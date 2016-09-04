#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

typedef struct arvore
{
    int ordem, reg;
    int *vetorFreq;
    struct arvore *vetorNo;

}arvore;

arvore *criaArvore(int);
arvore *leDicionario(int *);
void insereNaTrie(arvore *, char *, char, int *);
void leTexto(arvore *);
void encontraNaTrie(arvore *, char *, char);
char separaPalavra(char *, int);
void criaNo(int, arvore);
int hash(char);
void imprimeResultado(arvore, int);
#endif