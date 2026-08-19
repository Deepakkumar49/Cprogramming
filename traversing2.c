//Write a program to find the mean of n numbers using arrays.
#include<stdio.h>
int main(){
    int i,n,arr[20];

    //taking number of element 
    printf("Enter the number of element:");
    scanf("%d",&n);

    //Enter the element 
    printf("Enter the element:\n");
    for(i=0;i<n;i++){
        printf("arr[%d]=",i);
        scanf("%d",&arr[i]);
    }

    //finding mean
    int sum=0;
    for(i=0;i<n;i++){
        sum+=arr[i];
    }
    printf("Sum of element are :%d\n",sum);
    printf("Mean of given element are:%d",sum/n);

    return 0;
}
