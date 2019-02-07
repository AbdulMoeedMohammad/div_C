#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


/*Refined implementation of the pow-function with recursion*/
/*100 multiplications*/
double ref_pow(double x, int n){
    if (n==1)
        return x;
    else{
        n = n-1;
        x = x*ref_pow(x, n);
    }
}



/*Refined implementation of the pow-function with recursion*/
/*25+4=29 multiplications*/
double sup_pow(double x, int n){
    if (n==1)
        return x*x*x*x;
    else{
        n = n-1;
        x = x*ref_pow(x, n);
    }
}


double ticks_to_ms(clock_t tick){
    return ((double) tick)/(CLOCKS_PER_SEC/1000);
}

void main()
{
    double x = 1337.0;
    double power;
    
    /*Measuring efficiency of the standard function*/
    clock_t std_start = clock();
    power = pow(x,100);
    clock_t std_diff = clock()-std_start;
    
    /*Measuring efficiency of the refined function*/
    clock_t ref_start = clock();
    power = ref_pow(x,100);
    clock_t ref_diff = clock()-ref_start;
    
    
    /*Measuring efficiency of the refined function*/
    clock_t sup_start = clock();
    power = ref_pow(x,25);
    clock_t sup_diff = clock()-sup_start;
    
    
    /*Converting to milliseconds*/
    double time_std = ticks_to_ms(std_diff);
    double time_ref = ticks_to_ms(ref_diff);
    double time_sup = ticks_to_ms(sup_diff);
    
    
    printf("Standard function, time elapsed (ms): %f\n", time_std);
    printf("Refined function, time elapsed (ms):  %f\n", time_ref);
    printf("Super function, time elapsed (ms):    %f\n", time_sup);

}
