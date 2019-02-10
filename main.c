	#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "pilha.h"
#include "funcoes.h"
#define TRUE 1
#define FALSE 0

//Cabecalho para o temporizador
#ifdef _WIN32
#include <time.h>
#else
#include <sys/times.h>
#include <sys/unistd.h>
#endif


//Funcao para calculo do tempo do programa
float getTime() {
#ifdef _WIN32
    clock_t start = clock();
    return (float)start / CLOCKS_PER_SEC;
#else
    struct tms tempo;
    clock_t tempotic;
    float cpt = sysconf(_SC_CLK_TCK);
    times(&tempo);
    tempotic = tempo.tms_utime ;
    return ( (float) (tempotic/cpt) );
#endif
}

int main()
{
	//Variables
	int i = 0;
    int result = 0;
	int num_people = 0;
	int num_relansh = 0;
	int id = 0;
	int idade = 0;
	int pessoa_inicial = 0;
	int v1 = 0;
	int v2 = 0;

	int *vet_id;
	int *vet_idade;
	int *vet_relacao;
	int **matrizrelacao;

	//CALCULO DO TEMPO DE EXECUCAO DO PROGRAMA
    // O tempo eh calculado como a subtracao de dois tempos
    int K = 10000000;
    float s = getTime();
    int* vec = (int*) malloc (K * sizeof(int));
    for (i = 0; i < K; i++) {
        vec[i] = i;
    }
	//Fim da execucao do tempo de programa

	struct pilha *pilha = criaPilha(); //Criacao da pilha

	//Inicio do Programa
	scanf("%d", &num_people); //Leitura do numero de Pessoas
	scanf("%d", &num_relansh); //Leitura do numero de Relacoes entre Pessoas

	vet_idade = (int*)calloc(num_people,sizeof(int)); //Vetor onde armazena as idades
	vet_id = (int*)calloc(num_people,sizeof(int)); //Vetor onde armazena os id
	vet_relacao = (int*)calloc(num_relansh,sizeof(int)); //Vetor onde armazena se a pessoa ja escutou a musica ou seja a relacao ja passou por ela

	matrizrelacao = (int**)calloc(num_people,sizeof(int*)); //Criacao do grafo em memoria dinamica(Matriz adjacente de 2 dimensoes)
	for(i = 0; i < num_people; i++)
	{
		matrizrelacao[i] = (int*)calloc(num_people,sizeof(int));//alocação de uma coluna completa para o grafo; Todo o conteudo inicia com 0, por causa do calloc.
	}


	//Leitura da id e idade, feita numero de pessoas vezes.
	for(i = 0; i < num_people; i++)
	{
		scanf("%d %d", &id, &idade);

		vet_id[i] = id - 1; //Armazenamento das id no vetor, utiliza-se id-1 para as id seguirem em ordem as posicoes de memoria do vetor
		vet_idade[vet_id[i]] = idade; //Armazenamento das idades no vetor
	}

	//Leitura das relacoes entre pessoas, feita numero de relacoes vezes
	//Alem do preenchimento da matriz em relacao aos pesos(idade)
	for(i = 0; i < num_relansh; i++)
	{
		scanf("%d %d", &v1, &v2);

		matrizrelacao[v1-1][v2-1] = TRUE; //Preenchimento do grafo nao-direcional
		matrizrelacao[v2-1][v1-1] = TRUE;
	}

	scanf("%d",&pessoa_inicial);//Leitura de quem foi o primeiro a ouvir a musica
    pessoa_inicial = pessoa_inicial - 1;

    DFS(num_people,pessoa_inicial,pessoa_inicial, matrizrelacao, vet_idade, vet_relacao,pilha);

    //Funcao para contar a pilha.
    result = pilha->tamanho;
    printf("Resultado e: %d", result);
	printf("\nTempo gasto em segundos: %.5fs\n\n", getTime() - s);
	
	//Liberacao da memoria do programa
	LiberaPilha(pilha);
	LiberaMemoria(vet_idade, vet_relacao, vet_id, matrizrelacao,num_people);
	free(vec);
    
	

}//End Main
