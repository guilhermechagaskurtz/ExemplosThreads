#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int variavel_global=0;

void soma_id(void) {
     int my_rank = omp_get_thread_num();
     int thread_count = omp_get_num_threads();

     # pragma omp critical
     variavel_global+=my_rank;
     
}

int main(int argc, char* argv[]) {

    # pragma omp parallel num_threads(101)
    soma_id();
    
    printf("A soma dos ids eh %d",variavel_global);
    return 0;
}

