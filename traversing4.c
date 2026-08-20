//Write a program to find the second largest of n numbers using an arrays.

#include<stdio.h>
int main(){
    int i,n,arr[20],largest,second_larger,pos;

    printf("Enter the no of element:");
    scanf("%d",&n);

    for ( i = 0; i < n; i++)
    {
        printf("arr[%d]=",i);
        scanf("%d",&arr[i]);
    }
    largest=arr[0];
    pos=0;

    for ( i = 1; i < n; i++)
    {
        if (largest<arr[i])
        {
            largest=arr[i];
            pos=i;
        }
        
    }
    second_larger=arr[1];
    for ( i = 0; i < n; i++)
    {
        if(arr[i]!=largest){
            if(arr[i]>second_larger){
                second_larger=arr[i];
            }
        }
    }
    
    printf("Second largest no is:%d\n",second_larger);
    printf("Position of no:%d\n",i);
    return 0;
}