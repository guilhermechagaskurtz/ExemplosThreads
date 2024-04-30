#include <mpi.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
main(int argc, char* argv[]){
	int tam, meu_rank,i, quemRecebeAsPartes=0;
	int *vetEnviar;
	int *vetReceber, tamEnviar;
	MPI_Status status;
	MPI_Init (&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, & meu_rank);
	MPI_Comm_size(MPI_COMM_WORLD,&tam);
	/*Todos os processos alocam um vetor de tamanho 100/tam, ou seja, 
	se tiverem 5 processos, todos alocam um vetor de tamanho 100/5 = 20 
	Todos alocam pois cada uma das partes de 20 elementos sera reunida 
	em um único vetor de tamanho 100 no processo "quemRecebeAsPartes"*/
	tamEnviar = 100/tam;
	vetEnviar = (int *)malloc(tamEnviar*sizeof(int));	
	/* Todos os processos inicializam seu vetor de tamanho 100/tam com valores aleatorios*/
	printf("Processo %d gerando vetor parcial\n",meu_rank);
	for(i=0;i<tamEnviar;i++){
		vetEnviar[i] = meu_rank*i;	
	}
	/* Se eu sou o processo "quemRecebeAsPartes" eu aloco um vetor de tamanho 100
	para juntar todos os vetores de tamanho 100/tam neste único vetor grande	
	*/
	if(meu_rank==quemRecebeAsPartes){
		vetReceber = (int *)malloc(100*sizeof(int));
	}
	/* 
    Quais dos processos executam a função abaixo?
    Resposta: todos! A diferença é que:
       - Se eu sou o processo "quemRecebeAsPartes", executo para receber cada um dos "tam" vetores "vetEnviar" dos outros processos, inclusive inclusive o próprio.
       - os outros processos executam para enviar suas partes do vetor "vetEnviar" e acrescentá-la no vetor "vetReceber"
    */
	MPI_Gather(vetEnviar,tamEnviar,MPI_INT,vetReceber,tamEnviar,MPI_INT,quemRecebeAsPartes,MPI_COMM_WORLD); 
	/*
	Se eu sou o processo "quemRecebeAsPartes" mostra o vetor resultante
	da união de todos os vetEnviar dos outros processos
	*/
	if(meu_rank==quemRecebeAsPartes){
		printf("Sou o processo 0 e recebi o seguinte vetor:\n");
		for(i=0;i<100;i++){
			printf("[%d]",vetReceber[i]);		
		}
	}
	printf("\n");
	MPI_Finalize ();
}
