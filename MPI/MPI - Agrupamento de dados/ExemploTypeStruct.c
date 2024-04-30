#include <mpi.h>
#include <stdio.h>
#include <string.h>
struct ESTRUTURA{
	float a;
	float b;
	int n;
};

main(int argc, char* argv[]){
  struct ESTRUTURA var_struct;
	int tam, meu_rank;
	int block_lenghts[3];
	MPI_Datatype tipos[3];
  MPI_Aint deslocamentos[3];
  MPI_Aint endereco_inicial;
  MPI_Aint endereco;

	MPI_Status status;
	MPI_Init (&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, & meu_rank);
	MPI_Comm_size(MPI_COMM_WORLD,&tam);
	
	block_lenghts[0]=1;
  block_lenghts[1]=1;
  block_lenghts[2]=1;
  
  tipos[0]=MPI_FLOAT;
  tipos[1]=MPI_FLOAT;
  tipos[2]=MPI_INT;

  /*Para o primeiro elemento, a, o deslocamento é 0*/
  deslocamentos[0] = 0;

  /*calcula os deslocamentos das outras variáveis. A função MPI_Address copia o 
  endereço da variável do primeiro argumento para a variavel do segundo argumento.*/
  MPI_Address(&var_struct.a,&endereco_inicial); //copia o endereço de a para endereco_inicial

  /*Busca o endereço de b e calcula seu deslocamento a partir de a*/
  MPI_Address(&var_struct.b,&endereco); //copia o endereço de b para endereco
  deslocamentos[1] = endereco - endereco_inicial; //calcula o deslocamento a partir de a

  /*Busca o endereço de c e calcula seu deslocamento a partir de a*/
  MPI_Address(&var_struct.n,&endereco); //copia o endereço de n para endereco
  deslocamentos[2] = endereco - endereco_inicial; //calcula o deslocamento a partir de a

  /*Cria o novo tipo de dado*/
  MPI_Datatype NOVO_TIPO;
  MPI_Type_struct(3,block_lenghts,deslocamentos,tipos,&NOVO_TIPO);
  MPI_Type_commit(&NOVO_TIPO);
    
	if(meu_rank==0){
    var_struct.a = 0.0;
    var_struct.b = 1.0;
    var_struct.n = 1024;
  }
  
	MPI_Bcast(&var_struct,1,NOVO_TIPO,0,MPI_COMM_WORLD); //processo 0 manda a estrutura para todos os outros
	if (meu_rank != 0){
		printf("Sou o %d e recebi do processo 0: %f, %f e %d\n",meu_rank,var_struct.a,var_struct.b,var_struct.n);
	}
	MPI_Finalize ();
}
