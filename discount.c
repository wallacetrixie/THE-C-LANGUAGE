#include<stdio.h>
void greeting();
int dd();
int main()
{
    greeting();
    dd();

    return 0;
}
void greeting()
{
    printf("Welcome!\n");
    
}
int dd()
{
    int dis;
    int age;
    int prize;
    printf("Key in your age : ");
    scanf("%d",&age);
    if (age<18)
    {
        printf("The age you have entered is invalid");
        return 0;
    }
    
}