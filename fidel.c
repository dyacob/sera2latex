
/*-------------------------------------------------------------------------/
//                                                                         //
//  This is the current transilteration body for SERA to fidel.  The other //
//  routines "get_enum", "alternate", and "diqala" are also used for       //
//  transliteration and are called by the trans_fidel driver. The purpose  //
//  for the driver is to determine an address of a SERA string for the     //
//  font-map array "fidel.h".  The code is written now for clarity and not //
//  speed, the consequence should be minimal until VERY large documents    //
//  are transliterated.                                                    //
//                                                                         //
//  We don't want the transliterator to worry about lang, just script.     //
//                                                                         //
//-------------------------------------------------------------------------*/

#include <stdio.h>
#include "ansi.h"
#include "util.h"

void diqala(),alternate(),escapes(),get_enum();

unsigned short seramap[]=SERAMAP;
enum chartype ansi8[]=ANSI8;

struct char_id id={seramap,ansi8};

extern LS LnS[NUMLANGS+1];
extern char* Lnames2[NUMLANGS];
extern char* Lnames3[NUMLANGS];

void trans_fidel(word)
Word* word;
{ 
static int i,Enum,form=NIL;
unsigned addr=NIL;
boolean ok=true;

/*---- Exit If Operating in Wrong Zone -------------------------------------------------------------*/

   if(word->f->new->s != fidel) {printf("\nLeaving!\n"); return;}
  
do {

/* special case characters */

   switch ( id.ctype[word->in[word->top]] ) {


/*----- Handle Ethiopic And ASCII Punctuation -------------------------------------------------------*/


     case punct       :  
          switch(word->in[word->top]) {

    /*----- Handle SERA Special Chars -------------------------------------------------------------------*/

            case '`'  :  addr = i = id.fmap[word->in[++word->top] - ' '];
                         alternate(word,&addr,false); 
                          if(word->in[word->top] != '`') {       /* a change has occured */
                             word->out   [word->bot]   =  addr;
                             word->ls[word->bot++] =& LnS[word->f->new->l];
                          }
                          goto End_Punct;
                          break;

            case '\'' :  if(word->in[word->top+1] == '\'') {
                            word->out   [word->bot]   =  GEMINATE;
                            word->ls[word->bot++] =& LnS[word->f->new->l];
                          ++word->top;
                         } 
                         goto End_Punct;
                         break;  

    /*----- Handle Ethiopic Punctuation -----------------------------------------------------------------*/

            case '.'   :  word->out   [word->bot]   = PERIOD; 
                          word->ls[word->bot++] =& LnS[word->f->new->l];
                          break;
            case ','   :  word->out   [word->bot]   = COMMA; 
                          word->ls[word->bot++] =& LnS[word->f->new->l];
                          break;
            case ';'   :  word->out   [word->bot]   = SEMICOLON;
                          word->ls[word->bot++] =& LnS[word->f->new->l];
                          break;
            case ':'   :  word->out   [word->bot]   = (word->f->gpunct) ? 
                           ( (word->in[word->top+1]==':') ? PERIOD :  ( (word->in[word->top+1]=='|' && word->in[word->top+2] == ':') ? PARAGRAPH : ESPACE )) : COLON; 

                          if(word->f->gpunct) {
                             if(word->out[word->bot] == PERIOD) ++word->top;
                                else if(word->out[word->bot] == PARAGRAPH) word->top +=2;
                             if(word->out[word->bot] == ESPACE && word->out[word->bot-1] == ' ') {
                                word->out[word->bot--] = NIL; 
                                word->out[word->bot] = ESPACE; 
                              } 
                          }

                          word->ls[word->bot++] =& LnS[word->f->new->l];
                          break;

            case '-'   :  if(!word->f->gpunct) goto DEFAULT;
                          if(word->in [word->top+1] == ':') {
                             word->out[word->bot]   =  COLON;
                             word->ls [word->bot++] =& LnS[word->f->new->l];
                           ++word->top;
                          }
                          else goto DEFAULT;
                          break;

    /*----- Handle SERA Defined Escapes -----------------------------------------------------------------*/

            case '\\'  :  escapes(word);
                          goto End_Punct;
                          break;

    /*----- Handle For HTML -----------------------------------------------------------------------------*/

            case '&'   :  if(!word->f->html) goto DEFAULT;
                           while(word->in [word->top] != ';') {
                                   word->out[word->bot]  =  word->in[word->top++];
                                   word->ls [word->bot++]=& LnS[lat];
                           }
                           goto DEFAULT;
                           break;
                                
            case '<'   :  if(word->f->gpunct) 
                             if(word->in [word->top+1] == '<') {
                                word->out[word->bot]   = LEFTQUOTE;
                                word->ls [word->bot++] =& LnS[word->f->new->l];
                              ++word->top;
                                ok = false;
                                break;     /* do breaks in if's work? */
                            }
                            if(word->f->html && ok) 
                                while(word->in [word->top] != '>') {
                                      word->out[word->bot]  = word->in[word->top++];
                                      word->ls [word->bot++]=& LnS[lat];
                                }
                          ok = true;
                          goto DEFAULT;

            case '>'   :  if(word->f->gpunct) 
                             if(word->in [word->top+1] == '>') {
                                word->out[word->bot]   = RIGHTQUOTE;
                                word->ls [word->bot++] =& LnS[word->f->new->l];
                              ++word->top;
                                break;     /* do breaks in if's work? */
                            }

            case '?'   :  word->out   [word->bot]   = QUESTIONMARK;
                          word->ls[word->bot++] =& LnS[word->f->new->l];
                          break;

            default    :  goto DEFAULT;

        } /* end switch */
        if(word->f->gpunct && word->in[word->top+1] == ' ') ++word->top;
End_Punct:
        break;

/*----- Handle Ethiopic Consonants ------------------------------------------------------------------*/


     case cons  : addr = id.fmap[word->in[word->top] - ' '];

                  if (word->in[word->top] == 'W' || word->in[word->top+1] == 'W') diqala(word,&addr);
                      else
                  switch ( id.ctype[word->in[word->top+1]] ) {

                    case vowel :
                         switch(word->in[word->top+1]) {

                           case 'e'  :  form = 0; goto vowels;
                           case 'u'  :  form = 1; goto vowels;
                           case 'i'  :  form = 2; goto vowels;
                           case 'a'  :  form = 3; goto vowels;
                           case 'E'  :  form = 4; goto vowels;
                           case 'o'  :  form = 6; goto vowels;
                              vowels :
                                        addr +=  form - 5;
                                       ++word->top;
                         }
                         break;

                    case num   : if( word->in[word->top+1] != '2' ) break;
                                 alternate(word,&addr,true); 
                                 break;
                    default    :
                                 if (word->in[word->top+1] == '\'' && word->in[word->top+1] != '\'') ++word->top;
  
                  }  /* end cons switch */

                  word->out   [word->bot]   = addr;
                  word->ls[word->bot++] =& LnS[word->f->new->l];
                  addr = NIL;
                  break;


/*----- Handle Ethiopic Vowels ----------------------------------------------------------------------*/


     case vowel : addr = id.fmap[word->in[word->top] - ' '];
                  if ( word->in[word->top+1] == '2' )  {
                       addr = addr - (addr-128)/8 + 108 ;
                     ++word->top;
                  }
                  if ( word->in[word->top] ==  'e' && word->in[word->top+1] == '3') {
                       addr = 151;  
                     ++word->top;
                  }
                  if ( word->in[word->top]   == 'a' && word->f->new->l == amh) addr -= 3;     /* correct for A -> a in Amharic */
                  if ( word->in[word->top+1] == '\'' ) ++word->top;
                  word->out[word->bot]   = addr;
                  word->ls [word->bot++] =& LnS[word->f->new->l];
                  addr = NIL;
                  break;


/*----- Handle Euro-Cons, Euro-Vowel, Numbers, Other, the same for now ------------------------------*/


DEFAULT :
                          if(word->f->gpunct && word->in[word->top+1] == ' ') 
                             word->in[word->top+1] = word->in[word->top++];
                           

     case euro_cons  : /* this shouldn't happen, for now just print and get out  */
     case euro_vowel : /* later send to a scriptuage specific routine if available */
     case esc        :
     case num        :

     default         : /*  keep what you got  */

                           word->out   [word->bot]   = word->in[word->top];
                           word->ls[word->bot++] =& LnS[lat];
                           break;

      }   /*  end chartype switch */

  } while(word->in[++word->top] != NULL && word->f->new->s == fidel);

}   /*  end trans_fidel   */





/*-------------------------------------------------------------------------//
//                                                                         //
//  Hanndle all diqalawoc representations                                  //
//                                                                         //
//-------------------------------------------------------------------------*/

void diqala(word,addr)
Word* word;
unsigned* addr;
{
 int dform=NIL;
 unsigned base;

   base = *addr;
  *addr +=  2;
   if(word->in[word->top++] != 'W') word->top++;

  switch(word->in[word->top]) {

    case 'e'  : dform=0; goto diqalawoc;
    case 'u'  : dform=1; goto diqalawoc;
    case '\'' : dform=1; goto diqalawoc;
    case 'i'  : dform=2; goto diqalawoc;
    case 'E'  : dform=4; 
      diqalawoc :

               *addr += dform;                  /* mod 12 zone */
                if(base == 262)                  /* h2Wx = hWx */
                  *addr = 159 + dform; 
                else if(base < 144 || base > 236) {   /* not mod 12 zone */
                        word->out[word->bot]   = base;
                        word->ls [word->bot++] =& LnS[word->f->new->l];
                       *addr = 231 + dform;                 /* 231 = We */
                     }
                break;

    case 'a'  : dform=3; 
                if(base > 151 && base < 236)     /* mod 12 zone */
 			   *addr += dform;
 			else if(base == 262)             /* h2Wa = hWa */
  			       *addr =  162; 
 			else if(base > 235) {            /* mode 7 and above */
 			   word->out   [word->bot]   = base;
               word->ls[word->bot++] =& LnS[word->f->new->l];
 			   *addr = 231 + dform;           /* We + vowel */
 			}
                        break;

    default   : /* character other than vowel follows "W" */

                if(base < 144 || base > 235) {       /* not mod 12 zone */
                   if(base > 235 && base != 262) {   /* mode 7 and anything above but `h ! */
                      word->out[word->bot]   = base;
                      word->ls [word->bot++] =& LnS[word->f->new->l];
                     *addr = 234; 
                   }
                   if(base == 262)                   /* h2W = hW */
                     *addr  = 160;
                } 
                if(base > 151 && base < 236)         /* mod 12 zone */
                  *addr += 1;
              --word->top; 
  } /* end switch */
   
}




/*-------------------------------------------------------------------------//
//                                                                         //
//  Hanndle the hohEt that start with `                                    //
//                                                                         //
//-------------------------------------------------------------------------*/

void alternate(word,addr,from_2)
Word* word;
unsigned* addr;
boolean from_2;
{
 int form;

  switch (id.ctype[word->in[word->top]]) {
    case vowel :
           switch (word->in[word->top]) {
             case 'e'  :  form = 0; goto vowels;
             case 'U'  :
             case 'u'  :  form = 1; goto vowels;
             case 'i'  :  form = 2; goto vowels;
             case 'a'  : 
             case 'A'  :  form = 3; goto vowels;
             case 'E'  :  form = 4; goto vowels;
             case 'I'  :  form = 5; goto vowels;
             case 'o'  : 
             case 'O'  :  form = 6;
                vowels :
                          *addr =  255 + form - 5;
          }
          if(from_2) word->top++ ;
          break;

    case cons :
           switch (word->in[word->top]) {
             case 'k' : *addr -= 4;     /* correct for k -> k2  */
             case 'h' :
             case 's' :
             case 'S' :
                        *addr = *addr - (*addr-128)/8 + 108 ;
                        if(from_2) word->top++ ;
                        switch (word->in[word->top+1]) {
                          case 'e'  :  form = 0; goto Vowels;
                          case 'u'  :  form = 1; goto Vowels;
                          case 'i'  :  form = 2; goto Vowels;
                          case 'a'  :  form = 3; goto Vowels;
                          case 'E'  :  form = 4; goto Vowels;
                          case 'o'  :  form = 6; 
                             Vowels :
                                      *addr +=  form - 5;
                                       word->top++ ;
                                       break;
                          case 'W'  :  diqala(word,addr);
                                       break;
                        }
           }
           break;

    default  :
               if(word->in[word->top] == '\'') 
                  *addr = SOFTSADIS;     
               else 
                   --word->top;   /* ignore ` */
  }
}




/*-------------------------------------------------------------------------//
//                                                                         //
//  Determine SERA Defined Escapes                                         //
//                                                                         //
//-------------------------------------------------------------------------*/


void escapes ( word )
Word* word;
{
int i,l,Enum;
/*char escid[]="\0\0\0\0\0\0\0\0\0\0\0\0";
*/
char escid[12];
for(i=0;i<12;i++) escid[i]='\0';

/*----- Handle SERA Defined Escapes -----------------------------------------------------------------*/

    ++word->top;   /*  Advance from \ to x of \x  */

    /*----- Handle Hard Mode First -----------------------------------------------------------*/

      if(word->f->hard_mode)                    {
         if(word->in[word->top] == '~') goto NEWLANG;    
         if(word->in[word->top] == '!')     { 
            word->f->hard_mode   = false;
            word->f->new         = word->f->next;
            word->f->next        = word->f->major;
            word->f->major       = word->f->new;
            goto End_Escapes;        /* "break" doesn't work here */
         }
         else {
                word->out[word->bot] = '\\';
                word->ls [word->bot++] =& LnS[lat];
              --word->top;
                return;
         } 
      }

    /*----- Handle Ethiopic Numbers ----------------------------------------------------------*/

      if( id.ctype[word->in[word->top]] == num )               {
           do {
                Enum = 336 + word->in[word->top] - 49;
                i = 0;
                while (word->in[++word->top] == '0') i++;
                       get_enum(word,Enum,i); 
           }  while(id.ctype[word->in[word->top]] == num );
            --word->top;
              return;
      } 

    /*----- Handle Language Dependent Switches -----------------------------------------------*/

      switch( word->in[word->top] ) {  /* Just kick out the latin */

        case '\''  : 
        case '`'   :  if(word->f->new->s == fidel)      goto HERE; 
                         else                           goto THERE;
        case '.'   :  word->out[word->bot] = PERIOD;    goto HERE;
        case ','   :  word->out[word->bot] = COMMA;     goto HERE;
        case ';'   :  word->out[word->bot] = SEMICOLON; goto HERE;
        case ':'   :  if(word->f->new->s == fidel && word->in[word->top+1] == ':') {
                         word->f->gpunct =! word->f->gpunct;
                       ++word->top;
                         goto End_Escapes;
                         break;
                      }

                      word->out[word->bot] = COLON; 
HERE:

                      if(word->f->new->s == fidel) {
                         word->out[word->bot] = word->in[word->top];
                         word->ls [word->bot++] =& LnS[lat];
                      }
                      else 
                         word->ls[word->bot++] =& LnS[gez];
                      break;

    /*----- Handle Language Independent Switches ---------------------------------------------*/

        case '\\'  :   word->out[word->bot]   =  word->in[word->top];
                       word->ls [word->bot++] =& LnS[lat];
                       break;

    /*----- Handle Ethiopic Switches ---------------------------------------------------------*/

        case '_'   :   word->out[word->bot]   = ESPACE; 
                       word->ls [word->bot++] =& LnS[gez];
                       break;
        case '<'   :   word->out[word->bot]   = LEFTQUOTE;
                       word->ls [word->bot++] =& LnS[gez];
                       break;
        case '>'   :   word->out[word->bot]   = RIGHTQUOTE;
                       word->ls [word->bot++] =& LnS[gez];
                       break;
        case '*'   :   word->out[word->bot]   = PARAGRAPH;
                       word->ls [word->bot++] =& LnS[gez];
                       break;
        case '?'   :   word->out[word->bot]   = EQUESTIONMARK;
                       word->ls [word->bot++] =& LnS[gez];
                       break;
        case '!'   :   word->f->hard_mode =! word->f->hard_mode;
                       word->f->new       =  word->f->next;
                       word->f->next      =  word->f->major;
                       word->f->major     =  word->f->new;
                       goto End_Escapes;
                       break;

    /*----- Handle Graphic Switches ----------------------------------------------------------*/

        case '~'   :   /* Copy the graphic escape to output and let the display routine handle */
NEWLANG:
                       i = l = 0;
                       while ( word->in[word->top] != ' ' && word->in[word->top] != '\n' && word->in[word->top]
!= '\0')
                               escid[i++] = word->in[word->top++];

/*                     if (word->in[word->top] == '\n' || word->in[word->top] == '\0') --word->top;
*/                     if (word->in[word->top] != ' ') --word->top;

                       if(escid[i-1] == '!') { 
                          word->f->hard_mode =! word->f->hard_mode;
                          escid[i-1] = '\0'; 
                       }
/* note the next line fails if you want to change scripts but not languages 
** ...then again the premise is one script per language so the hold thing 
** would crash...
*/
                       if(!strcmp(&escid[1],Lnames2[word->f->new->l])
                       || !strcmp(&escid[1],Lnames3[word->f->new->l])) break;

                       if(!strcmp(&escid[1],"html") || !strcmp(&escid[1],"HTML")) {
                         word->f->html =! word->f->html;
                         goto End_Escapes;
                         break;
                       } 
                  if(i>2) 
                       do {
                            if(!strcmp(&escid[1],Lnames2[l]) || !strcmp(&escid[1],Lnames3[l])) {
  
                               if(word->f->new->l == word->f->major->l){  /* switch next and current so \ goes back to */
                                  word->f->new     = word->f->next;       /* the language we're leaving */
                                  word->f->next    = word->f->major;
                                  word->f->major   = word->f->new;        /* f->new is just a temp variable here... */
                               }
                               word->f->new        =& LnS[l]; 
                               goto End_Escapes;
                               break;
                            }
                       }while(l++ < NUMLANGS);
                       if(word->f->hard_mode) {                           /* in hard_mode but no lang change */
                          word->out[word->bot] = '\\';
                          word->ls [word->bot++] =& LnS[lat];
                          word->top -= i+1;
                          return;
                       } 
                       if(l == NUMLANGS || i == 2) {     /* this means no language match */
                          for(l=0;l<i;l++) {
                                  word->out[word->bot]   =  escid[l];
                                  word->ls [word->bot++] =& LnS[gfx];
                          }
                       }
                       goto End_Escapes;
                       break;

    /*----- Handle Primary\Secondary Language Toggles ----------------------------------------*/
THERE:
        default    :   
                       word->f->new   = word->f->next;
                       word->f->next  = word->f->major;
                       word->f->major = word->f->new;   
                     --word->top;
End_Escapes:
                       if(word->in[word->top+1] == ' ') ++word->top;
                       return;
      }                /*        end \ switches         */

      if(word->f->gpunct && word->f->new->s == fidel)
         if(word->in[word->top+1] == ' ') ++word->top;

}




/*-------------------------------------------------------------------------//
//                                                                         //
//  Quaint Little Routine For Ethiopic Numbers                             //
//                                                                         //
//-------------------------------------------------------------------------*/

void get_enum(word,Enum,num0s)
Word* word;
int Enum,num0s;
{
int i,odd,num,ande=ONE,asr=9,mato=HUNDRED,asrxi=TENTHOUSAND;


  asr +=  Enum;
  odd  =  num0s%2;
  
  if(Enum == ande)
     if(!num0s) {
         word->out[word->bot]   =  ande;
         word->ls [word->bot++] =& LnS[gez];
         return;
     }
       else if(odd) { word->out[word->bot]   =  asr ;
                      word->ls [word->bot++] =& LnS[gez];
       }
  
  if(Enum != ande) {
     if(!odd) word->out[word->bot]   = Enum ;
       else   word->out[word->bot]   = asr  ;
              word->ls [word->bot++] =& LnS[gez];
  }

  num = num0s%4;
  if(num > 1) {
     word->out[word->bot]   =  mato ;
     word->ls [word->bot++] =& LnS[gez];
  }

  num = num0s/4;
  for(i = 0; i < num; i++) {
      word->out[word->bot]   =  asrxi ;
      word->ls [word->bot++] =& LnS[gez];
  }

}

