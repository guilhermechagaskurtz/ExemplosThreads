#include <omp.h>
#include <stdio.h>

void funcao1(){
     printf("Thread %d inicializando for da funcao 1", omp_get_thread_num());
     for(i=0; i<200000000; i++){}
     printf("Thread %d terminando for da funcao 1", omp_get_thread_num());

}
main () {
     int i;
     #pragma omp parallel
     {
         funcao1();
         printf("Thread %d na barreira\n", omp_get_thread_num());
         #pragma omp barrier
         printf("Thread %d saiu da Barreira\n", omp_get_thread_num());
     }
}
