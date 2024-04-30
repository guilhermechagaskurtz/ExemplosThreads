#include <omp.h>
#include <stdio.h>
main () {
     int i;
     /*o schedule não diz nada em relação ao número de threads que irão executar
     mas sim de quantos em quantos blocos as interações serão divididas
     Ex:para um vetor de 20, com 4 threads e schedule static de 3:
             a thread 0 pega 0,1,2;
             a thread 1 pega 3,4,5;
             a thread 2 pega 6,7,8;
             a thread 3 pega 9,10,11;
             e o ciclo recomeça com a 0 pegando 12,13,14, e assim por diante.
     Quando se utiliza dynamic ao invés de static, divide-se de 3 em 3,
     mas não necessariamente na ordem como mostra o exemplo acima.
     */
     
     //Exemplo de schedule com static 3
     printf("--- static 3 ---\n");     
     #pragma omp parallel for schedule(static,3)
         for (i=0; i < 20; i++){
             int my_rank = omp_get_thread_num();
             printf("(%d)[%d]\n",my_rank,i);
         }
         
     //Exemplo de schedule com dynamic 3
     printf("\n\n--- dynamic 3 ---\n");
     #pragma omp parallel for schedule(dynamic,3)
         for (i=0; i < 20; i++){
             int my_rank = omp_get_thread_num();
             printf("(%d)[%d]\n",my_rank,i);
         }
}
