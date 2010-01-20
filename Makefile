CFLAGS = -W -Wall -g -O2 --std=c99

all : wisp

OBJ = wisp.o cons.o symbol.o common.o object.o hashtab.o mem.o

wisp : $(OBJ)

wisp.o : wisp.c cons.h symbol.h object.h common.h
cons.o : cons.c cons.h common.h mem.h
symbol.o : symbol.c symbol.h mem.h
object.o : object.c object.h mem.h
mem.o : mem.c mem.h
common.o : common.c common.h

# Hash table
hashtab.o : hashtab.c hashtab.h

.PHONY : all clean

clean : 
	$(RM) $(OBJ) wisp
