#include <stdio.h>
int main(void)
{
int a = 100;
float b = 1.2365;
printf("%10d\n", a);
printf("%10f\n", b);
printf("%10.3f\n", b);
printf("%*.3f\n", 6, b);
printf("%2d\n", a);
printf("%6f\n", b);
return 0;
}