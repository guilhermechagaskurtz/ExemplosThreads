#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


int main(int argc, char* argv[]) {

    int i=0;
    //i � compartilhado por default, mas podemos deixar expl�cito
    # pragma omp parallel num_threads(101) shared(i)
    {
             i++;
    }
    //neste caso, qual ser� o valor final de i??    
    printf("Valor final de i (shared): %d\n",i);
    
    i=0;
    //i � compartilhado por default, mas podemos modificar e torn�-lo privado
    # pragma omp parallel num_threads(101) private(i)
    {
             i++;
    }
    //neste caso, qual ser� o valor final de i??
    printf("Valor final de i (private): %d",i);
    return 0;
}

