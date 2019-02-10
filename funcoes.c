#include "funcoes.h"
#include "pilha.h"

void DFS(int num_pessoas,int linha,int pessoa_inicial, int **matriz, int *vet_idade, int *vet_relacao, pilha *pilha)
{
    int j;
    vet_relacao[linha] = 1;

    for(j = 0; j < num_pessoas; j++)
    {
		printf("matrizA[%d][%d] = [%d]\n", linha, j, matriz[linha][j]);
        if(vet_idade[j] < 35 && matriz[linha][j] == 1)
        {
            if(vet_relacao[j] == 0)
            {
				printf("matrizD[%d][%d] = [%d]\n", linha, j, matriz[linha][j]);
                empilhaElemento(linha,pilha);
                DFS(num_pessoas,j,pessoa_inicial, matriz, vet_idade, vet_relacao,pilha); //Busca em Profundidade
            }
        }
    }
}

//Funcao que verifica se a pessoa ja ouviu a musica ou nao
//Se ela já tive ouvido a musica retorna 1, se nao retorna 0
int verifica(int pessoa_inicial, int *vet_relacao)
{
    if(vet_relacao[pessoa_inicial] != 0)
    {
        return 1;//RETORNAR TRUE QUER DIZER QUE ESSA PESSOA JA FOI CONTADA
    }
    else
    {
        vet_relacao[pessoa_inicial] = 1;
        return 0;//RETORNAR FALSE QUER DIZER QUE ESSA PESSOA NAO FOI CONTADA AINDA
    }
}

void LiberaMemoria(int *vet_idade, int *vet_relacao, int *vet_id, int **matriz, int num_pessoas)
{
	int i = 0;
	
	free(vet_idade);
	free(vet_relacao);
	free(vet_id);
 	for(i=0;i<=num_pessoas;i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}
