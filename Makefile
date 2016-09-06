tp0: arvore.o main.o
	gcc main.o arvore.o -o tp0
main.o: main.c
	gcc -c main.c -o main.o
arvore.o: arvore.c arvore.h
	gcc -c arvore.c -o arvore.o
clean:
	rm *.o *gch
	rm tp0