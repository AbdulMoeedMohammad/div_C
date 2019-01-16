/* Q: prescribed at runtime? */


#include <stdio.h>

void main(){
    
    int n = 10;
    int max = 0;
    int min = 0;
    
    int a[n];
    
    for (int i=0; i<n; i++){
        a[i] = rand();
        
        if (i == 0){
            max = a[i];
            min = a[i];
        }
        else{
            if (a[i]>max){
                max = a[i];
            }
            if (a[i]<min){
                min = a[i];
            }
        }
    }
    
    printf("Minimum value: %d \n", min);
    printf("Maximum value: %d", max);

}
