/* Exemplo de divisão de um vetor de tamanho 100 para N processos*/
#include <mpi.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
main(int argc, char* argv[]){
	int tam, meu_rank,i, quemDivide = 0;
	int *vetEnviar;
	int *vetReceber, tamReceber;
	MPI_Status status;
	MPI_Init (&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, & meu_rank);
	MPI_Comm_size(MPI_COMM_WORLD,&tam);
	/*Todos os processos alocam um vetor de tamanho 100/tam, ou seja, 
    se tiverem 5 processos, todos alocam um vetor de tamanho 100/5 = 20 */
	tamReceber = 100/tam;
	vetReceber = (int *)malloc(tamReceber*sizeof(int)); 
	
	/* Se eu sou o processo "quemDivide", aloco um vetor de tamanho 100 e inicializo ele com alguns valores*/
	if(meu_rank==quemDivide){
		vetEnviar = (int *)malloc(100*sizeof(int));
		printf("Processo 0 inicializando:\n");		
		for(i=0;i<100;i++){
			vetEnviar[i]=i+1;
			printf("[%d]",vetEnviar[i]);
		}
		printf("\n");
		
	}
	/* 
    Quais dos processos executam a função abaixo?
    Resposta: todos! A diferença é que:
       - Se eu sou o processo "quemDivide", divido o vetor "vetEnviar" com os outros processos, inclusive comigo mesmo
       - os outros processos recebem suas partes do vetor "vetEnviar" e armazenam essa parte no "vetReceber"
    */
	MPI_Scatter(vetEnviar,tamReceber,MPI_INT,vetReceber,tamReceber,MPI_INT,quemDivide,MPI_COMM_WORLD);
	/*cada um dos processos mostra sua parte do vetor recebida */
	printf("Sou o processo %d e recebi o seguinte vetor:\n",meu_rank);
	for(i=0;i<tamReceber;i++){
		printf("[%d]",vetReceber[i]);		
	}
	printf("\n");
	MPI_Finalize ();
}
