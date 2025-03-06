
CC = cc
PROG =   s2l
LIBDIR = /usr/include  # the LIBDIR may require editing for your system
SOURCE1  = sera2latex.c fidel.c latin.c greek.c
OBJECTS1 = $(SOURCE1:.c=.o)

 
LIBS =
 
all: ${PROG} 
 
${PROG}:  $(OBJECTS1) 
	    $(CC) $(SOURCE1) -I$(LIBDIR) $(LIBS) -o ${PROG}
 

clean:
	    rm -f $(OBJECTS1) $(OBJECTS2)


