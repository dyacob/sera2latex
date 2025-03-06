/*
**  sera2xxx v0.2
**
**  Generalized code to convert SERA (The System for Ethiopic Representation
**  in ASCII) to an arbitrary second system.  The generalized transliteration
**  is achieved here by requiring a mapping of the output system into the
**  "fidel" addresss table (see fidel.h).
**  sera2jun v0.2  SERA To Junet address conversion is the function of this
**  body of code.  The only "Junet" specific element of the filter is the
**  "junet" array found in "main" and the junet.h file.  The junet address
**  array may be substituted for any second system so long as the "fidel"
**  mapping table is updated accordingly.
** 
**  This is free software; you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation; either version 1, or (at your option)
**  any later version.  See the included "COPYING" file.
** 
**  --Daniel Yaqob, 1995
** 
*/


#include <stdio.h>
#include "fidel.h"
#include "s2l.h"
#include "util.h"
#include "ansi.h"

Flag myflags;
mytexfonts replace={{"washr","Washr","WASHR","bigwashr","BIGwashr"},FONTSIZES, NIL, NIL };

extern struct char_id  id;
LS LnS[NUMLANGS+1] = LSDEFS;
char* Lnames2[NUMLANGS] = LNAMES2;
char* Lnames3[NUMLANGS] = LNAMES3;

LS* default_lang =& LnS[DEFLANG];

int stats[362];

void disp_ltext(),disp_ptext(),trans_fidel(),trans_latin(),escapes(),flag_reset();
void do_graphics(), print_stats(); 

/*-------------------------------------------------------------------------//
//                                                                         //
//  Main reads input switches, does file read-in, and sends one char at    //
//  at a time to the transliteration subroutins.                           //
//                                                                         //
//-------------------------------------------------------------------------*/

void main(argc,argv)
int argc;
char **argv;
{
Word myword;
enum Languages zone[WSIZE];
int i;
char ch,dumbword[WSIZE]; 
char mystring[WSIZE];
FILE *inptr;

  myword.f            =& myflags;
  myword.f->new       =  default_lang;
  myword.f->major     =  myword.f->new;
  myword.f->next      =& LnS[lat];
  myword.f->ethspace  =  false;
  myword.f->hard_mode =  false;
  myword.f->gpunct    =  false;
  myword.f->size      =  DFLTSIZE;
  myword.f->pre       =  false;
  myword.f->pho       =  false;
  myword.f->tex       =  false;
  myword.f->filt      =  false;
  myword.in           =  mystring;

  for(i=0;i<362;i++) stats[i] = 0;

  inptr = stdin;

  flag_reset(argc, argv, inptr);

  myword.f->new = myword.f->major;

  if(myflags.filt) filter(&myword,inptr);

  if(!myword.f->tex) {
    fprintf(stdout,"\\documentstyle{report} \n\\begin{document}\n\n");
    fprintf(stdout,"\\newfont{\\washra}{%s%s%d.%dpk}\n",TEXFONTDIR,FONTNAME,myflags.size,TEXNUM);
    fprintf(stdout,"\\newfont{\\washrx}{%s%sx%d.%dpk}\n",TEXFONTDIR,FONTNAME,myflags.size,TEXNUM);
    if(!myflags.filt && !myflags.pho)
      fprintf(stdout,"\\include{fidelmap}\n");
    if(myflags.pre)
      fprintf(stdout,"\\noindent\n");
  }
  else {
    fprintf(stdout,"\\font\\washra=%s%s%d.%dpk\n",TEXFONTDIR,FONTNAME,myflags.size,TEXNUM);
    fprintf(stdout,"\\font\\washrx=%s%sx%d.%dpk\n",TEXFONTDIR,FONTNAME,myflags.size,TEXNUM);
    fprintf(stdout,"\\def\\noi{\\noindent}\n");
    fprintf(stdout,"\\def\\nl{\\noi\\par}\n");
    if(!myflags.filt && !myflags.pho)
      fprintf(stdout,"\\input fidelmap.tex\n");
    if(myflags.pre)
      fprintf(stdout,"\\noi\n");
  }


  fgets(myword.in,WSIZE,inptr);
  while(!feof(inptr))            {
     for(i=0;i<WSIZE;i++) zone[i] = myword.out[i] = NIL;
     i = myword.top = myword.bot = 0;

     while(myword.in[myword.top] != '\0')      {
         zone[myword.bot]  = myword.f->new->s;
         switch(myword.f->new->s) {

           case fidel  :  trans_fidel (&myword);  
                          break;

           case latin  :  trans_latin (&myword);
                          break;

           case greek  :  trans_greek (&myword);
         }
     }

     if(myflags.pho)
       disp_ptext(&myword,zone);  /* go phonetic */
     else
       disp_ltext(&myword,zone);  /* go abass    */

     fgets(myword.in,WSIZE,inptr);
  }
  if(!myword.f->tex)
    fprintf(stdout,"\n\\end{document}\n");
  else
    fprintf(stdout,"\n\\bye\n");

  if(myword.f->stats) print_stats();
  exit(0);
}



/*-------------------------------------------------------------------------//
//                                                                         //
//  The "send to output" routine is here.  It screen draws the char or     //
//  prints or whatever. The SPACE logic will substitute ESPACE for SPACE   //
//  for only the first of multiple spaces:  "   " = ":  "  and omit ":"    //
//  at the start of a paragraph -as per user requests.                     //
//                                                                         //
//-------------------------------------------------------------------------*/

void disp_ltext ( word, zone )
Word *word ;
enum Languages *zone;
{
 int i,set=NIL;
 boolean lastspace=false, lastreturn=false;
 enum Languages Zone;
 static unsigned char lastch = '\n';
 static enum Languages last_zone = NIL;

  if(lastch == 9 || lastch == 10) lastreturn = true;
  
  for(i=0;i<word->bot;i++) {

      if(zone[i] != NIL)   { 
         Zone = zone[i]; 
         if(last_zone == fidel && Zone != fidel) {
            if(replace.last_set != NIL && word->f->filt)                  /* make sure actual fidel was printed */
               printf("}");
            replace.last_set = NIL;
         }
      }
        
      switch(word->ls[i]->s) {

        case latin:

          if(word->f->pre && lastreturn  && !word->f->filt &&
            ( word->out[i] == '\n' || (word->out[i+1] == ' ' && word->out[i+2] == '\n'))) {
            if(!word->f->tex)
               fprintf(stdout,"\n");
            else
              fprintf(stdout,"\n\\smallskip\n");
            if(word->out[i+1] == ' ') i++ ;
            i++;
            lastspace = false;
            lastreturn = true;
            break;
           }


          if(word->out[i] == ' ') {
             if(word->f->ethspace && Zone < latin && !lastspace && !lastreturn ) 
                 if((word->out[i-1] < SPACE  || word->out[i-1] >= ONE) 
                 || (word->ls[i-1]->s == latin && id.ctype[word->out[i-1]] != punct)) {
                     fprintf(stdout,"\\%s",TeXFidel[ESPACE]);
                     if(word->f->stats) ++stats[ESPACE];
                     lastspace = true;
                     lastreturn = false;
                     break;
                 }
             lastspace = true;
          }
          else
             lastspace = false;

          lastreturn = false;
          switch(word->out[i]) {
            case  9  :
            case 10  : 
                       if(word->f->pre && !word->f->filt) {
                          if(!word->f->tex)
                             fprintf(stdout,"\\\\\n");
                          else
                             fprintf(stdout,"\\nl\n\n");
                       }
                       else 
                          fprintf(stdout,"\n");
                       lastreturn = true;
                       break;
            case ' ' : if(word->f->pre && !word->f->filt) fprintf(stdout," \\ ");
                       else 
                          fprintf(stdout," ");
                       if(word->f->stats && Zone < latin) ++stats[SPACE];
                       break;
            case '\\' :
            case '^' :
            case '#' :
            case '%' :
            case '_' :
            case '~' :
            case '&' :
            case '$' :  
            case '}' :
            case '{' : fprintf(stdout,"\\");

            default  :
                       fprintf(stdout,"%c",word->out[i]); 
          } 
          break;
     
        case greek:

          fprintf(stdout,"%s",Greek[word->out[i]]); 
          lastspace = lastreturn = false;
          break;

        case fidel:
FIDEL:
          if(word->out[i] == NIL) break;
          if(word->out[i]==EQUESTIONMARK) word->out[i] = QUESTIONMARK;
          if(word->f->filt) set  = ABFidel[word->out[i]].set;
          if(replace.last_set != set && word->f->filt) {
            if(last_zone == fidel && replace.last_set != NIL) printf("}");
            if(set)
              fprintf(stdout,"{\\%sx ",replace.names[replace.who]);
            else
              fprintf(stdout,"{\\%sa ",replace.names[replace.who]);
          }
          if(word->out[i+1] == GEMINATE)     {
               fprintf(stdout,"\\\"{\\%s}",TeXFidel[word->out[i]]);
             ++i;
          }
          else 
               fprintf(stdout,"\\%s",TeXFidel[word->out[i]]);
          lastspace = lastreturn = false;
          if(word->out[i] == ESPACE) lastspace = true;
          if(word->f->stats) ++stats[word->out[i]];
          replace.last_set = set;
          break;


       case graphic:
          i++;
          do_graphics(word,i);
          lastspace = lastreturn = false;
          break;

     }
     last_zone = Zone;
   }
     lastch  = word->out[i-1];
     zone[i] = last_zone;
}


void do_graphics(word,i) 
Word* word;
int i;
{
unsigned addr;

   return;  /*  Disable Graphics for LaTeX Output 

    switch(word->out[i]) {

      case 'e' : addr = FIDELLAND;    break;

      case 'E' : addr = INVFIDELLAND; break;

      case 'a' : addr = AFRICA;       break; 

      case 'A' : addr = INVAFRICA;    break;

      default  : return;

    }
    fprintf(stdout,"%s",amharic[addr]);  
    return;
*/
}

/*
**  This is the original phonetic transcription body.
**  It is kept as a seperate routine for clarity's 
**  sake.
**
*/

void disp_ptext ( word )
Word *word ;
{
 int addr=NIL,i;
 static boolean lastreturn=false;

  for(i=0;i<word->bot;i++) {

      switch(word->ls[i]->s) {

        case latin:

          if(word->f->pre && lastreturn  &&
            ( word->out[i] == '\n' || (word->out[i+1] == ' ' && word->out[i+2] == '\n'))) {
            if(!word->f->tex)
               fprintf(stdout,"\\\\\n");
            else
              fprintf(stdout,"\n\\smallskip\n");
            if(word->out[i+1] == ' ') i++ ;
            i++;
            lastreturn = true;
            break;
           }

          lastreturn = false;
          switch(word->out[i]) {
            case  9  :
            case 10  :
                       if(word->f->pre) {
                          if(!word->f->tex)
                             fprintf(stdout,"\\\\\n");
                          else
                             fprintf(stdout,"\\nl\n\n");
                       }
                       else
                          fprintf(stdout,"\n");
                       lastreturn = true;
                       break;
            case ' ' : if(word->f->pre) fprintf(stdout," \\ ");
                       else
                          fprintf(stdout," ");
                       break;
            case '\\' :
            case '^' :
            case '#' :
            case '%' :
            case '_' :
            case '~' :
            case '&' :
            case '$' :
            case '}' :
            case '{' : fprintf(stdout,"\\");

            default  :
                       fprintf(stdout,"%c",word->out[i]);
          }
          break;

     
        case greek:

          fprintf(stdout,"%s",Greek[word->out[i]]); 
          break;

        case fidel:
          if(word->out[i] == NIL) break;
          if(word->out[i]==EQUESTIONMARK) word->out[i] = QUESTIONMARK;
          addr = Fidel[word->out[i]];
          if(word->out[i+1] == GEMINATE)     {
             fprintf(stdout,"%s%s%s",fscript[word->ls[i]->l][addr].c,fscript[word->ls[i]->l][addr].c,fscript[word->ls[i]->l][addr].v);
             ++i;
          }
          else if(word->out[i] == SOFTSADIS) {            /* voiced component of cons */
             fprintf(stdout,"(%s)",ge_ez[150].v);  
          }
          else
             fprintf(stdout,"%s%s",fscript[word->ls[i]->l][addr].c,fscript[word->ls[i]->l][addr].v);
          if(word->f->stats) ++stats[word->out[i]];
          break;

       case graphic:
          i++;
          do_graphics(word,i);
          break;

     }
   }
}

/*---------------Finds and Replaces \sera \Sera \SERA \bigsera \BIGsera-------------------------*/

void filter(word,inptr)
Word* word;
FILE* inptr;
{
char *find[NUMFONTS] = {"sera","Sera","SERA","bigs","BIGs"};
char temp[WSIZE],ch;
enum Languages zone[WSIZE];
int i,j,k,I;

/*----------Print Header Info---------------------------------------------------------------------*/

  if(!word->f->tex) {
    for(i=0;i<NUMFONTS;i++) {
       fprintf(stdout,"\\newfont{\\%sa}{%swshr%d.%dpk}\n",replace.names[i],TEXFONTDIR,replace.sizes[i],TEXNUM);
       fprintf(stdout,"\\newfont{\\%sx}{%swshrx%d.%dpk}\n",replace.names[i],TEXFONTDIR,replace.sizes[i],TEXNUM);
    }
    fprintf(stdout,"\\include{fidelmap2}\n");
  }
  else {
    for(i=0;i<NUMFONTS;i++) {
       fprintf(stdout,"\\font\\%sa=%swshr%d.%dpk\n",replace.names[i],TEXFONTDIR,replace.sizes[i],TEXNUM);
       fprintf(stdout,"\\font\\%sx=%swshrx%d.%dpk\n",replace.names[i],TEXFONTDIR,replace.sizes[i],TEXNUM);
    }
    fprintf(stdout,"\\def\\noi{\\noindent}\n");
    fprintf(stdout,"\\def\\nl{\\noi\\par}\n");
    fprintf(stdout,"\\input fidelmap2.tex\n");
  }

while(fscanf(inptr,"%c",&ch) != EOF) {

  if(ch != '\\') fprintf(stdout,"%c",ch);
    else {
         fgets(temp,5,inptr); 
         I=-1;
         while(++I<5 && strcmp(temp,find[I]));
         if(I==5) {
            fprintf(stdout,"%c%s",ch,temp);
            continue;  /* where do you go break? */
         }
         replace.who = I;
         fscanf(inptr,"%c",&ch);                /* get { */          
         if(I>2) fgets(temp,4,inptr);          /* get left over ``ra{'' */

         word->f->new   =  default_lang;
         word->f->major =  word->f->new;
         word->f->next  =& LnS[lat];

RECYCLE:
         for(i=0;i<WSIZE;i++) {
             zone[i] = word->out[i] = NIL;
             temp[i] = word->in [i] = '\0';
         }
         i = word->top = word->bot = 0;
         fgets(temp,WSIZE,inptr); 
         for(j=0;j<strlen(temp);j++)
            if(temp[j] == '}' && temp[j-1] != '\\') break;
         strncpy(word->in,temp,j);


     while(word->in[word->top] != '\0')      {
         zone[word->bot] = word->f->new->s;
         switch(word->f->new->s) {

           case fidel  :  trans_fidel (word);
                          break;

           case latin  :  trans_latin (word);
                          break;

           case greek  :  trans_greek (word);
         }
     } 

     disp_ltext(word,zone);  /* go abass    */
     if(temp[j] == '}') {
       if(zone[word->bot] == fidel)  printf("}");
       replace.last_set = NIL;
       for(k=j+1;k<strlen(temp);k++)
          fprintf(stdout,"%c",temp[k]);
       continue;
     }

     if(!feof(inptr)) goto RECYCLE; 

   } /* end else ch != '\\' */

} /* end while */

if(word->f->stats) print_stats();
exit(0);
}



/*-------------------------------------------------------------------------//
//                                                                         //
//  Print Table of Character Occurances                                    //
//                                                                         //
//-------------------------------------------------------------------------*/


void print_stats()
{
int addr,Addr,i,mod,space=0;
FILE* fp;

 fp = fopen("s2l.stats","w");
 for(addr = 0; addr < 358; addr++) {

  Addr = TraditionalOrder[addr];

  if(Addr <= 151) mod = 8;
    else if(Addr <= 235) mod = 12;
         else if(addr < 300) mod = 7;

  if(Addr == 152) mod = 7;   /* `he / he correction */
  if(Addr == 257) mod = 12;

  if(Addr == SPACE) mod = 11; 
  if(Addr == ONE) mod = 10; 
  if(Addr == SPACE || Addr == ONE || Addr == 264 )
    fprintf(fp,"-------------------------------------------------------------------------------------\n\n");

  if(Addr == SPACE) space = 1;

    for(i=0; i<mod; i++) fprintf(fp, "%*s    ", 3+space, FidelName[TraditionalOrder[addr+i]]);
    fprintf(fp,"\n");
    for(i=0; i<mod; i++) fprintf(fp, "%*d    ", 3+space, stats[TraditionalOrder[addr++]]);
    fprintf(fp,"\n\n");
    addr--;
 }

 fclose(fp);
 exit(0);
}




/*-------------------------------------------------------------------------//
//                                                                         //
//  Simple routine to read input options and reset the default flags.      //
//  The flags for this version are -l if a file starts in Latin and        //
//  -s to use Ethiopic word separators in Ethiopic text zones.             //
//                                                                         //
//-------------------------------------------------------------------------*/


void flag_reset(argc, argv, fp)
int argc;
char **argv;
FILE *fp;
{
int i=0,j;

if(argc == 1) goto DEFAULT;
  
  while (++i < argc) {
    if (argv[i][0] == '-') {

       switch(toupper(argv[i][1])) {

         case 'F' :  myflags.filt = true;
                     break; 
         case 'L' :  j=-1;
                     while( ++j < NUMLANGS && (strcmp(argv[i+1],Lnames2[j]) && strcmp(argv[i+1],Lnames3[j])) );
                     if(j < NUMLANGS ) {
                         if(argv[i][2] == '1') myflags.major  =& LnS[j];  
                           else  
                              if(argv[i][2] == '2') myflags.next  =& LnS[j];  
                                 else { 
                                    fprintf(stderr,"Option %s is unknown.  Exiting\n",argv[i]);
                                    exit(0);
                                 }
                            
                     }
                     i++;
                     if(j == NUMLANGS) {
                        fprintf(stderr,"Language %s Not Supported\n",argv[i]);
                        exit(1);
                     }
                     break; 
         case 'N' :  myflags.size = atoi(argv[++i]);
                     break; 
         case 'S' :  if(argv[i][2] == 't')
                        myflags.stats = true;     /* give character occurance statistics */
                     else
                        myflags.ethspace = true;  /* use Eth Word Sep. for " " */
                     break;

         case 'G' :  myflags.gpunct   = true;  /* use Glyph Punctuaion Rules */
                     break;
         case 'P' :  switch(toupper(argv[i][2])) {
                       case 'H':
                        myflags.pho  = true;  /* preserve text format      */
                        break;
                       case 'R':
                        myflags.pre  = true;  /* preserve text format      */
                        break;
                       default :
                        fprintf(stderr,"Flag %s unknown, ignoring...\n",argv[i]);
                        break;
                     }
                     break;
         case 'T' :  myflags.tex = true;  /* use Eth Word Sep. for " " */
                     break;
DEFAULT:
         default  :
                     fprintf(stderr,"\n\tUseage:  sera2latex -option[s] file > file.tex\n");
                     fprintf(stderr,"\tTo output in TeX format:\n");
                     fprintf(stderr,"\t   -tex \n");
                     fprintf(stderr,"\tTo transcribe into phonetics:\n");
                     fprintf(stderr,"\t   -pho \n");
                     fprintf(stderr,"\tTo preserve a text documents format:\n");
                     fprintf(stderr,"\t   -pre \n");
                     fprintf(stderr,"\tTo filter a .tex document:\n");
                     fprintf(stderr,"\t   -filt \n");
                     fprintf(stderr,"\tTo change the default font size from 10 to 12, 14, 18, or 36:\n");
                     fprintf(stderr,"\t   -n 18 \n");
                     fprintf(stderr,"\tTo use Ge'ez punctuation glyph maps:\n");
                     fprintf(stderr,"\t   -g \n");
                     fprintf(stderr,"\tTo substitute Latin spaces with Ge'ez wordspace:\n");
                     fprintf(stderr,"\t   -s \n");
                     fprintf(stderr,"\tTo set starting language:\n");
                     fprintf(stderr,"\t   -l iso639-name \n");
                     fprintf(stderr,"\t      am = amh = Amharic \n");
                     fprintf(stderr,"\t      gz = gez = Ge'ez   \n");
                     fprintf(stderr,"\t      la = lat = Latin   \n");
                     fprintf(stderr,"\t      ti = tig = Tigrigna\n");
                     fprintf(stderr,"\n\tTo contact the maintainers:\n");
                     fprintf(stderr,"\t   fisseha@cig.mot.com / dmulholl@cs.indiana.edu\n\n");
                     exit(0); 
                     break;
             
       }
    }  
    else {
          fclose(fp);
          if ((fp = fopen(argv[i],"r")) == NULL){
              fprintf(stderr,"\n*** File Not Found \"%s\" ***\n",argv[i]);
              exit(1);
          }
    }
  }

  if(myflags.pho)                              /* just in case.... */
     myflags.filt = myflags.ethspace = false;
  
    /* else ignore, and use defaults */
}
