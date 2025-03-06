
#include <stdio.h>
#include "util.h"
#include "ansi.h"

void extern escapes();

extern struct char_id id;
extern LS LnS[NUMLANGS+1];


void trans_latin(word)
Word* word;
{ 
int i;
 do {

  switch ( id.ctype[word->in[word->top]] ) {

        case punct   :  
             if(word->in[word->top] == '\\') escapes(word);
               else goto DEFAULT;
             break;

        default      :
DEFAULT:
             word->out[word->bot]   =  word->in[word->top];
             word->ls [word->bot++] =& LnS[lat];
             break;
  }

 } while(word->in[++word->top] != '\0' && word->f->new->s == latin);

}
