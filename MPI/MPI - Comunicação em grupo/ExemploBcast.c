#include <mpi.h>
#include <stdio.h>
#include <string.h>
main(int argc, char* argv[]){
	int tam, meu_rank,quemEnvia=2;
	float k;
	MPI_Status status;
	MPI_Init (&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, & meu_rank);
	MPI_Comm_size(MPI_COMM_WORLD,&tam);
	//se eu sou o processo "quemEnvia", digo que PARA MIM o k vale 20
	if(meu_rank == quemEnvia){		
        k = 20;
    }
    /*
    Quais dos processos executam a fun��o abaixo?
    Resposta: todos! A diferen�a � que:
        - o processo "quemEnvia" executa para enviar a vari�vel k a todos os outros;
        - os outros processos executam para receber a vari�vel k do processo "quemEnvia"
    */
	MPI_Bcast(&k,1,MPI_FLOAT,quemEnvia,MPI_COMM_WORLD); 
	//se eu N�O sou o processo "quemEnvia", mostro o valor de k que recebi
	if (meu_rank != quemEnvia){
		printf("Sou o %d e recebi do processo %d a variavel k = %f\n",meu_rank,quemEnvia,k);
	}
	MPI_Finalize ();
}
