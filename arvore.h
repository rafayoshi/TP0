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
    struct arvore **vetorNo;

}arvore;

void desalocaArvore(arvore *);
arvore *criaArvore(int);
arvore *leDicionario();
void insereNaTrie(arvore *, char *, char, int);
void leTexto(arvore *);
void encontraNaTrie(arvore *, char *, char);
void compara(arvore *);
char separaPalavra(char *, int);
void criaNo(int, arvore *);
int hash(char);
void imprimeResultado(arvore *);
#endif