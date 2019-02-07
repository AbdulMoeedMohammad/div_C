#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <inttypes.h>


#ifdef _WIN32
#include <intrin.h>
uint64_t rdtsc(){
    return __rdtsc();
}
#else
uint64_t rdtsc(){
    unsigned int lo,hi;
    __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((uint64_t)hi << 32) | lo;
}
#endif

double numerical_integration (double x_min, double x_max, int slices)
{
	double delta_x = (x_max-x_min)/slices;
	double x, sum = 0.0;
	int i = 0;
	clock_t start = clock();
	while (i<slices){
		x = x_min + (i+0.5)*delta_x;
		st = rdtsc();
		sum = sum + 4.0/(1.0+x*x);
		i++;		
	}
	return sum*delta_x;
}


void main(){
	
	int n = 1000000;
	uint64_t start = rdtsc();
	double pi = numerical_integration(0.0, 1.0, n);
	uint64_t end = rdtsc();
	printf("Approximation of pi: %f\n", pi);
	printf("Total clock cycles: %" PRIu64 "\n", end-start);
	printf("Clock cycles per iterations: %f\n", (double)((end-start)/n));
}
