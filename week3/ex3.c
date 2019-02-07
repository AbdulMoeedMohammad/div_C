#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


/*Refined implementation of the pow-function with recursion*/
/*25+4=29 multiplications*/
double sup_pow(double x, int n){
    if (n==1)
        return x*x*x*x;
    else{
        n = n-1;
        x = x*sup_pow(x, n);
    }
}


double ticks_to_ms(clock_t tick){
    return ((double) tick)/(CLOCKS_PER_SEC/1000);
}

void main()
{
    double x = 1337.0;
    
    /*Measuring efficiency of the standard function*/
    clock_t std_start = clock();
    double pow_std = pow(x,100);
    clock_t std_diff = clock()-std_start;
    
    /*Measuring efficiency of the refined function*/
    clock_t sup_start = clock();
    double pow_sup = sup_pow(x,25);
    clock_t sup_diff = clock()-sup_start;
    

    /*Converting to milliseconds*/
    double time_std = ticks_to_ms(std_diff);
    double time_sup = ticks_to_ms(sup_diff);
    
    /*Output*/
    printf("pow(%f,100) = %f\n", x, pow_sup);
    printf("Standard function, time elapsed (ms): %f\n", time_std);
    printf("Refined function, time elapsed (ms):  %f\n", time_sup);
    printf("Percentage quicker:                   %.2f%%\n", (time_std/time_sup)*100);

}
