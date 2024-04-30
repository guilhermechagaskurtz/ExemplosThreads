#include <mpi.h>
#include <stdio.h>
#include <string.h>
main(int argc, char* argv[]){
    int tam, meu_rank, tag=0, *vet;
    MPI_Status status;
    MPI_Init (&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &meu_rank);
    MPI_Comm_size(MPI_COMM_WORLD,&tam);
    vet = (int*) malloc (5*sizeof(int));
    if (meu_rank == 0){
        for(i=0;i<5;i+) vet[i]=i;
        for(i=1;i<tam;i++) MPI_Send(vet, 5, MPI_INT, i, tag, MPI_COMM_WORLD);
    } 
    else {
        MPI_Recv(vet, 5, MPI_INT, 0, tag, MPI_COMM_WORLD, &status);
        printf("\nrecebi do mestre o vetor:");
        for(i=0; i<5; i++) printf("%d ", vet[i]);
    }
    MPI_Finalize ();
}
