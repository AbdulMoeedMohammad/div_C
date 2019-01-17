#include <stdio.h>

void main(){
    
    int n;
    int max;
    int min;
    
    printf("Enter length of array: ");
    scanf("%d",&n);
    
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
