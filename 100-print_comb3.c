#include <stdio.h>
/**
* main - prints all possible different combinations of two digits
*
* Return: Always 0 (Success)
*/
int main(void)
{
int i, j;
for (i = 0; i < 100; i++)
{
j = i + 1;
while (j < 100)
{
putchar((i / 10) + '0');
putchar((i % 10) + '0');
putchar(',');
putchar(' ');
putchar((j / 10) + '0');
putchar((j % 10) + '0');
if (i == 98 && j == 99)
break;
putchar(',');
putchar(' ');
j++;
}
}
putchar('\n');
return (0);
}
