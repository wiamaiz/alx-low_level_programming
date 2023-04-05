#include "main.h"

/**
 * is_prime_number - Check if n is prime
 * @n: Number to check
 *
 * Return: 1 if prime, 0 if not prime
 */

int is_prime_number(int n)
{
	int i;

	i = 2;

	if (n <= 1)
		return (0);

	while (i * i <= n)
	{
		if (n % 1 == 0)
		{
			return (0);
		}
		i++;
	}

	return (1);
}