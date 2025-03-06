/*  
   To use the sera2xxx code for other fidel font tables, you need to define
   a maping of font addresses, following the table below, into the 2nd 
   "fidel[]" array.  Address for unavailble characters should be given by -1 .

*/

char *TeXFidel[362]=
              {"le","lu","li","la","lE","l","lo","lWa",
               "me","mu","mi","ma","mE","m","mo","mWa",
               "re","ru","ri","ra","rE","r","ro","rWa",
               "xe","xu","xi","xa","xE","x","xo","xWa",
               "be","bu","bi","ba","bE","b","bo","bWa",
               "ve","vu","vi","va","vE","v","vo","vWa",
               "te","tu","ti","ta","tE","t","to","tWa",
               "ce","cu","ci","ca","cE","c","co","cWa",
               "ne","nu","ni","na","nE","n","no","nWa",
               "Ne","Nu","Ni","Na","NE","N","No","NWa",
               "ze","zu","zi","za","zE","z","zo","zWa",
               "Ze","Zu","Zi","Za","ZE","Z","Zo","ZWa",
               "de","du","di","da","dE","d","do","dWa",
               "Te","Tu","Ti","Ta","TE","T","To","TWa",
               "Ce","Cu","Ci","Ca","CE","C","Co","CWa",
               "fe","fu","Fi","fa","fE","f","fo","fWa",
               "se","su","si","sa","sE","s","so","sWa",
               "Se","Su","Si","Sa","SE","S","So","SWa",
               "ea", "u", "i", "a", "E","I", "o","e3",
               "he","hu","hi","ha","hE","h","ho","hWe","hWu","hWi","hWa","hWE",
               "ke","ku","ki","ka","kE","k","ko","kWe","kWu","kWi","kWa","kWE",
               "Ke","Ku","Ki","Ka","KE","K","Ko","KWe","KWu","KWi","KWa","KWE",
               "qe","qu","qi","qa","qE","q","qo","qWe","qWu","qWi","qWa","qWE",
               "Qe","Qu","Qi","Qa","QE","Q","Qo","QWe","QWu","QWi","QWa","QWE",
               "ge","gu","gi","ga","gE","g","go","gWe","gWu","gWi","gWa","gWE",
               "we","wu","wi","wa","wE","w","wo","wWe","wWu","wWi","wWa","wWE",
               "sse","ssu","ssi","ssa","ssE","ss","sso",
               "SSe","SSu","SSi","SSa","SSE","SS","SSo",
               "ee",  "uu", "ii", "aa", "EE","II", "oo",
               "hhe","hhu","hhi","hha","hhE","hh","hho",
               "kke","kku","kki","kka","kkE","kk","kko",
               "Xe","Xu","Xi","Xa","XE","X","Xo",
               "He","Hu","Hi","Ha","HE","H","Ho",
               "ye","yu","yi","ya","yE","y","yo",
               "De","Du","Di","Da","DE","D","Do",
               "je","ju","ji","ja","jE","j","jo",
               "Ge","Gu","Gi","Ga","GE","G","Go",
               "Pe","Pu","Pi","Pa","PE","P","Po",
               "pe","pu","pi","pa","pE","p","po",

               "space","Gspace","Gperiod","Gcomma","Gsemicolon","Gcolon","paragraph break",
               "leftquote","rightquote","and","hulet","sost","arat","amst",
               "sadst","sabat","smnt","zeteN","asr","heya","selasa",
               "arba","hemsa","slsa","seba","semanya","zeTana","meto",
               "asrxi","fland","ifland",
               "africa","inverted africa","C360","QMARK"};


char *FidelName[362]=
              {"le","lu","li","la","lE","l","lo","lWa",
               "me","mu","mi","ma","mE","m","mo","mWa",
               "re","ru","ri","ra","rE","r","ro","rWa",
               "xe","xu","xi","xa","xE","x","xo","xWa",
               "be","bu","bi","ba","bE","b","bo","bWa",
               "ve","vu","vi","va","vE","v","vo","vWa",
               "te","tu","ti","ta","tE","t","to","tWa",
               "ce","cu","ci","ca","cE","c","co","cWa",
               "ne","nu","ni","na","nE","n","no","nWa",
               "Ne","Nu","Ni","Na","NE","N","No","NWa",
               "ze","zu","zi","za","zE","z","zo","zWa",
               "Ze","Zu","Zi","Za","ZE","Z","Zo","ZWa",
               "de","du","di","da","dE","d","do","dWa",
               "Te","Tu","Ti","Ta","TE","T","To","TWa",
               "Ce","Cu","Ci","Ca","CE","C","Co","CWa",
               "fe","fu","Fi","fa","fE","f","fo","fWa",
               "se","su","si","sa","sE","s","so","sWa",
               "Se","Su","Si","Sa","SE","S","So","SWa",
               "e",  "u", "i", "a", "E","I", "o","e3",
               "he","hu","hi","ha","hE","h","ho","hWe","hWu","hWi","hWa","hWE",
               "ke","ku","ki","ka","kE","k","ko","kWe","kWu","kWi","kWa","kWE",
               "Ke","Ku","Ki","Ka","KE","K","Ko","KWe","KWu","KWi","KWa","KWE",
               "qe","qu","qi","qa","qE","q","qo","qWe","qWu","qWi","qWa","qWE",
               "Qe","Qu","Qi","Qa","QE","Q","Qo","QWe","QWu","QWi","QWa","QWE",
               "ge","gu","gi","ga","gE","g","go","gWe","gWu","gWi","gWa","gWE",
               "we","wu","wi","wa","wE","w","wo","wWe","wWu","wWi","wWa","wWE",
               "`se","`su","`si","`sa","`sE","`s","`so",
               "`Se","`Su","`Si","`Sa","`SE","`S","`So",
               "`e",  "`u", "`i", "`a", "`E","`I", "`o",
               "`he","`hu","`hi","`ha","`hE","`h","`ho",
               "`ke","`ku","`ki","`ka","`kE","`k","`ko",
               "Xe","Xu","Xi","Xa","XE","X","Xo",
               "He","Hu","Hi","Ha","HE","H","Ho",
               "ye","yu","yi","ya","yE","y","yo",
               "De","Du","Di","Da","DE","D","Do",
               "je","ju","ji","ja","jE","j","jo",
               "Ge","Gu","Gi","Ga","GE","G","Go",
               "Pe","Pu","Pi","Pa","PE","P","Po",
               "pe","pu","pi","pa","pE","p","po",


               "\" \" ","(:)","::",",", ";", ":", "*", "<<", ">>",
                "(1)", "(2)", "(3)", "(4)", "(5)", "(6)", "(7)", "(8)",  "(9)", "(10)",
               "(20)","(30)","(40)","(50)","(60)","(70)","(80)","(90)","(100)", "(10,000)",
               "fland","ifland","africa","iafrica","\\?","?"};




/*  Traditional Mapping onto the Mathematical Fidel Model */

int Fidel[362]={  7,  8,  9, 10, 11, 12, 13, 14,                 /* le - lWa */
                 22, 23, 24, 25, 26, 27, 28, 29,                 /* me - mWa */ 
                 37, 38, 39, 40, 41, 42, 43, 44,                 /* re - rWa */
                 53, 54, 55, 56, 57, 58, 59, 60,                 /* xe - xWa */
                 85, 86, 87, 88, 89, 90, 91, 92,                 /* be - bWa */
                 93, 94, 95, 96, 97, 98, 99,100,                 /* ve - vWa */
                101,102,103,104,105,106,107,108,                 /* te - tWa */
                109,110,111,112,113,114,115,116,                 /* ce - cWa */
                129,130,131,132,133,134,135,136,                 /* ne - nWa */
                137,138,139,140,141,142,143,144,                 /* Ne - NWa */
                210,211,212,213,214,215,216,217,                 /* ze - zWa */
                218,219,220,221,222,223,224,225,                 /* Ze - ZWa */
                233,234,235,236,237,238,239,240,                 /* de - dWa */
                274,275,276,277,278,279,280,281,                 /* Te - TWa */
                282,283,284,285,286,287,288,289,                 /* Ce - CWa */
                319,320,321,322,323,324,325,326,                 /* fe - fWa */
                 45, 46, 47, 48, 49, 50, 51, 52,                 /* se - sWa */
                297,298,299,300,301,302,303,304,                 /* Se - SWa */
                145,146,147,148,149,150,151,152,                 /* e/a-  e3 */
                  0,  1,  2,  3,  4,  5,  6,124,125,126,127,128, /* he - hWE */
                153,154,155,156,157,158,159,160,161,162,163,164, /* ke - kWE */
                172,173,174,175,176,177,178,179,180,181,182,183, /* Ke - KWE */
                 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, /* qe - qWE */
                 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, /* Qe - QWE */
                255,256,257,258,259,260,261,262,263,264,265,266, /* ge - gWE */
                191,192,193,194,195,196,197,198,199,200,201,202, /* we - wWE */
                 30, 31, 32, 33, 34, 35, 36,                     /*`se - `so */
                305,306,307,308,309,310,311,                     /*`Se - `So */
                203,204,205,206,207,208,209,                     /* `e - `o  */
                117,118,119,120,121,122,123,                     /*`he - `ho */
                165,166,167,168,169,170,171,                     /*`ke - `ko */
                184,185,186,187,188,189,190,                     /* Xe - Xo  */
                 15, 16, 17, 18, 19, 20, 21,                     /* He - Ho  */
                226,227,228,229,230,231,232,                     /* ye - yo  */
                241,242,243,244,245,246,247,                     /* De - Do  */
                248,249,350,351,352,353,354,                     /* je - jo  */
                267,268,269,270,271,272,273,                     /* Ge - Go  */
                290,291,292,293,294,295,296,                     /* Pe - Po  */
                312,313,314,315,316,317,318,                     /* pe - po  */
                327,328,329,330,331,332,333,334,335,          /* punctuation */
                336,337,338,339,340,341,342,343,344,345,         /*  1 - 10  */
                346,347,348,349,350,351,352,353,354,355,         /* 20 - 100 */
                356,357,358,359,360,361};                        /*  Glyphs  */




/*  Mathematical Fidel Mapping onto the Traditional */

int TraditionalOrder[362]=
               {152,153,154,155,156,157,158,                     /* he - ho  */
                  0,  1,  2,  3,  4,  5,  6,  7,                 /* le - lWa */
                278,279,280,281,282,283,284,                     /* He - Ho  */
                  8,  9, 10 ,11 ,12, 13, 14, 15,                 /* me - mWa */ 
                236,237,238,239,240,241,242,                     /*`se - `so */
                 16, 17, 18, 19, 20, 21, 22, 23,                 /* re - rWa */
                128,129,130,131,132,133,134,135,                 /* se - sWa */
                 24, 25, 26, 27, 28, 29, 30, 31,                 /* xe - xWa */
                188,189,190,191,192,193,194,195,196,197,198,199, /* qe - qWE */
                200,201,202,203,204,205,206,207,208,209,210,211, /* Qe - QWE */
                 32, 33, 34, 35, 36, 37, 38, 39,                 /* be - bWa */
                 40, 41, 42, 43, 44, 45, 46, 47,                 /* ve - vWa */
                 48, 49, 50, 51, 52, 53, 54, 55,                 /* te - tWa */
                 56, 57, 58, 59, 60, 61, 62, 63,                 /* ce - cWa */
                257,258,259,260,261,262,263,159,160,161,162,163, /*`he - hWE */
                 64, 65, 66, 67, 68, 69, 70, 71,                 /* ne - nWa */
                 72, 73, 74, 75, 76, 77, 78, 79,                 /* Ne - NWa */
                144,145,146,147,148,149,150,151,                 /* e/a-  e3 */
                164,165,166,167,168,169,170,171,172,173,174,175, /* ke - kWE */
                176,177,178,179,180,181,182,183,184,185,186,187, /* Ke - KWE */
                224,225,226,227,228,229,230,231,232,233,234,235, /* we - wWE */
                250,251,252,253,254,255,256,                     /* `e - `o  */
                 80, 81, 82, 83, 84, 85, 86, 87,                 /* ze - zWa */
                 88, 89, 90, 91, 92, 93, 94, 95,                 /* Ze - ZWa */
                285,286,287,288,289,290,291,                     /* ye - yo  */
                 96, 97, 98, 99,100,101,102,103,                 /* de - dWa */
                299,300,301,302,303,304,305,                     /* je - jo  */
                212,213,214,215,216,217,218,219,220,221,222,223, /* ge - gWE */
                104,105,106,107,108,109,110,111,                 /* Te - TWa */
                112,113,114,115,116,117,118,119,                 /* Ce - CWa */
                313,314,315,316,317,318,319,                     /* Pe - Po  */
                136,137,138,139,140,141,142,143,                 /* Se - SWa */
                243,244,245,246,247,248,249,                     /*`Se - `So */
                120,121,122,123,124,125,126,127,                 /* fe - fWa */
                320,321,322,323,324,325,326,                     /* pe - po  */

                264,265,266,267,268,269,270,                     /*`ke - `ko */
                271,272,273,274,275,276,277,                     /* Xe - Xo  */
                292,293,294,295,296,297,298,                     /* De - Do  */
                306,307,308,309,310,311,312,                     /* Ge - Go  */

                327,328,330,331,332,329,360,333,334,335,361,     /* punctuation */
                336,337,338,339,340,341,342,343,344,345,         /*  1 - 10  */
                346,347,348,349,350,351,352,353,354,355,         /* 20 - 100 */ 
                356,357,358,359};                                /*  Glyphs  */




/*  LaTeX Phonetic Mappings Here */


char e[]="\\\"{a}"    ,               /* Define Vowel  Elemants */
     u[]="u"          ,  
     i[]="i"          ,  
     a[]="a"          ,  
     E[]="\\={e}"     ,  
     I[]="{\\i}"      ,  
     Y[]=""           ,               /* Keep Y Empty!!         */
     o[]="o"          ,  
     We[]="w\\\"{a}"  , 
     Wu[]="w"         , 
     Wi[]="wi"        , 
     Wa[]="wa"        , 
     WE[]="w\\={e}"   ; 


char h[] = "h"        ,              /* Define Consonants */
     l[] = "l"        ,  
     H[] = "\\d{h}"   ,  
     m[] = "m"        ,  
     s2[] = "\\'{s}"  , 
     r[] = "r"        ,  
     s[] = "s"        ,  
     x[] = "\\v{s}"   ,  
     q[] = "q"        ,  
     Q[] = "\\v{q}"   ,  
     b[] = "b"        ,  
     v[] = "v"        ,  
     t[] = "t"        ,  
     c[] = "\\v{c}"   ,  
    h2[] = "\\b{h}"   ,  
     n[] = "n"        ,  
     N[] = "\\~{n}"   ,  
     k[] = "k"        ,  
    k2[] = "k'"       ,  
     K[] = "x"        ,  
     X[] = "x'"       ,  
     w[] = "w"        ,  
    a2[] = "`"        ,  
     z[] = "z"        ,  
     Z[] = "Z"        ,  
     y[] = "y"        ,  
     d[] = "d"        ,  
     D[] = "\\d{d}"   ,  
     j[] = "j"        ,  
     g[] = "g"        ,  
     G[] = "\\d{g}"   ,  
     T[] = "\\d{t}"   ,  
     C[] = "\\.{c}"   ,  
     P[] = "\\d{p}"   ,  
     S[] = "\\d{s}"   ,  
    S2[] = "\\d{d}"   ,  
     f[] = "f"        ,  
     p[] = "p"        ;


char space[] = "--"   ,  
    espace[] = " "    ,  
/*  period[] = "::"   ,  */
    period[] = "."    ,  
     comma[] = ","    ,  
    scolon[] = ";"    ,  
     colon[] = ":"    ,  
     parag[] = ""     ,  
    lquote[] = "\""   ,  
    rquote[] = "\""   ,  
       one[] = "1"    ,  
       two[] = "2"    ,  
     three[] = "3"    ,  
      four[] = "4"    ,  
      five[] = "5"    ,  
       six[] = "6"    ,  
     seven[] = "7"    ,  
     eight[] = "8"    ,  
      nine[] = "9"    ,  
       ten[] = "10"   ,  
      twen[] = "20"   ,  
      thir[] = "30"   ,  
     fourt[] = "40"   ,  
       fif[] = "50"   ,  
      sixt[] = "60"   ,  
    sevent[] = "70"   ,  
    eighty[] = "80"   ,  
     ninet[] = "90"   ,  
      hund[] = "1,000" ,  
    tthous[] = "10,000";

typedef struct {
          char* c;
          char* v;
       } phonset; 

phonset amharic[362]=                 /* Amharic Rules */

      {{h,a}, {h,u}, {h,i}, {h,a}, {h,E}, {h,Y}, {h,o},          /*   0 -   6 */
       {l,e}, {l,u}, {l,i}, {l,a}, {l,E}, {l,Y}, {l,o}, {l,Wa},  /*   7 -  14 */
       {h,a}, {h,u}, {h,i}, {h,a}, {h,E}, {h,Y}, {h,o},          /*  15 -  21 */
       {m,e}, {m,u}, {m,i}, {m,a}, {m,E}, {m,Y}, {m,o}, {m,Wa},  /*  22 -  29 */
       {s,e}, {s,u}, {s,i}, {s,a}, {s,E}, {s,Y}, {s,o},          /*  30 -  36 */
       {r,e}, {r,u}, {r,i}, {r,a}, {r,E}, {r,Y}, {r,o}, {r,Wa},  /*  37 -  44 */
       {s,e}, {s,u}, {s,i}, {s,a}, {s,E}, {s,Y}, {s,o}, {s,Wa},  /*  45 -  52 */
       {x,e}, {x,u}, {x,i}, {x,a}, {x,E}, {x,Y}, {x,o}, {x,Wa},  /*  53 -  60 */
       {q,e}, {q,u}, {q,i}, {q,a}, {q,E}, {q,Y}, {q,o}, {q,We}, {q,Wu}, {q,Wi}, {q,Wa}, {q,WE}, /* 61 - 72 */
       {Q,e}, {Q,u}, {Q,i}, {Q,a}, {Q,E}, {Q,Y}, {Q,o}, {Q,We}, {Q,Wu}, {Q,Wi}, {Q,Wa}, {Q,WE}, /* 73 - 84 */
       {b,e}, {b,u}, {b,i}, {b,a}, {b,E}, {b,Y}, {b,o}, {b,Wa},  /*  85 -  92 */
       {v,e}, {v,u}, {v,i}, {v,a}, {v,E}, {v,Y}, {v,o}, {v,Wa},  /*  93 - 100 */
       {t,e}, {t,u}, {t,i}, {t,a}, {t,E}, {t,Y}, {t,o}, {t,Wa},  /* 101 - 108 */
       {c,e}, {c,u}, {c,i}, {c,a}, {c,E}, {c,Y}, {c,o}, {c,Wa},  /* 109 - 116 */
       {h,a}, {h,u}, {h,i}, {h,a}, {h,E}, {h,Y}, {h,o}, {h,We}, {h,Wu}, {h,Wi}, {h,Wa}, {h,WE}, /* 117 - 128 */
       {n,e}, {n,u}, {n,i}, {n,a}, {n,E}, {n,Y}, {n,o}, {n,Wa},  /* 129 - 136 */
       {N,e}, {N,u}, {N,i}, {N,a}, {N,E}, {N,Y}, {N,o}, {N,Wa},  /* 137 - 144 */
       {Y,a}, {Y,u}, {Y,i}, {Y,a}, {Y,E}, {Y,I}, {Y,o}, {Y,e},   /* 145 - 152 */
       {k,e}, {k,u}, {k,i}, {k,a}, {k,E}, {k,Y}, {k,o}, {k,We}, {k,Wu}, {k,Wi}, {k,Wa}, {k,WE}, /* 153 - 164 */
       {k2,e}, {k2,u}, {k2,i}, {k2,a}, {k2,E}, {k2,Y}, {k2,o},   /* 165 - 171 */
       {K,e}, {K,u}, {K,i}, {K,a}, {K,E}, {K,Y}, {K,o}, {K,We}, {K,Wu}, {K,Wi}, {K,Wa}, {K,WE}, /* 172 - 183 */
       {X,e}, {X,u}, {X,i}, {X,a}, {X,E}, {X,Y}, {X,o},          /* 184 - 190 */
       {w,e}, {w,u}, {w,i}, {w,a}, {w,E}, {w,Y}, {w,o}, {w,We}, {w,Wu}, {w,Wi}, {w,Wa}, {w,WE}, /* 191 - 202 */
       {Y,a}, {Y,u}, {Y,i}, {Y,a}, {Y,E}, {Y,I}, {Y,o},          /* 203 - 209 */
       {z,e}, {z,u}, {z,i}, {z,a}, {z,E}, {z,Y}, {z,o}, {z,Wa},  /* 210 - 217 */
       {Z,e}, {Z,u}, {Z,i}, {Z,a}, {Z,E}, {Z,Y}, {Z,o}, {Z,Wa},  /* 218 - 225 */
       {y,e}, {y,u}, {y,i}, {y,a}, {y,E}, {y,Y}, {y,o},          /* 226 - 232 */
       {d,e}, {d,u}, {d,i}, {d,a}, {d,E}, {d,Y}, {d,o}, {d,Wa},  /* 233 - 240 */
       {D,e}, {D,u}, {D,i}, {D,a}, {D,E}, {D,Y}, {D,o},          /* 241 - 247 */
       {j,e}, {j,u}, {j,i}, {j,a}, {j,E}, {j,Y}, {j,o},          /* 248 - 254 */
       {g,e}, {g,u}, {g,i}, {g,a}, {g,E}, {g,Y}, {g,o}, {g,We}, {g,Wu}, {g,Wi}, {g,Wa}, {g,WE}, /* 255 - 266 */
       {G,e}, {G,u}, {G,i}, {G,a}, {G,E}, {G,Y}, {G,o},          /* 267 - 273 */
       {T,e}, {T,u}, {T,i}, {T,a}, {T,E}, {T,Y}, {T,o}, {T,Wa},  /* 274 - 281 */
       {C,e}, {C,u}, {C,i}, {C,a}, {C,E}, {C,Y}, {C,o}, {C,Wa},  /* 282 - 289 */
       {P,e}, {P,u}, {P,i}, {P,a}, {P,E}, {P,Y}, {P,o},          /* 290 - 296 */
       {S,e}, {S,u}, {S,i}, {S,a}, {S,E}, {S,Y}, {S,o}, {S,Wa},  /* 297 - 304 */
       {S,e}, {S,u}, {S,i}, {S,a}, {S,E}, {S,Y}, {S,o},          /* 305 - 312 */
       {p,e}, {p,u}, {p,i}, {p,a}, {p,E}, {p,Y}, {p,o},          /* 312 - 319 */
       {f,e}, {f,u}, {f,i}, {f,a}, {f,E}, {f,Y}, {f,o}, {f,Wa},  /* 319 - 326 */

       {space,Y},{espace,Y},{period,Y},{comma,Y},{scolon,Y},{colon,Y},{parag,Y},
       {lquote,Y},{rquote,Y},{one,Y},{two,Y},{three,Y},{four,Y},{five,Y},
       {six,Y},{seven,Y},{eight,Y},{nine,Y},{ten,Y},{twen,Y},{thir,Y},
       {fourt,Y},{fif,Y},{sixt,Y},{sevent,Y},{eighty,Y},{ninet,Y},{hund,Y},
       {tthous,Y}, {Y,Y}, {Y,Y},
       {Y,Y}, {Y,Y}, {Y,Y}, {Y,Y}};


phonset tigrigna[362]=                 /* Tigrigna Rules */

      {{h,e}, {h,u}, {h,i}, {h,a}, {h,E}, {h,Y}, {h,o},          /*   0 -   6 */
       {l,e}, {l,u}, {l,i}, {l,a}, {l,E}, {l,Y}, {l,o}, {l,Wa},  /*   7 -  14 */
       {H,e}, {H,u}, {H,i}, {H,a}, {H,E}, {H,Y}, {H,o},          /*  15 -  21 */
       {m,e}, {m,u}, {m,i}, {m,a}, {m,E}, {m,Y}, {m,o}, {m,Wa},  /*  22 -  29 */
       {s,e}, {s,u}, {s,i}, {s,a}, {s,E}, {s,Y}, {s,o},          /*  30 -  36 */
       {r,e}, {r,u}, {r,i}, {r,a}, {r,E}, {r,Y}, {r,o}, {r,Wa},  /*  37 -  44 */
       {s,e}, {s,u}, {s,i}, {s,a}, {s,E}, {s,Y}, {s,o}, {s,Wa},  /*  45 -  52 */
       {x,e}, {x,u}, {x,i}, {x,a}, {x,E}, {x,Y}, {x,o}, {x,Wa},  /*  53 -  60 */
       {q,e}, {q,u}, {q,i}, {q,a}, {q,E}, {q,Y}, {q,o}, {q,We}, {q,Wu}, {q,Wi}, {q,Wa}, {q,WE}, /* 61 - 72 */
       {Q,e}, {Q,u}, {Q,i}, {Q,a}, {Q,E}, {Q,Y}, {Q,o}, {Q,We}, {Q,Wu}, {Q,Wi}, {Q,Wa}, {Q,WE}, /* 73 - 84 */
       {b,e}, {b,u}, {b,i}, {b,a}, {b,E}, {b,Y}, {b,o}, {b,Wa},  /*  85 -  92 */
       {v,e}, {v,u}, {v,i}, {v,a}, {v,E}, {v,Y}, {v,o}, {v,Wa},  /*  93 - 100 */
       {t,e}, {t,u}, {t,i}, {t,a}, {t,E}, {t,Y}, {t,o}, {t,Wa},  /* 101 - 108 */
       {c,e}, {c,u}, {c,i}, {c,a}, {c,E}, {c,Y}, {c,o}, {c,Wa},  /* 109 - 116 */
       {h,e}, {h,u}, {h,i}, {h,a}, {h,E}, {h,Y}, {h,o}, {h,We}, {h,Wu}, {h,Wi}, {h,Wa}, {h,WE}, /* 117 - 128 */
       {n,e}, {n,u}, {n,i}, {n,a}, {n,E}, {n,Y}, {n,o}, {n,Wa},  /* 129 - 136 */
       {N,e}, {N,u}, {N,i}, {N,a}, {N,E}, {N,Y}, {N,o}, {N,Wa},  /* 137 - 144 */
       {Y,e}, {Y,u}, {Y,i}, {Y,a}, {Y,E}, {Y,I}, {Y,o}, {Y,e},   /* 145 - 152 */
       {k,e}, {k,u}, {k,i}, {k,a}, {k,E}, {k,Y}, {k,o}, {k,We}, {k,Wu}, {k,Wi}, {k,Wa}, {k,WE}, /* 153 - 164 */
       {k2,e}, {k2,u}, {k2,i}, {k2,a}, {k2,E}, {k2,Y}, {k2,o},   /* 165 - 171 */
       {K,e}, {K,u}, {K,i}, {K,a}, {K,E}, {K,Y}, {K,o}, {K,We}, {K,Wu}, {K,Wi}, {K,Wa}, {K,WE}, /* 172 - 183 */
       {X,e}, {X,u}, {X,i}, {X,a}, {X,E}, {X,Y}, {X,o},          /* 184 - 190 */
       {w,e}, {w,u}, {w,i}, {w,a}, {w,E}, {w,Y}, {w,o}, {w,We}, {w,Wu}, {w,Wi}, {w,Wa}, {w,WE}, /* 191 - 202 */
       {a2,e}, {a2,u}, {a2,i}, {a2,a}, {a2,E}, {a2,I}, {a2,o},   /* 203 - 209 */
       {z,e}, {z,u}, {z,i}, {z,a}, {z,E}, {z,Y}, {z,o}, {z,Wa},  /* 210 - 217 */
       {Z,e}, {Z,u}, {Z,i}, {Z,a}, {Z,E}, {Z,Y}, {Z,o}, {Z,Wa},  /* 218 - 225 */
       {y,e}, {y,u}, {y,i}, {y,a}, {y,E}, {y,Y}, {y,o},          /* 226 - 232 */
       {d,e}, {d,u}, {d,i}, {d,a}, {d,E}, {d,Y}, {d,o}, {d,Wa},  /* 233 - 240 */
       {D,e}, {D,u}, {D,i}, {D,a}, {D,E}, {D,Y}, {D,o},          /* 241 - 247 */
       {j,e}, {j,u}, {j,i}, {j,a}, {j,E}, {j,Y}, {j,o},          /* 248 - 254 */
       {g,e}, {g,u}, {g,i}, {g,a}, {g,E}, {g,Y}, {g,o}, {g,We}, {g,Wu}, {g,Wi}, {g,Wa}, {g,WE}, /* 255 - 266 */
       {G,e}, {G,u}, {G,i}, {G,a}, {G,E}, {G,Y}, {G,o},          /* 267 - 273 */
       {T,e}, {T,u}, {T,i}, {T,a}, {T,E}, {T,Y}, {T,o}, {T,Wa},  /* 274 - 281 */
       {C,e}, {C,u}, {C,i}, {C,a}, {C,E}, {C,Y}, {C,o}, {C,Wa},  /* 282 - 289 */
       {P,e}, {P,u}, {P,i}, {P,a}, {P,E}, {P,Y}, {P,o},          /* 290 - 296 */
       {S,e}, {S,u}, {S,i}, {S,a}, {S,E}, {S,Y}, {S,o}, {S,Wa},  /* 297 - 304 */
       {S,e}, {S,u}, {S,i}, {S,a}, {S,E}, {S,Y}, {S,o},          /* 305 - 311 */
       {p,e}, {p,u}, {p,i}, {p,a}, {p,E}, {p,Y}, {p,o},          /* 312 - 318 */
       {f,e}, {f,u}, {f,i}, {f,a}, {f,E}, {f,Y}, {f,o}, {f,Wa},  /* 319 - 325 */

       {space,Y},{espace,Y},{period,Y},{comma,Y},{scolon,Y},{colon,Y},{parag,Y},
       {lquote,Y},{rquote,Y},{one,Y},{two,Y},{three,Y},{four,Y},{five,Y},
       {six,Y},{seven,Y},{eight,Y},{nine,Y},{ten,Y},{twen,Y},{thir,Y},
       {fourt,Y},{fif,Y},{sixt,Y},{sevent,Y},{eighty,Y},{ninet,Y},{hund,Y},
       {tthous,Y}, {Y,Y}, {Y,Y},
       {Y,Y}, {Y,Y}, {Y,Y}, {Y,Y}};

phonset ge_ez[362]=                 /* Ge'ez Rules */

      {{h,e}, {h,u}, {h,i}, {h,a}, {h,E}, {h,Y}, {h,o},          /*   0 -   6 */
       {l,e}, {l,u}, {l,i}, {l,a}, {l,E}, {l,Y}, {l,o}, {l,Wa},  /*   7 -  14 */
       {H,e}, {H,u}, {H,i}, {H,a}, {H,E}, {H,Y}, {H,o},          /*  15 -  21 */
       {m,e}, {m,u}, {m,i}, {m,a}, {m,E}, {m,Y}, {m,o}, {m,Wa},  /*  22 -  29 */
       {s2,e}, {s2,u}, {s2,i}, {s2,a}, {s2,E}, {s2,Y}, {s2,o},   /*  30 -  36 */
       {r,e}, {r,u}, {r,i}, {r,a}, {r,E}, {r,Y}, {r,o}, {r,Wa},  /*  37 -  44 */
       {s,e}, {s,u}, {s,i}, {s,a}, {s,E}, {s,Y}, {s,o}, {s,Wa},  /*  45 -  52 */
       {x,e}, {x,u}, {x,i}, {x,a}, {x,E}, {x,Y}, {x,o}, {x,Wa},  /*  53 -  60 */
       {q,e}, {q,u}, {q,i}, {q,a}, {q,E}, {q,Y}, {q,o}, {q,We}, {q,Wu}, {q,Wi}, {q,Wa}, {q,WE}, /* 61 - 72 */
       {Q,e}, {Q,u}, {Q,i}, {Q,a}, {Q,E}, {Q,Y}, {Q,o}, {Q,We}, {Q,Wu}, {Q,Wi}, {Q,Wa}, {Q,WE}, /* 73 - 84 */
       {b,e}, {b,u}, {b,i}, {b,a}, {b,E}, {b,Y}, {b,o}, {b,Wa},  /*  85 -  92 */
       {v,e}, {v,u}, {v,i}, {v,a}, {v,E}, {v,Y}, {v,o}, {v,Wa},  /*  93 - 100 */
       {t,e}, {t,u}, {t,i}, {t,a}, {t,E}, {t,Y}, {t,o}, {t,Wa},  /* 101 - 108 */
       {c,e}, {c,u}, {c,i}, {c,a}, {c,E}, {c,Y}, {c,o}, {c,Wa},  /* 109 - 116 */
       {h2,e}, {h2,u}, {h2,i}, {h2,a}, {h2,E}, {h2,Y}, {h2,o}, {h2,We}, {h2,Wu}, {h2,Wi}, {h2,Wa}, {h2,WE}, /* 117 - 128 */
       {n,e}, {n,u}, {n,i}, {n,a}, {n,E}, {n,Y}, {n,o}, {n,Wa},  /* 129 - 136 */
       {N,e}, {N,u}, {N,i}, {N,a}, {N,E}, {N,Y}, {N,o}, {N,Wa},  /* 137 - 144 */
       {Y,e}, {Y,u}, {Y,i}, {Y,a}, {Y,E}, {Y,I}, {Y,o}, {Y,e},   /* 145 - 152 */
       {k,e}, {k,u}, {k,i}, {k,a}, {k,E}, {k,Y}, {k,o}, {k,We}, {k,Wu}, {k,Wi}, {k,Wa}, {k,WE}, /* 153 - 164 */
       {k2,e}, {k2,u}, {k2,i}, {k2,a}, {k2,E}, {k2,Y}, {k2,o},   /* 165 - 171 */
       {K,e}, {K,u}, {K,i}, {K,a}, {K,E}, {K,Y}, {K,o}, {K,We}, {K,Wu}, {K,Wi}, {K,Wa}, {K,WE}, /* 172 - 183 */
       {X,e}, {X,u}, {X,i}, {X,a}, {X,E}, {X,Y}, {X,o},          /* 184 - 190 */
       {w,e}, {w,u}, {w,i}, {w,a}, {w,E}, {w,Y}, {w,o}, {w,We}, {w,Wu}, {w,Wi}, {w,Wa}, {w,WE}, /* 191 - 202 */
       {a2,e}, {a2,u}, {a2,i}, {a2,a}, {a2,E}, {a2,I}, {a2,o},   /* 203 - 209 */
       {z,e}, {z,u}, {z,i}, {z,a}, {z,E}, {z,Y}, {z,o}, {z,Wa},  /* 210 - 217 */
       {Z,e}, {Z,u}, {Z,i}, {Z,a}, {Z,E}, {Z,Y}, {Z,o}, {Z,Wa},  /* 218 - 225 */
       {y,e}, {y,u}, {y,i}, {y,a}, {y,E}, {y,Y}, {y,o},          /* 226 - 232 */
       {d,e}, {d,u}, {d,i}, {d,a}, {d,E}, {d,Y}, {d,o}, {d,Wa},  /* 233 - 240 */
       {D,e}, {D,u}, {D,i}, {D,a}, {D,E}, {D,Y}, {D,o},          /* 241 - 247 */
       {j,e}, {j,u}, {j,i}, {j,a}, {j,E}, {j,Y}, {j,o},          /* 248 - 254 */
       {g,e}, {g,u}, {g,i}, {g,a}, {g,E}, {g,Y}, {g,o}, {g,We}, {g,Wu}, {g,Wi}, {g,Wa}, {g,WE}, /* 255 - 266 */
       {G,e}, {G,u}, {G,i}, {G,a}, {G,E}, {G,Y}, {G,o},          /* 267 - 273 */
       {T,e}, {T,u}, {T,i}, {T,a}, {T,E}, {T,Y}, {T,o}, {T,Wa},  /* 274 - 281 */
       {C,e}, {C,u}, {C,i}, {C,a}, {C,E}, {C,Y}, {C,o}, {C,Wa},  /* 282 - 289 */
       {P,e}, {P,u}, {P,i}, {P,a}, {P,E}, {P,Y}, {P,o},          /* 290 - 296 */
       {S,e}, {S,u}, {S,i}, {S,a}, {S,E}, {S,Y}, {S,o}, {S,Wa},  /* 297 - 304 */
       {S2,e}, {S2,u}, {S2,i}, {S2,a}, {S2,E}, {S2,Y}, {S2,o},   /* 305 - 311 */
       {p,e}, {p,u}, {p,i}, {p,a}, {p,E}, {p,Y}, {p,o},          /* 312 - 318 */
       {f,e}, {f,u}, {f,i}, {f,a}, {f,E}, {f,Y}, {f,o}, {f,Wa},  /* 319 - 325 */

       {space,Y},{espace,Y},{period,Y},{comma,Y},{scolon,Y},{colon,Y},{parag,Y},
       {lquote,Y},{rquote,Y},{one,Y},{two,Y},{three,Y},{four,Y},{five,Y},
       {six,Y},{seven,Y},{eight,Y},{nine,Y},{ten,Y},{twen,Y},{thir,Y},
       {fourt,Y},{fif,Y},{sixt,Y},{sevent,Y},{eighty,Y},{ninet,Y},{hund,Y},
       {tthous,Y}, {Y,Y}, {Y,Y},
       {Y,Y}, {Y,Y}, {Y,Y}, {Y,Y}};

phonset*  fscript[] = {amharic,ge_ez,tigrigna};

#include "greek.h"
