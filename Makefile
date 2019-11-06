# Author: Peiyi Guan
# Date: July 2019

SRC = main.c error.c array.c
OBJ = main.o error.o array.o
HDR = array.h functions.h

TRG = mmaparray

${TRG}: ${OBJ}
	gcc -g ${OBJ} -pthread -lc -o ${TRG}

main.o: main.c ${HDR}
	gcc -g -c -pthread main.c

error.o: error.c ${HDR}
	gcc -g -c error.c

clean:
	/bin/rm ${OBJ} ${TRG} *~

tar:
	tar cf mmaparray.tar ${SRC} ${HDR} Makefile
	../sendit mmaparray.tar

