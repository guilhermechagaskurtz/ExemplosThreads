#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


int main(int argc, char* argv[]) {

    int i=0;
    //i é compartilhado por default, mas podemos deixar explícito
    # pragma omp parallel num_threads(101) shared(i)
    {
             i++;
    }
    //neste caso, qual será o valor final de i??    
    printf("Valor final de i (shared): %d\n",i);
    
    i=0;
    //i é compartilhado por default, mas podemos modificar e torná-lo privado
    # pragma omp parallel num_threads(101) private(i)
    {
             i++;
    }
    //neste caso, qual será o valor final de i??
    printf("Valor final de i (private): %d",i);
    return 0;
}

