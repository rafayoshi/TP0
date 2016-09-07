#include<stdio.h>
#include<stdlib.h>
#include "arvore.h"

int main(int argc, char * argv[])
{
    arvore *trie;
    trie = leDicionario();
    leTexto(trie);
    compara(trie);
    imprimeResultado(trie);
    free(trie->ordem->palavraOrdem);
    free(trie->ordem);
    desalocaArvore(trie);

}