#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

typedef struct
{
    char *palavraOrdem;
    int freq;
}vetorOrdem;

typedef struct arvore
{
    int reg, tamanho;
    vetorOrdem *ordem;
    struct arvore *vetorNo;

}arvore;

void desalocaArvore(arvore *);
arvore *criaArvore(int);
arvore *leDicionario();
void insereNaTrie(arvore *, char *, char);
void leTexto(arvore *);
void encontraNaTrie(arvore *, char *, char);
char separaPalavra(char *, int);
void criaNo(int, arvore *);
int hash(char);
void imprimeResultado(arvore *);
#endif