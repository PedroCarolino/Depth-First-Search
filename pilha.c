#include "pilha.h"
#define TRUE 1
#define FALSE 0

pilha *criaPilha()
{ //a função retorna uma pilha criada e vazia.
    pilha *p;
    p = (pilha*)(malloc(sizeof(pilha))); //aloco espaço na memória dinâmica para a estrutura da pilha.
    p->base = NULL; // direciono os ponteiros dela para NULL
    p->topo = NULL;
    p->tamanho = 1;

    return p; //retorno a pilha.
}

void empilhaElemento(int elemento, pilha *p){ //a função empilha o elemento dado na pilha. é do tipo void pois não precisa de retorno.
    nodo *n; //crio e aloco um nodo novo para a pilha.
    n = (nodo*)(malloc(sizeof(nodo)));
    n->valor = elemento; //o valor do nodo será o valor do elemento enviado na função. também direciono os ponteiros dele para NULL.
    n->proximo = NULL;
    n->anterior = NULL;

    if (p->base == NULL) { //caso a pilha estiver vazia, este nodo será sua base e, também, seu topo.
        p->base = n;
        p->topo = n;
    } else {
        n->anterior = p->topo; //caso tenha elementos na pilha, este nodo será organizado de forma a ser o novo topo.
        p->topo->proximo = n;
        p->topo = n;
    }

    p->tamanho++;
    //printf("tamanho da pilha = %d\n", p->tamanho);
    //printf("print pilha = %d\n",p->topo->valor);
}


void LiberaPilha(pilha *p)
{
	nodo* q = p->topo;
	while(p->tamanho != 0)
	{
		p->topo = q->proximo;
		free(q);
		p->tamanho--;
	}
	
}















