#include<stdio.h>
int main()
{
    int marks[]={87,66,78,99,44,56,98,1,94,55};
    int size=sizeof(marks)/sizeof(int);
    int i=0;
    int sum;
    for(i=0;i<size;i++)
    {
        sum+=marks[i];         
    }
    printf("The sum of the elements in the array is:%d",sum);
   
}