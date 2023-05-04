#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index in a number
 * @n: number to search
 * @index: index of the bit
 *
 * Return: value of the bit at the given index or -1 if an error occurred
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index > 63)
		return (-1);

	return ((n >> index) & 1);
}
