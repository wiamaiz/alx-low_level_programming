#ifndef MAIN_H
#define MAIN_H

/* function to convert binary string to unsigned int */
unsigned int binary_to_uint(const char *b);

/* function to print binary representation of an unsigned long int */
void print_binary(unsigned long int n);

/* function to get bit at specified index in an unsigned long int */
int get_bit(unsigned long int n, unsigned int index);

/* function to set bit at specified index in an unsigned long int */
int set_bit(unsigned long int *n, unsigned int index);

/* function to clear bit at specified index in an unsigned long int */
int clear_bit(unsigned long int *n, unsigned int index);

/* function to flip bits of one unsigned long int to another */
unsigned int flip_bits(unsigned long int n, unsigned long int m);

/* function to convert string to integer */
int _atoi(const char *s);

/* function to print a character to stdout */
int _putchar(char c);

/* function to determine the endianness of the system */
int get_endianness(void);

#endif
