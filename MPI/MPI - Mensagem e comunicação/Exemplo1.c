#include <mpi.h>
#include <stdio.h>
#include <string.h>
  main(int argc, char* argv[]){
    int tam, meu_rank, origem, dest, tag = 0;		
    char message[100];
    MPI_Status status;
    MPI_Init (&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, & meu_rank);
    MPI_Comm_size(MPI_COMM_WORLD,&tam);
    if (meu_rank != 0){
        sprintf(message, "Saudacoes do processo %d", meu_rank);
        dest = 0;
        MPI_Send(message, strlen(message)+1, MPI_CHAR, dest, tag, MPI_COMM_WORLD);
    }
    else {
        for(origem=1; origem<tam; origem++){
            MPI_Recv(message, 100, MPI_CHAR, origem, tag, MPI_COMM_WORLD, &status);
            printf("Sou o mestre e recebi %s de %d\n", message, origem);
        }
    }
    MPI_Finalize ();
  }
