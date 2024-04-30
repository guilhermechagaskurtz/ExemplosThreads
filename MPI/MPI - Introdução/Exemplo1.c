#include <mpi.h>
#include <stdio.h>
#include <string.h>
  main(int argc, char* argv[]){
		int tam, meu_rank;
		MPI_Status status;
		MPI_Init (&argc, &argv);
		MPI_Comm_rank(MPI_COMM_WORLD, & meu_rank);
		MPI_Comm_size(MPI_COMM_WORLD,&tam);
		printf("Hello world, estou sendo executado pelo processo %d de um total de %d processos\n", meu_rank, tam);
	    MPI_Finalize ();
  }
