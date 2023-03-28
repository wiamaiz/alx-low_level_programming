#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/**
* main - Entry point
*
* Description: Get the last digit of a random number and print whether it is
* greater than 5, 0, or less than 6 and not 0.
*
* Return: Always 0 (Success)
*/
int main(void)
{
int n;
int ld;
srand(time(0));
n = rand();
ld = n % 10;
if (ld > 5)
{
printf("Last digit of %d is %d and is greater than 5\n", n, ld);
}
else if (ld == 0)
{
printf("Last digit of %d is %d and is 0\n", n, ld);
}
else
{
printf("Last digit of %d is %d and is less than 6 and not 0\n", n, ld);
}
return (0);
}
