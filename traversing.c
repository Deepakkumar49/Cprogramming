// Write a program to read and display n numbers using an array.

#include<stdio.h>
int main(){
    int n,arr[20];
 
    // taking n value 
    printf("Enter the size of arrays:");
    scanf("%d",&n);

    //reading arrays element
 
    printf("Enter the element:");
    for(int i=0;i<n;i++){
        printf("\n arr[%d]=",i);
        scanf("%d",&arr[i]);
    }
    
    //display elements

    printf("Element of arrays are:");
     for(int i=0;i<n;i++){
        printf("\t %d",arr[i]);
    }
    return 0;
}