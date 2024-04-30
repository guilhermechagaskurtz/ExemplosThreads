#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char* argv[]) {
    
    printf("Hello World (sequencial)!!!\n");

    # pragma omp parallel
    printf("Hello World (paralelo)!!!\n");

    return 0;
}
