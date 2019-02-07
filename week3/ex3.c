#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


/*Refined implementation of the pow-function.*/
double ref_pow(double x, int n){
    if (n == 0)
        return 1;
    double r = ref_pow(x, n/2);
    if ( (n % 2) == 0)
            return r*r;
    else
        return x*r*r;
}


double ticks_to_ms(clock_t tick){
    return ((double) tick)/(CLOCKS_PER_SEC/1000);
}


void main()
{
    double x = 7.0;
    
    /*Measuring efficiency of the standard function*/
    clock_t std_start = clock();
    double pow_std = pow(x,100);
    clock_t std_diff = clock()-std_start;
    
    /*Measuring efficiency of the refined function*/
    clock_t ref_start = clock();
    double pow_ref = ref_pow(x,100);
    clock_t ref_diff = clock()-ref_start;

    /*Converting to milliseconds*/
    double time_std = ticks_to_ms(std_diff);
    double time_ref = ticks_to_ms(ref_diff);
    
    /*Output*/
    printf("pow(%f,100) = %f\n", x, pow_ref);
    printf("Standard function, time elapsed (ms): %f\n", time_std);
    printf("Refined function, time elapsed (ms):  %f\n", time_ref);
    printf("Percentage quicker:                   %.2f%%\n", (time_std/time_ref)*100);

}
