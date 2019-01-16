/* Sum of an infinite geometric series with initial value a_0 and quotient k, up to error e */

void main(){
    
    double a_0 = 1;
    double sum;
    double k = -0.25;
    double e = 1e-5;
    double limit = 0.8;
    
    while ((fabs(sum-limit)) >= e){
        sum += a_0;
        a_0 *= k;
    }
    
    printf("%6f", sum);

}
