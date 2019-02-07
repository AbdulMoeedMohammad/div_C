#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


/*Refined implementation of the pow-function with recursion*/
double ref_pow(double x, int n){
    if (n==1)
        return x;
    else{
        n = n-1;
        x = x*ref_pow(x, n);
    }
}


void main()
{
    double x = 1337.0;
    double std_pow;
    double refined_pow;
    
    /*Measuring efficiency of the standard function*/
    clock_t std_start = clock();
    std_pow = pow(x,100);
    clock_t std_diff = clock()-std_start;
    
    /*Measuring efficiency of the refined function*/
    clock_t ref_start = clock();
    refined_pow = ref_pow(x,100);
    clock_t ref_diff = clock()-ref_start;
    
    /*Converting to milliseconds*/
    double time_std = ((double)std_diff)/(CLOCKS_PER_SEC/1000);
    double time_ref = ((double)ref_diff)/(CLOCKS_PER_SEC/1000);
    
    printf("Standard function, time elapsed (ms): %f\n", time_std);
    printf("Refined function, time elapsed (ms): %f\n", time_ref);
    if (time_std > time_ref)
        printf("The refined function is quicker.\n");
    else
        printf("The standard function is quicker.\n");
    printf("Time difference (ms): %f", fabs(time_std-time_ref));

}
