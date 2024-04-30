#include <mpi.h>
#include <stdio.h>
#include <string.h>

main(int argc, char* argv[]){
	
	int tam, meu_rank, i ,j;
	MPI_Status status;
	MPI_Init (&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, & meu_rank);
	MPI_Comm_size(MPI_COMM_WORLD,&tam);
	
	float A[10][10];
	MPI_Datatype NOVO_TIPO;
	MPI_Type_vector(10,1,10,MPI_FLOAT, &NOVO_TIPO);
  MPI_Type_commit(&NOVO_TIPO);
    
	if(meu_rank == 0){
	 printf("matriz gerada pelo processo 0 \n");
    for(i=0;i<10;i++){
      for(j=0;j<10;j++){
        A[i][j] = i*j;
        printf("%f ",A[i][j]);
      }
      printf("\n");
    }
    MPI_Send(&(A[0][2]),1,NOVO_TIPO,1,0,MPI_COMM_WORLD);
  }
  
	if (meu_rank == 1){
		printf("Sou o processo 1 e recebi a segunda coluna da matriz:\n");
		MPI_Recv(&(A[0][2]),1,NOVO_TIPO,0,0,MPI_COMM_WORLD,&status);
		for(i=0;i<10;i++){
      printf("%f\n",A[i][2]);
    }
	}
	MPI_Finalize ();
}
