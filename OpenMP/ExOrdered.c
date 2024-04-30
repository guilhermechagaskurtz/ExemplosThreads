#include <omp.h>
#include <stdio.h>
main () {
     int i;
     printf("FOR SEM ORDERED\n");
     #pragma omp parallel for
     for (i=0; i < 20; i++){
         int my_rank = omp_get_thread_num();
         int thread_count = omp_get_num_threads();
         printf("(%d)[%d]\n",my_rank,i);
     }
     
     printf("\n\nFOR COM ORDERED\n");
     #pragma omp parallel for ordered /*schedule(dynamic,2)*/
     for (i=0; i < 20; i++){
         int my_rank = omp_get_thread_num();
         int thread_count = omp_get_num_threads();
         #pragma omp ordered
         printf("(%d)[%d]\n",my_rank,i);
     }
}
