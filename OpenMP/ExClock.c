#include <omp.h>
#include <stdio.h>
#include <sys/time.h>
main () {
     struct timeval inicio, final;
     double Segundos, Milissegundos, Microssegundos;
     gettimeofday(&inicio, NULL);
     #pragma omp parallel for
     for(int i=0; i<900000000; i++){
              for(int j=0; j<3; j++){
              }
     }
     gettimeofday(&final, NULL);
     
     printf("Inicio:\t%ld:%ld\n\n",inicio.tv_sec,inicio.tv_usec);
     printf("Fim:\t%ld:%ld\n\n",final.tv_sec,final.tv_usec);     
     Segundos = final.tv_sec - inicio.tv_sec;
     Microssegundos = final.tv_usec - inicio.tv_usec;
     Milissegundos = Segundos * 1000 + Microssegundos / 1000;
     printf("Segundos: %f\nMicrossegundos: %f\n\nMilissegundos: %f",Segundos,Microssegundos,Milissegundos);
}
