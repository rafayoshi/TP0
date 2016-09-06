#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

arvore *criaArvore(int dicTam)
{
    arvore *trie = (arvore *) malloc(sizeof(arvore ));
    trie->vetorNo = (arvore **) malloc(27 * sizeof(arvore *));
    int i;
    for(i = 1; i <= 26; i++)
    {
        trie->vetorNo[i] = (arvore *) malloc(sizeof(arvore));
    }
    trie->ordem = (vetorOrdem *) malloc((dicTam + 1) * sizeof(vetorOrdem));
    for(i = 0; i < dicTam; i++)
    {
        trie->ordem[i].freq = 0;
        trie->ordem[i].palavraOrdem = malloc(17 * sizeof(char));
    }
    trie->tamanho = dicTam;
    return trie;
}
void criaNo(int posicao, arvore *trie)
{
    trie->vetorNo[posicao] = (arvore *) malloc(sizeof(arvore));
    trie->vetorNo[posicao]->reg = 0;
    trie->vetorNo[posicao]->vetorNo = NULL;
}

arvore *leDicionario()
{
    int dicTam, i = 0;
    size_t palavraTam;
    scanf("%d", &dicTam);
    getchar();
    palavraTam = 16 * dicTam * sizeof(char);
    char *palavra = (char *) malloc(17 * sizeof(char));
    char *buffer = (char *) malloc(palavraTam + 1);
    getline(&buffer, &palavraTam, stdin);
    palavra = strtok(buffer, " ");
    if(palavra[strlen(palavra) - 1] == '\n')
    {
        palavra[strlen(palavra) - 1] = '\0';
    }
    arvore *trie = criaArvore(dicTam);
    char letra;
    while(palavra != NULL)
    {
        letra = separaPalavra(palavra, 0);
        strcpy(trie->ordem[i].palavraOrdem, palavra);
        int j = 0;
        insereNaTrie(trie, palavra, letra, j);
        palavra = strtok(NULL, " ");
        if(palavra != NULL)
        {
            if (palavra[strlen(palavra) - 1] == '\n')
            {
                palavra[strlen(palavra) - 1] = '\0';
            }
        }
        i++;
    }
    free(palavra);
    free(buffer);
    return trie;
}

void insereNaTrie(arvore *trie, char *palavra, char letra, int i)
{
    int posicao;
    if(letra != '\0') {
        posicao = hash(letra);
        if(trie->vetorNo == NULL)
        {
            trie->vetorNo = (arvore **) malloc(27 * sizeof(arvore *));
        }
        if(trie->vetorNo[posicao] == NULL)
        {
            criaNo(posicao, trie);
        }
        trie->vetorNo[posicao]->reg = 1;
        i++;
        letra = separaPalavra(palavra, i);
        insereNaTrie(trie->vetorNo[posicao], palavra, letra, i);
    }
}

void leTexto(arvore *trie)
{
    int texTam;
    size_t palavraTam;
    scanf("%d", &texTam);
    getchar();
    palavraTam = 15 * texTam * sizeof(char);
    char *palavra = (char *) malloc(15 * sizeof(char));
    char *buffer = (char *) malloc(palavraTam);
    getline(&buffer, &palavraTam, stdin);
    palavra = strtok(buffer, " ");
    if(palavra[strlen(palavra) - 1] == '\n')
    {
        palavra[strlen(palavra) - 1] = '\0';
    }
    char letra;
    int j = 0;
    do
    {
        letra = separaPalavra(palavra, 0);
        encontraNaTrie(trie, palavra, letra);
        palavra = strtok(NULL, " ");
        if(palavra == NULL)
        {
            break;
        }
        if(palavra[strlen(palavra) - 1] == '\n')
        {
            palavra[strlen(palavra) - 1] = '\0';
        }
        j++;
    }while(palavra != NULL);
    free(palavra);
    free(buffer);
}

void encontraNaTrie(arvore *trie, char *palavra, char letra)
{
    arvore *sentinela;
    sentinela = trie;
    int i = 1, posicao, posicaoFreq = 0;
    while(strcmp(trie->ordem[posicaoFreq].palavraOrdem, palavra) != 0)
    {
        if(trie->ordem[posicaoFreq + 1].palavraOrdem != NULL)
        {
            posicaoFreq++;
        }
        else
        {
            return;
        }
    }
    while(letra != '\0')
    {
        posicao = hash(letra);
        if(NULL == sentinela->vetorNo)
        {
            return;
        }
        else if(sentinela->vetorNo[posicao]->reg == 0)
        {
            return;
        }
        else if(sentinela->vetorNo[posicao]->reg == 1)
        {
            sentinela = sentinela->vetorNo[posicao];
        }
        letra = separaPalavra(palavra, i);
        i++;
    }
    trie->ordem[posicaoFreq].freq++;
 //   desalocaArvore(sentinela);
}

void desalocaArvore(arvore *trie)
{
    int i;
    for(i = 0; i < 26; i++)
    {
        free(&trie->vetorNo[i]);
    }
            return;
}

char separaPalavra(char *palavra, int i)
{
    char resultado = palavra[i];
    return resultado;
}

int hash(char letra)
{
    int numero = ((int)letra) - 96;
    return numero;
}

void compara(arvore *trie)
{
    int i, j;
    for(i = 0; i < trie->tamanho; i++)
    {
        for(j = i + 1; j < trie->tamanho; j++)
        {
            if (strcmp(trie->ordem[i].palavraOrdem,trie->ordem[j].palavraOrdem) == 0)
            {
                trie->ordem[j].freq = trie->ordem[i].freq;
            }
        }
    }
}

void imprimeResultado(arvore *trie)
{
    int i;
    for(i = 0; i < trie->tamanho; i++)
    {
        printf("%d ", trie->ordem[i].freq);
    }
    printf("\n");
}