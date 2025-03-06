
#ifndef S2L_H
#define S2L_H

#define TEXFONTDIR "/u1/yacob/fonts/tex/"
#define FONTNAME   "wshr"
#define DFLTSIZE   10
#define NUMFONTS   5
#define FONTSIZES  {10,12,14,18,36}

#define   TEXNUM   300

#define DEFLANG tig
/* #define DEFLANG amh */
/* #define DEFLANG gez */

typedef struct {
          char *names[NUMFONTS];
          int sizes[NUMFONTS];
          int who;
          int last_set;
       } mytexfonts;

#endif

#include "ab.h"
