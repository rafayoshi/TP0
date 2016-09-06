all: trie
trie: main.o arvore.o
	gcc -o trie main.o arvore.o -I

trie.o: trie.c trie.h

main.o: main.c trie.c trie.h