#include<stdio.h>
int Add(int a,int b)
{

    return a+b;
}
int main()
{
    int a=10;
    int b=10;
    int sum=Add(a, b);
    printf("%d",sum);
}