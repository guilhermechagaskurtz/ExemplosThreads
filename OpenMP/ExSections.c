#include <omp.h>
#include <stdio.h>
main () {
    #pragma omp parallel sections
    {
        #pragma omp section
        {
            /* Uma thread faz isso */
            printf ("Funcao 1: id = %d, \n", omp_get_thread_num());
        }
         
        #pragma omp section
        {
            /* Outra thread faz isso */
            printf ("Funcao 2: id = %d, \n", omp_get_thread_num());
        }
         
        #pragma omp section
        {
            /* E outra faz isso */
            printf ("Funcao 3: id = %d, \n", omp_get_thread_num());
        } 
    
    }
}
