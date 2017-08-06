#include <stdio.h>      /* Standard I/O Library: printf */
#include <stdlib.h>     /* Standard Library: malloc, calloc, free, ralloc */
#include <string.h>     /* String funtions: strcpy*/
#include <time.h>

#define MATRIX_SIZE 10000000

int main() {
    
    /* Requesting dynamic memory for space to allocate array 
    arrays are created commonly like array[MATRIX_SIZE]. However
    when MATRIX_SIZE is too large it is neccesary to create it
    as described as follows.
    */
    int * array = (int *) malloc( sizeof(int) * MATRIX_SIZE );

    #pragma acc kernels
    for(int i = 0; i < MATRIX_SIZE; i++) array[i] = 1;

    /* Checking the answer */
    char validation[10];
    strcpy(validation,"Ok");
    for(int i=0;i<MATRIX_SIZE;i++)
        if( array[i] != 1) strcpy(validation, "Fail");

    printf ("\n");
    printf ("Validation: %s \n", validation);
    printf ("Vector size: %d \n", MATRIX_SIZE);

    free(array);

    return EXIT_SUCCESS;
}
