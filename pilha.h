#ifndef _PILHA_H
#define _PILHA_H
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo { //crio a estrutura do nodo da pilha, que cont�m o valor, o ponteiro para a pr�xima posi��o e para a posi��o anterior.
    int valor;
    struct nodo *proximo;
    struct nodo *anterior;
}nodo;

typedef struct pilha { //aqui, crio a estrutura da pilha, que cont�m um apontador para sua base e topo e um inteiro para medir.
    nodo *base;
    nodo *topo;
    int tamanho;
}pilha;

pilha *criaPilha();

void empilhaElemento(int elemento, pilha *p);

void LiberaPilha(pilha *p);

#endif // _PILHA_H
