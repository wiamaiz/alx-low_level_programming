/**
 * binary_to_uint - converts a binary number to unsigned int
 * @b: string containing the binary number
 *
 * Return: the converted number, or 0 if the string is invalid
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int n = 0;

	if (!b)
		return (0);

	for (; *b; b++)
	{
		if (*b != '0' && *b != '1')
			return (0);
		n = (n << 1) | (*b - '0');
	}

	return (n);
}
