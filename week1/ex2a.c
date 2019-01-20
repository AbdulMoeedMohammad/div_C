#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/*File format:
00:05 -0.1
00:21 0.1
00:29 -0.2
......
*/


/* 
Structure acting as a 2D array with timestamps and temperature measurements.
*/
typedef struct temperature{
	char *time;
	double celcius;
} temperature;


/*
Structure collecting basic statistics.
*/
typedef struct statistics{
	double average;
	double standard_deviation;
	double max_celcius;
	double min_celcius;
	char *max_celcius_time;
	char *min_celcius_time;
} statistics;


/*
Deliberately made one function to compute all the basic statistics in one pass.
*/
struct statistics basic_stats(struct temperature *array, int total){
	struct statistics results;
	double sum;
	double sum_squared;
	double max;
	double min;
	char *max_time;
	char *min_time;
	int i = 0;

	while (i<total){
		sum += array[i].celcius;
		sum_squared += pow(array[i].celcius, 2);
		if (i == 0){
			max = array[i].celcius;
			min = array[i].celcius;
			max_time = array[i].time;
			min_time = array[i].time;
		}
		else{
			if (array[i].celcius > max){
				max = array[i].celcius;
				max_time = array[i].time;
			}
			if (array[i].celcius < min){
				min = array[i].celcius;
				min_time = array[i].time;
			}
		}
		i++;
	}
	results.average = sum/total;
	results.standard_deviation = (sum_squared/total)-pow(results.average, 2);
	results.max_celcius = max;
	results.min_celcius = min;
	results.max_celcius_time = max_time;
	results.min_celcius_time = min_time;
	return results;
}


void main(){
	
	FILE *fr;
    char buff[255];
	
	char *time_string;
	char *celcius_string;
	double celcius_value;
	struct temperature *array;
	int counter;
	
	double average_celcius;
	double sd_celcius;
	struct statistics values;
	
	// Reading data.
	fr = fopen("data.txt", "r");
	array = malloc(10*sizeof(temperature));
	counter = 0;
	
	while (fgets(buff, sizeof(buff), fr) != NULL)
    {
		// Tokenizing on whitespace.
		time_string = strtok(buff," "); 
		celcius_string = strtok(NULL, " ");
		
		// Storing values.
		array[counter].time = strdup(time_string);
		array[counter].celcius = atof(celcius_string);
		
		counter++;
	}
	
	// Printing statistics.
	values = basic_stats(array, counter);
	printf("\nAverage temperature: %f Celcius. \n", values.average);
	printf("Standard deviation: %f Celcius. \n", values.standard_deviation);
	printf("Maximum temperature: %f Celcius at %s o'clock. \n", values.max_celcius, values.max_celcius_time);
	printf("Minimum temperature: %f Celcius at %s o'clock. \n", values.min_celcius, values.min_celcius_time);
	
	fclose(fr);
}


