#include <omp.h>
#include <stdio.h>

main () {
     int i;
     #pragma omp parallel
     {
         #pragma omp for nowait
         for(i=0; i<20; i++){
                  printf("(%d)[%d]\n",omp_get_thread_num(),i);
         }
         printf("Thread %d continuou sem esperar pelas outras",omp_get_thread_num());
     }
}
