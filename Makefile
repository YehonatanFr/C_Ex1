CC = gcc
Ar = ar
Flags = -Wall -g
Objects_loop= advancedClassificationLoop.o basicClassification.o
Objects_rec= advancedClassificationRecursion.o basicClassification.o

all:loops recursives recursived loopd mains maindloop maindrec

basicClassification.o: basicClassification.c
	$(CC) $(Flags) -c basicClassification.c

advancedClassificationLoop.o: advancedClassificationLoop.c 
	$(CC) $(Flags) -c advancedClassificationLoop.c 

advancedClassificationRecursion.o: advancedClassificationRecursion.c
	$(CC) $(Flags) -c advancedClassificationRecursion.c
	
loops:libclassloops.a

libclassloops.a: $(Objects_loop)
	$(AR) -rcs libclassloops.a $(Objects_loop)

recursives:libclassrec.a

libclassrec.a: $(Objects_rec) 
	$(AR) -rcs libclassrec.a $(Objects_rec)

recursived:libclassrec.so

libclassrec.so: $(Objects_rec)
	$(CC) -shared -o libclassrec.so $(Objects_rec) -lm

loopd:libclassloops.so

libclassloops.so: $(Objects_loop)
	$(CC) -shared -o libclassloops.so $(Objects_loop) -lm

mains: $(Objects_main) libclassrec.a
	$(CC) $(Flags) -o mains $(Objects_main) libclassrec.a -lm

maindloop: $(Objects_main) libclassloops.so
	$(CC) $(Flags) -o maindloop $(Objects_main) -lm ./libclassloops.so

maindrec: $(Objects_main) libclassrec.so
	$(CC) $(Flags) -o maindrec $(Objects_main)  -lm ./libclassrec.so

main.o: main.c NumClass.h
	$(CC) $(Flags) -c main.c -lm

.PHONY: clean all

clean:
	rm -f *.o *.a *.so mains maindloop maindrec


