#include<stdio.h>
#include<stdlib.h>
#include "arvore.h"

int main(int argc, char * argv[])
{
    arvore *trie;
    trie = leDicionario();
    leTexto(trie);
    imprimeResultado(trie);
    // desalocaArvore(trie);
}