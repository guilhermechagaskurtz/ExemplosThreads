#include <mpi.h>
#include <stdio.h>
#include <string.h>

main(int argc, char* argv[]){
	float a;
	float b;
	int n;
	
	char buffer[100];
	int position;
	
	int tam, meu_rank;
	
	MPI_Status status;
	MPI_Init (&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, & meu_rank);
	MPI_Comm_size(MPI_COMM_WORLD,&tam);

	if(meu_rank == 0){
    a = 1.7;
    b = 2.8;
    n = 150;
    position=0;
    MPI_Pack(&a,1,MPI_FLOAT,buffer,100,&position,MPI_COMM_WORLD);
    MPI_Pack(&b,1,MPI_FLOAT,buffer,100,&position,MPI_COMM_WORLD);
    MPI_Pack(&n,1,MPI_INT,buffer,100,&position,MPI_COMM_WORLD);
    MPI_Send(buffer,100,MPI_PACKED,1,0,MPI_COMM_WORLD);
    
    a=1.7;
    b=2.8;
    n=150;
    /*agora come�aremos a �empacotar�. Primeiro dizemos que vamos come�ar colocando os dados no in�cio do buffer, na posi��o 0*/
    position=0;

    /*e empacotamos a primeira vari�vel */
    MPI_Pack(&a,1,MPI_FLOAT,buffer,100,&position,MPI_COMM_WORLD);
    
    /*a vari�vel position se desloca automaticamente, ou seja, ela esta agora �apontando� para a pr�xima posi��o livre do buffer. Portanto, podemos empacotar os pr�ximos elemento*/
    MPI_Pack(&b,1,MPI_FLOAT,buffer,100,&position,MPI_COMM_WORLD);
    MPI_Pack(&n,1,MPI_INT,buffer,100,&position,MPI_COMM_WORLD);
    
    /*E agora o processo 0 pode enviar os dados empacotados para o processo 1*/
    MPI_Send(buffer,100,MPI_PACKED,1,0,MPI_COMM_WORLD);

  }
  
  else if(meu_rank == 1){

    /*Processo 1 recebe a mensagem empacotada e armazena em buffer*/
    MPI_Recv(buffer,100,MPI_PACKED,0,0,MPI_COMM_WORLD, &status);

    /*Processo 1 desempacota as mensagens, vari�vel por vari�vel. Logo, position deve ser zerado novamente*/
    position=0;
    MPI_Unpack(buffer,100,&position,&a,1,MPI_FLOAT,MPI_COMM_WORLD);

    /*Novamente position � incrementado automaticamente, logo, podemos desempacotar as outras vari�veis:*/
    MPI_Unpack(buffer,100,&position,&b,1,MPI_FLOAT,MPI_COMM_WORLD);
    MPI_Unpack(buffer,100,&position,&n,1,MPI_INT,MPI_COMM_WORLD);
    
    printf("Recebi %f, %f e %d\n",a,b,n);
  }

	MPI_Finalize ();
}
