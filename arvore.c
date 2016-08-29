#include<stdio.h>
#include<stdlib.h>
#include<arvore.h>
#include "arvore.h"

arvore *criaArvore()
{
    arvore *trie;
    trie->reg = malloc(1 * sizeof(char *));
    trie->reg = malloc(26 * sizeof(char *));
    trie->reg[1] = "a";
    trie->reg[2] = "b";
    trie->reg[3] = "c";
    trie->reg[4] = "d";
    trie->reg[5] = "e";
    trie->reg[6] = "f";
    trie->reg[7] = "g";
    trie->reg[8] = "h";
    trie->reg[9] = "i";
    trie->reg[10] = "j";
    trie->reg[11] = "k";
    trie->reg[12] = "l";
    trie->reg[13] = "m";
    trie->reg[14] = "n";
    trie->reg[15] = "o";
    trie->reg[16] = "p";
    trie->reg[17] = "q";
    trie->reg[18] = "r";
    trie->reg[19] = "s";
    trie->reg[20] = "t";
    trie->reg[21] = "u";
    trie->reg[22] = "v";
    trie->reg[23] = "w";
    trie->reg[24] = "x";
    trie->reg[25] = "y";
    trie->reg[26] = "z";

}