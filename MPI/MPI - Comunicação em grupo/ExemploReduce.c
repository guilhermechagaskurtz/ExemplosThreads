#include <mpi.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
main(int argc, char* argv[]){
	int tam, meu_rank,i, quemRecebe=0;
	int *vetEnviar;
	int *vetOperandos, *vetResultado;
	MPI_Status status;
	MPI_Init (&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, & meu_rank);
	MPI_Comm_size(MPI_COMM_WORLD,&tam);
	/*Todos os processos alocam um vetor de tamanho 10*/
	tam = 10;
	vetOperandos = (int *)malloc(tam*sizeof(int));
	printf("Processo %d gerando vetor\n",meu_rank);
	/*Todos os processos inicializam este vetor*/
	for(i=0;i<tam;i++){
		vetOperandos[i] = meu_rank*i;
		printf("[%d]",vetOperandos[i]);	
	}
	printf("\n");
	/*Se eu sou o processo "quemRecebe", inicializo um outro vetor vetResultado, este
	que irá armazenar o resultado da soma dos valores de cada posicao de vetOperandos*/
	if(meu_rank==quemRecebe){
		vetResultado = (int *)malloc(tam*sizeof(int));	
	}
	/* 
    Quais dos processos executam a função abaixo?
    Resposta: todos! A diferença é que:
       - Se eu sou o processo "quemRecebe", executo para somar cada posicao dos vetores vetOperandos dos outros processos e armazenar o resultado em vetResultado.
       - os outros processos executam para enviar suas partes do vetor "vetOperandos" para o processo "quemRecebe" poder realizar a operação de soma (MPI_SUM)
    */
	MPI_Reduce(vetOperandos,vetResultado,tam,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD); 
	/*
	Processo "quemRecebe" mostra o resultado da soma de cada posicao de vetOperandos no vetor vetResultado
	*/
	if(meu_rank==quemRecebe){
		printf("Sou o processo 0 e o resultado da soma das posicoes de cada vetor é vetor:\n");
		for(i=0;i<10;i++){
			printf("[%d]",vetResultado[i]);		
		}
	}
	printf("\n");
	MPI_Finalize ();
}
