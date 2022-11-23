#Dictionery:
CC = gcc -c 
CFLAGS = -Wall -g
CLIB = ar rcs  
CLIBD = gcc -shared -o 

mains: main.o libclassrec.a 
	gcc -Wall main.o ./libclassrec.a -o mains -lm
maindloop: main.o libclassloops.so 
	gcc -Wall main.o ./libclassloops.so -o maindloop -lm
maindrec: main.o libclassrec.so 
	gcc -Wall main.o ./libclassrec.so -o maindrec -lm
	
loops: libclassloops.a
libclassloops.a: basicClassification.o advancedClassificationLoop.o
	$(CLIB) libclassloops.a basicClassification.o advancedClassificationLoop.o
     
loopd:libclassloops.so
libclassloops.so: basicClassification.o advancedClassificationLoop.o
	$(CLIBD) libclassloops.so basicClassification.o advancedClassificationLoop.o
   
recursives: libclassrec.a
libclassrec.a: basicClassification.o advancedClassificationRecursion.o
	$(CLIB) libclassrec.a basicClassification.o advancedClassificationRecursion.o
     
recursived: libclassrec.so 	
libclassrec.so: basicClassification.o advancedClassificationRecursion.o
	$(CLIBD) libclassrec.so basicClassification.o advancedClassificationRecursion.o	


basicClassification.o: basicClassification.c 
	$(CC) $(CFLAGS) -fPIC basicClassification.c	
advancedClassificationLoop.o: advancedClassificationLoop.c 
	$(CC) $(CFLAGS) -fPIC advancedClassificationLoop.c
advancedClassificationRecursion.o: advancedClassificationRecursion.c 
	$(CC) $(CFLAGS) -fPIC advancedClassificationRecursion.c
main.o: main.c NumClass.h
	$(CC) $(CFLAGS) main.c 	

all: mains maindloop maindrec libclassloops.a libclassloops.so libclassrec.a libclassrec.so 

.PHONY: clean 
clean: 
	rm -rf *.o *.a *.so maindloop mains maindrec



