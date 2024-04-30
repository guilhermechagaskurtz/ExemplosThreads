#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


void Hello(void) {
     int my_rank = omp_get_thread_num();
     int thread_count = omp_get_num_threads();

     printf("Hello World da thread %d de %d \n\n", my_rank, thread_count);
}

int main(int argc, char* argv[]) {

    # pragma omp parallel num_threads(8)
    Hello();
    return 0;
}

