#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*Initializing a random array*/
int *randomArray(int* array, int length)
{
    for(int i=0; i<length; i++){
        array[i] = rand();
    }
    return array;
}


void main()
{
    
    int *array1 = malloc(1000*sizeof(int));
    int *array2 = malloc(1000*sizeof(int));
    
    array1 = randomArray(array1, 1000);
    array2 = randomArray(array1, 1000);
    
    /*Copying the arrays elementwise*/
    clock_t start = clock();
    for(int j = 0; j<1000; j++){
        array1[j] = array2[j];
    }
    double time_elementwise = (double)(clock()-start);
    printf("Copying elementwise, elapsed time: %d \n", time_elementwise);
    
    /*Copying using memcpy*/
    start = clock();
    memcpy(array1, array2, sizeof(int)*1000);
    double time_memcpy = (double)(clock()-start);
    printf("Copying mempy, elapsed time: %d \n", time_memcpy);

    
}
