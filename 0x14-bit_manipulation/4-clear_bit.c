#include "main.h"

/**
 * clear_bit - sets the value of a given bit to 0
 * @n: pointer to the number to change
 * @index: index of the bit to clear (starting from 0)
 *
 * Return: 1 if successful, or -1 if an error occurred
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	/* Shift 1 to the left by the index and complement it to create a mask
	 * with all bits set to 1 except for the bit at the given index, which is 0
	 * Then, perform a bitwise AND with the number to set the bit at the given index to 0 */
	*n &= ~(1UL << index);

	return (1);
}
