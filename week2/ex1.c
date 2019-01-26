#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


/*Generating a random string of Norwegian letters*/
char *randomASCII(char *array, int length)
{
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZÆØÅ";
    size_t letters = strlen(alphabet);

    int i = 0;
    while(i<length) {
        array[i] = alphabet[rand() % letters];
        i++;
    }
    return array;
}

/*Converting a character to binary representation*/
int ascii_to_bin(char c)
{
    int ascii_value = (int) c;
    int binary = 0;
    int remainder = 0;
    int i = 1;

    while (ascii_value > 0) {
        binary += i*(ascii_value % 2);
        ascii_value /= 2;
        i *= 10;
    }

    return binary;
}


/*Converting an array of character to binary representation*/
int *randomBinary(char *c_array, int length)
{
    int *bin_array = malloc(length*sizeof(int));
    int i = 0;

    while (i < length) {
        bin_array[i] = ascii_to_bin(c_array[i]);
        i++;
    }
    return bin_array;
}


void main() {

    FILE *fp;
    char *random_string;
    int *random_binary;
    int number_char;
    char buff[255];

    number_char = 100000;
    random_string = malloc((number_char)*sizeof(char));
    random_binary = malloc((number_char)*sizeof(int));

    /*String of random characters.*/
    random_string = randomASCII(random_string, number_char);

    /*Binary representation of the random string*/
    random_binary = randomBinary(random_string, number_char);

    /*Writing ASCII representation*/
    clock_t start_1 = clock();
    fp = fopen("ascii_test.txt", "w+");
    int i = 0;
    while(i < number_char) {
        fprintf(fp, "%c", random_string[i]);
        i++;
    }
    fclose(fp);
    clock_t end_1 = clock();
    printf("Writing ASCII to file, elapsed time: %f \n", (double)(end_1-start_1));

    /*Writing binary representation*/
    clock_t start_2 = clock();
    fp = fopen("binary_test.txt", "w+");
    i = 0;
    while(i < number_char) {
        fprintf(fp, "%d", random_binary[i]);
        i++;
    }
    fclose(fp);
    clock_t end_2 = clock();
    printf("Writing binary to file, elapsed time: %f \n", (double)(end_2-start_2));


    /*Reading ASCII representation*/
    start_1 = clock();
    fp = fopen("ascii_test.txt", "r");
    i = 0;
    while (fgets(buff, sizeof(buff), fp) != NULL)
    {
        //printf("%s", buff);
        i++;
    }
    fclose(fp);
    end_1 = clock();
    printf("Reading ASCII from file, elapsed time: %f \n", (double)(end_1-start_1));


    /*Reading binary representation*/
    start_2 = clock();
    fp = fopen("binary_test.txt", "r");
    i = 0;
    while (fgets(buff, sizeof(buff), fp) != NULL)
    {
        //printf("%d", strtol(buff, NULL, 2));
        i++;
    }
    fclose(fp);
    end_2 = clock();
    printf("Reading binary from file, elapsed time: %f \n", (double)(end_2-start_2));


    free(random_string);
    free(random_binary);
}
