
#ifndef UTIL_H
#define UTIL_H

#if __G_HAVE_BOOL

typedef bool boolean;

#else

  typedef enum {false, true} boolean;

#endif

#ifndef NIL
#define NIL      -1
#endif
#define WSIZE     120

#define NUMLANGS 5


enum Scripts  { fidel, latin, greek, graphic };
enum Languages{ amh, gez, tig, lat, gre, gfx };

typedef struct {
           enum Languages l; 
           enum Scripts   s;
        }  LS;
          
typedef struct {
           boolean ethspace, hard_mode, eth_only, html, gpunct;
           boolean pre, pho,tex,filt;         /* for sera2latex only */
           LS* new, *major, *next;
           int size;
        }  Flag;

typedef struct {
           Flag*            f;
           char*           in;
           int     out[WSIZE]; 
           LS*      ls[WSIZE]; 
           int       top, bot;
        }  Word;

#define LSDEFS {{amh,fidel},{gez,fidel},{tig,fidel},{lat,latin},{gre,greek},{gfx,graphic}}
#define LNAMES2 {"am", "gz", "ti", "la", "el"}
#define LNAMES3 {"amh","gez","tig","lat","gre"}


#endif

/*
**
**  The premise in transliteration routines that will require 
**  this header is that to uniquely identify a character, its 
**  script and language, at a minimum, must be known.
**
**  The LS structure is a list of ordered pairs of languages and
**  scripts that may be used to identify a character at the time
**  its address is assigned.  Both pieces of information will be
**  critical for some output applications, particularly when 
**  applying the phonetic rules of different languages using the
**  same script for their writing system.
**
**  The Flag structure contains the minimum number of flags
**  required by the transliteration routines for SERA.  Additional
**  flags may be added to the structure for application specific
**  requirements, but should only be applied externally from the 
**  transliteration packages.
**
**  The Word structure is what the sera language modules operate
**  on.  Any null terminated string of chars is suitable for
**  the ``in'' pointer for transcription.  The `out' vector will
**  contain the transcribed addresses.  Graphic entries will
**  simply be copied into the `out' vector where ~ which serves
**  as deliminator.
**
*/

