#include <omp.h>
#include <stdio.h>
main () {
     int i;
     #pragma omp parallel for
         for (i=0; i < 20; i++){
             int my_rank = omp_get_thread_num();
             printf("(%d)[%d]\n",my_rank,i);
         }
}
