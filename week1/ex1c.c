#include <stdio.h>
#include <time.h>

void main()
{
    int matrix[100][100] = {{0}};
    
    /*Iterating over rows first, then columns.*/
    clock_t start = clock();
    for (int i = 0; i<100; i++){
        for (int j = 0; j<100; j++){
            matrix[i][j] *=1;
        }
    }
    double time_row_major = (double)(clock()-start);
    printf("Row-major order, elapsed time: %f \n", time_row_major);
    

    /*Iterating over columns first, then rows.*/
    start = clock();
    for (int i = 0; i<100; i++){
        for (int j = 0; j<100; j++){
            matrix[j][i] *=1;
        }
    }
    double time_column_major = (double)(clock()-start);
    printf("Column-major order, elapsed time: %f \n", time_column_major);
    
    
    /*Comparing the the order of the iterations.*/
    if (time_column_major < time_row_major){
        printf("Column-major is quicker then row-major.");
    }
    else{
        printf("Row-major is quicker then column-major.");
    }

}
