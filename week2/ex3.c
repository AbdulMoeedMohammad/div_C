#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/*Function for initializing the v-array*/
double *make_array(int n_x, int n_y, int n_z)
{
   double *array = malloc(n_x*n_y*n_z*sizeof(double));

    for (int i = 0; i < n_x; i++) {
        for (int j = 0; j<n_y; j++){
            for (int k=0; k<n_z; k++){
                array[i*n_y*n_z + j*n_z + k] = 2.0+sin((i*j*k*acos(-1))/((n_x-1)*(n_y-1)*(n_z-1)));
            }
        }
    }
    printf("Successfully allocated array.\n");
    return array;
}

/*Printing the values of the array*/
void print_array(int n_x, int n_y, int n_z, double *array)
{
    for (int i = 0; i < n_x; i++) {
        for (int j = 0; j<n_y; j++){
            for (int k=0; k<n_z; k++){
                printf("u(%d, %d, %d)= %f \n", i, j, k, array[i*n_y*n_z+j*n_z+k]);
            }
        }
    }
}


/*Computation*/
void computation_arrays(int n_x, int n_y, int n_z, double *array_u, double *array_v)
{
    for (int i = 1; i < n_x-2; i++) {
        for (int j = 1; j<n_y-2; j++){
            for (int k=1; k<n_z-2; k++){
                array_u[i*n_y*n_z+j*n_z+k] = array_v[i*n_y*n_z+j*n_z+k] + (
                    array_v[(i-1)*n_y*n_z+j*n_z+k]+array_v[i*n_y*n_z+(j-1)*n_z+k]+
                    array_v[(i-1)*n_y*n_z+j*n_z+(k+1)]-6*array_v[(i-1)*n_y*n_z+j*n_z+k]+
                    array_v[(i+1)*n_y*n_z+j*n_z+k]+array_v[i*n_y*n_z+(j+1)*n_z+k]+
                    array_v[i*n_y*n_z+j*n_z+(k+1)])/6;
            }
        }
    }
}



void free_array(double *array)
{
    free(array);
    printf("Successfully deallocated array.\n");
}



void main()
{
    double *array_u;
    double *array_v;
    int n_x = 4;
    int n_y = 5;
    int n_z = 6;
    
    /*Initializing array u with zeroes*/
    array_u = malloc(n_x*n_y*n_z*sizeof(double));
    memset(array_u, 0.0, n_x*n_y*n_z*sizeof(double));
    
    /*Initializing array v*/
    array_v = make_array(n_x,n_y,n_z);
    
    /*Performing the computation*/
    computation_arrays(n_x, n_y, n_z, array_u, array_v);
    
    /*Printing the results*/
    print_array(n_x, n_y, n_z, array_u);
    
    /*Freeing the allocated memory*/
    free_array(array_u);
    free_array(array_v);
    
}
