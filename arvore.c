#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

arvore *criaArvore(int dicTam)
{
    arvore *trie;
    arvore **vetorNo = (arvore **) malloc(27 * sizeof(arvore *));
    int i;
    for(i = 1; i <= 26; i++)
    {
        vetorNo[i] = NULL;
    }
    trie = (arvore *) malloc(sizeof(arvore));
    trie->vetorFreq = (int *) malloc(dicTam * sizeof(int));
    for(i = 0; i < dicTam; i++)
    {
        trie->vetorFreq[i] = 0;
    }
    trie->vetorNo = *vetorNo;
    trie->tamanho = dicTam;
    free(vetorNo);
    return trie;
}
void criaNo(int posicao, arvore *trie)
{
    trie->vetorNo = (arvore *) malloc(27 * sizeof(arvore));
    arvore **novoNo;
    novoNo = (arvore **) malloc(27 * sizeof(arvore *));
    novoNo[posicao] = (arvore *) malloc(sizeof(arvore));
    trie->vetorNo = (arvore *) novoNo;
    free(novoNo);
}

arvore *leDicionario(int *ordem)
{
    int dicTam;
    size_t palavraTam;
    scanf("%d", &dicTam);
    getchar();
    palavraTam = 16 * dicTam * sizeof(char);
    char *palavra = (char *) malloc(16 * sizeof(char));
    char *buffer = (char *) malloc(palavraTam);
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
        insereNaTrie(trie, palavra, letra, ordem);
        palavra = strtok(NULL, " ");
        if(palavra != NULL)
        {
            if (palavra[strlen(palavra) - 1] == '\n')
            {
                palavra[strlen(palavra) - 1] = '\0';
            }
        }
    }
    free(palavra);
    free(buffer);
    return trie;
}

void insereNaTrie(arvore *trie, char *palavra, char letra, int *ordem)
{
    int i = 1,  posicao;
    while(letra != '\0')
    {
        posicao = hash(letra);
        if(trie->vetorNo == NULL)
        {
            criaNo(posicao, trie);
            trie->vetorNo[posicao].reg = 1;
            trie->vetorNo[posicao].ordem = *ordem;
        }
        else if(trie->vetorNo[posicao].reg == 0)
        {
            trie->vetorNo[posicao].reg = 1;
            trie->vetorNo[posicao].ordem = *ordem;
        }
        trie = &trie->vetorNo[posicao];
        letra = separaPalavra(palavra, i);
        i++;
    }
    ordem++;
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
    if(palavra[strlen(palavra)] == '\n')
    {
        palavra[strlen(palavra) - 1] = '\0';
    }
    char letra;
    while(palavra != NULL)
    {
        letra = separaPalavra(palavra, 0);
        encontraNaTrie(trie, palavra, letra);
        palavra = strtok(NULL, " ");
        if(palavra[strlen(palavra)] == '\n')
        {
            palavra[strlen(palavra) - 1] = '\0';
        }
    }
    free(palavra);
    free(buffer);
}

void encontraNaTrie(arvore *trie, char * palavra, char letra)
{
    arvore *sentinela;
    sentinela = malloc(sizeof(trie));
    sentinela = trie;
    int i = 1, posicao, contador = 0;
    while(letra != '\0')
    {
        posicao = hash(letra);
        if(NULL == sentinela->vetorNo)
        {
            trie->vetorFreq[sentinela->ordem] = contador;
            return;
        }
        else if(sentinela->vetorNo[posicao].reg == 0)
        {
            trie->vetorFreq[sentinela->ordem] = contador;
            return;
        }
        else if(sentinela->vetorNo[posicao].reg == 1)
        {
            contador++;
            sentinela = &sentinela->vetorNo[posicao];
        }
        i++;
        letra = separaPalavra(palavra, i);
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

void imprimeResultado(arvore trie, int dicTam)
{
    int i;
    for(i = 0; i < dicTam; i++)
    {
        printf("%d ", trie.vetorFreq[i]);
    }
    printf("\n");
}