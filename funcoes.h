#ifndef _FUNCOES_H
#define _FUNCOES_H
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void DFS(int num_pessoas, int linha,int pessoainicial, int **matriz, int *vet_idade, int *vet_relacao, pilha *pilha);

int verifica(int pessoa_inicial, int *vet_relacao);

void LiberaMemoria(int *vet_idade, int *vet_relacao, int *vet_id, int **matriz,int num_pessoas); 


#endif // _PILHA_H
