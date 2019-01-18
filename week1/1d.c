#include <stdio.h>
#include <stdlib.h>

/*Flattening a 3D array into a continguous 1D array storage */

int *make_array(int n_x, int n_y, int n_z)
{
    int *array = malloc(n_x*n_y*n_z*sizeof(int));

    for (int i = 0; i < n_x; i++) {
        for (int j = 0; j<n_y; j++){
            for (int k=0; k<n_z; k++){
                printf("Enter value of u(%d, %d, %d)= ", i, j, k);
                if (scanf("%d", &array[i*n_y*n_z+j*n_z+k]) == 0){
                    printf ("Error.\n");
                }
            }
        }
    }
    printf("Successfully allocated array.\n");
    return array;
}


void print_array(int n_x, int n_y, int n_z, int *array)
{
    for (int i = 0; i < n_x; i++) {
        for (int j = 0; j<n_y; j++){
            for (int k=0; k<n_z; k++){
                printf("u(%d, %d, %d)= %d \n", i, j, k, array[i*n_y*n_z+j*n_z+k]);
            }
        }
    }
}


void free_array(int *array)
{
    free(array);
    printf("Successfully deallocated array.\n");
}



void main()
{
    int *array_3d;
    int n_x = 1;
    int n_y = 2;
    int n_z = 3;
    
    array_3d = make_array(n_x,n_y,n_z);
    print_array(n_x,n_y,n_z,array_3d);
    free_array(array_3d);
    
}
    
    
