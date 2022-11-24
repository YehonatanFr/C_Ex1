CC = gcc
Ar = ar
Flags = -Wall -g
Objects_loop = advancedClassficationLoop.o basicClassfication.o
Objects_rec = advancedClassficationRecursion.o basicClassfication.o

all: loops recursives recursived loopd mains maindloop maindrec

basicClassfication.o: basicClassfication.c NumClass.h
	$(CC) $(Flags) -fPIC -c basicClassfication.c 

advancedClassficationLoop.o: advancedClassficationLoop.c NumClass.h
	$(CC) $(Flags) -fPIC -c advancedClassficationLoop.c 

advancedClassficationRecursion.o: advancedClassficationRecursion.c NumClass.h
	$(CC) $(Flags) -fPIC -c advancedClassficationRecursion.c 
	
loops: libclassloops.a

recursives: libclassrec.a

recursived: libclassrec.so

loopd: libclassloops.so

libclassloops.a: $(Objects_loop)
	$(AR) rcs libclassloops.a $(Objects_loop)

libclassrec.a: $(Objects_rec) 
	$(AR) rcs libclassrec.a $(Objects_rec)

libclassrec.so: $(Objects_rec)
	$(CC) -shared -o libclassrec.so $(Objects_rec)

libclassloops.so: $(Objects_loop)
	$(CC) -shared -o libclassloops.so $(Objects_loop)

mains: main.o libclassrec.a
	$(CC) $(Flags) main.o ./libclassrec.a -lm -o mains

maindloop: main.o libclassloops.so
	$(CC) $(Flags) main.o ./libclassloops.so -lm -o maindloop

maindrec: main.o libclassrec.so
	$(CC) $(Flags) main.o ./libclassrec.so -lm -o maindrec

main.o: main.c NumClass.h
	$(CC) $(Flags) -fPIC -c main.c NumClass.h

.PHONY: clean all

clean:
	rm -f *.o *.a *.so *.gch mains maindloop maindrec

#ljhns