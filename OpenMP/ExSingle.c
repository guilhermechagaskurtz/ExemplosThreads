#include <omp.h>
#include <stdio.h>

main () {
     #pragma omp parallel
     {
         printf("Primeiro printf: thread %d\n",omp_get_thread_num());
         
         #pragma omp single
         printf("Segundo printf: thread %d\n",omp_get_thread_num());
         
         printf("Terceiro printf: thread %d\n",omp_get_thread_num());
     }
}
