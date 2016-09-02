#include<stdio.h>
#include<stdlib.h>
#include "arvore.h"

int main(int argc, char * argv[])
{
    arvore *trie;
    int ordem = 0;
    trie = leDicionario(&ordem);
    leTexto(trie);
}