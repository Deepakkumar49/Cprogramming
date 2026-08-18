#include<stdio.h>
int main(){
   int rollno[10];//arrays declaration
   printf("Enter element:\t");
   //taking input
   for(int i=0;i<10;i++){
    scanf("%d",&rollno[i]);
   }
   //printing 
   for (int i = 0; i < 10; i++)
   {
    printf("%d",rollno[i]);
   }
   
    return 0;
}