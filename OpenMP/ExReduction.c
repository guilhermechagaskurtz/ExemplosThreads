#include <omp.h>
#include <stdio.h>
#define N 10
main () {
     int i, A[N], soma;
     for(i=0; i<N; i++){
         A[i]=i+1;
     }
     printf("--- sem reduction ---\n");
     soma=0;
     #pragma omp parallel for
         for (i=0; i < N; i++){
             soma+=A[i];
         }
     printf("Resultado da soma sem reduction: %d",soma);
     
     
     printf("\n\n\n--- com reduction ---\n");
     /*A redução definira o valor final da soma:
       soma(final) = soma(inicial) + soma(t0) + soma(t1) + soma(t2) + soma(t3) +...
       */  
     soma=0;
     #pragma omp parallel for reduction(+:soma)
         for (i=0; i < N; i++){
             soma+=A[i];
         }
     printf("Resultado da soma com reduction: %d",soma);
}
