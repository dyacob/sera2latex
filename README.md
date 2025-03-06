# FIDEL AND PHONETIC TRANSCRIBER FOR LATEX 

## NOTE
*This is a archived work last updated in 1995, it is not expected to
 build out-of-the-box.  Abundant and better quality solutions are
 available today. The PK in this package are available as TrueType and
 Ethiopic text may not be authored directly in Unicode.*
              


SERA2LaTeX 0.11
================

SERA2LaTeX provides a means to convert Latin text written in SERA into
TeX and LaTeX output for Fidel [aka Ethiopic, Ge'ez, Abyssinic] script
or into a Latin based phonetic symbology.

The symbol choice for the phonetic output is adjustable by the user, edits
need only be made in the `fidel.h' file prior to compilation.

The Fidel script output relies on the "Washra" family of LaTeX fonts
created for the EthTeX package by Abass Alemnehe.  Five sizes are provided.

THIS RELEASE of the sera2latex package has seen very limited testing but
will perform reliably with the samples provided.  This package will be under 
continuous development, in the near future a version will be avilalbe for
converting SERA based La\TeX format files into acceptable input for TeX and
LaTeX.  User response and suggestions will govern the course of future
development of this package.


INSTALLATION
------------

Read the "INSTALL" document for instructions.  If problems occur
you may contact me at yacob@apollo.aoe.vt.edu for assistance in this
area.


HOW TO USE
==========

After successful installation you may use your favorite ascii editor to write
a SERA text file and convert to TeX or LaTeX.  You will need to check which
is available on your system.

LaTeX is the default output:

	s2l myfile > myfile.tex

For TeX output:

	s2l -tex myfile > myfile.tex
 
Eview v0.5 may also be used to preview the file SERA file.  To print the .tex
file two additional steps are required.  The first is to compile the TeX or
LaTeX document --this will produce a .dvi file.  The next is to convert the
.dvi file into postscript format.


Printing
--------

Beginning with the .tex file (produced as shown above) the following steps
for printing are:

    latex myfile.tex                   [alternately: tex myfile.tex]
    dvips -f myfile.dvi > myfile.ps
    lpr myfile.ps

Once in postscript form, you may preview with `ghostview', `xpsv', or
`xpsview' etc.


The complete list of options:
----------------------------

-n)  Change the font size from the default.  The default is size 10,
     Others available are 12, 14, 18, and 36.  Example use:

                s2l -n 18 myfile > myfile.tex

-l)  If your file begins with Latin script, you will either need to add a
     \ as the first character in the file.  Or perform the following:

                s2l -l lat myfile > myfile.tex

     Where "lat" is required to indicate the starting script if not Fidel.
     "gre" is available for Greek script.

-g)  This option will read files written to appear in the traditional
     style.  See the file "etc/yoHens" as an example. 
     Use as per:

                s2l -g docs/yoHens > yoHens.tex

-s)  If you would like to switch all of the blank spaces, " ", into Ethiopic
     word spaces (:), in the Ethiopic portions of your text, do as follows:


                s2l -s myfile > myfile.tex

-stats) Provides a Fidel table with statistical output of character
        occurances into the file ``s2l.stats''.

                s2l -stats myfile > myfile.tex

-tex) Generates output in TeX format.  Example use:

                s2l -tex myfile > myfile.tex

-pho) Transcribes SERA file into phonetic output.  Example use:

                s2l -pho myfile > myfile.tex

      The -pho option ignores -s and -filt

-pre) Preserves the original text format.  That is TeX and LaTeX control
      symbols are inserted to turn-off the word wrapping which is automatic
      in TeX and LaTeX.  Example use:

                s2l -pre -g shake > shake.tex

-filt) This option is to be used with a document already in TeX or LaTeX
       format.  The filter will find and replace sera encoding marked by
       identifying keywords.  The rest of the document should remain 
       undisturbed.  The keywords that ``fitler'' searches for serve a
       secondary purpose for writing with mixed font sizes.  The definitions
       follow:

       FONT SIZE        KEYWORD             TRANSLATION
       -------------------------------------------------------
          10            \sera{ }      \washra{ }    , \washrx{ }
          12            \Sera{ }      \Washra{ }    , \Washrx{ }
          14            \SERA{ }      \WASHRA{ }    , \WASHRx{ }
          18            \Sera{ }      \bigwashra{ } , \bigwasrx{ }
          36            \Sera{ }      \BIGwashra{ } , \BIGwasrx{ }

       Useage:  \sera{selam, selamta, selmat \ hello!}
       
       Note that the ``sera'' keywords describes the encoding within
       the brackets { and }.  ``Washra'' and ``Washrx'' refer to specific
       font tables.  

       CAUTION:

         You MAY use    :    \texword{\sera{...}}
         You MAY NOT use:    \sera{\texword{...}}

         This deficiency will be addressed in later editions of this
         program.

       Example:

         s2l -filt -tex docs/demo-tex.tex > demo.tex
         tex demo.tex 
         dvips -f demo.dvi > demo.ps 

         s2l -filt docs/demo-latex.tex > demo.tex
         etc

_________________________________________________________________________
  Unless specified, you may use the -f, -g , -l, -s, -tex, -pho, -pre,
  -filt and -stats options together.
-------------------------------------------------------------------------

Samples
-------

The files "docs/recipe", "docs/fidel" and "docs/fidel2" are provided samples.
Print these files from the sera2latex directory (where s2l is located) by:

                s2l -l amh -pre docs/recipe > recipe.tex
                latex recipe.tex
                dvips -f recipe.dvi | lp
                 
                s2l -pho -pre docs/multilingual > mult.tex
                etc....
               

Gemination
----------

sera2latex offers different gemination handling for phonetic and fidel
ouputs.  Under the SERA-95 convention gemination is given by '' following
the character to be geminated.  The result in phonetic transcripiton is
doubling of the geminated character.  The two traditional styled ``dots''
are placed over the geminated character for Fidel output.

Example:

       SERA            PHONETIC              FIDEL
     ------------------------------------------------
                                               ..
       yele''m         yellem             (ye)(le)(m)




LIMITATIONS
===========

This La/TeX filter is not robust!
     Remember \texword{\sera{ }} OK,  \sera{\texword{ }} ... no promises.
                                      
 
Only one font size is available automatically for regular text files.

Some Gurage and Tigrigna series are not available:
     Ge -> Go, Xe -> Xo, `ke -> `ko, and KWe, KWi, KWa, KW, KWE

the nearest matching glyph will be substituted.

No number conversion is attempted when going from SERA->Phonetic

If LaTeX tells you: `` ! There's no line here to end. ''
just hit &lt;return&gt; and continue or look for a \\ on a line by itself and
delete it.
   
If bugs are found in the sera2latex converter, please open an issue:

	https://github.com/dyacob/sera2latex/issues


IF YOU WANT MORE LATEX POWER
----------------------------

Get the original LaTeX for Fidel --The EthTeX Package!!!  :-)

By Web:

   http://jasper.ora.com/CTAN/tex-archive/language/ethiopia/tree.htm


By ftp:    Official CTAN Archives

     Geographic                                          
     Location         Site                  IP Address   
     --------------------------------------------------------
     United States    ftp.shsu.edu          192.92.115.10
     United Kingdom   ftp.tex.ac.uk         131.151.79.32
     Germany          ftp.dante.de          129.206.100.192 



SERA
====

Extended documents for The System for Ethiopic Representation in ASCII (SERA)
by World Wide Web at: [http://abyssiniagateway.net/fidel/fidel.html](http://abyssiniagateway.net/fidel/fidel.html)
and [http:/abyssiniagateway.net/fidel/sera-faq.html](http:/abyssiniagateway.net/fidel/sera-faq.html).
The file docs/sera-sys.html gives an outline of the ascii system.

Briefly, characters are representation goes like :

     Consonants:
     me   mu   mi   ma   mE   m   mo   mWa

     Independent Vowels:
     e/a*  u/U  i    a/A  E   I   o/O   e3

     Independent Vowels Following a 6th Form Consonant:
              l'e   l'u   l'i   l'a   l'E   l'I   l'o
     also -->       lU          lA          lI    lO

     Consonants With 12 forms:
     hWe  hWu/hW'  hWi   hWa   hWE 

     *NOTE:  ``a'' may be used in place of ``e'' for the first lone
             vowel ONLY in Amharic text zones.  See INSTALL for 
             setting Amharic as a default language.

