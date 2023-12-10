#include "shell.h"

/**
 * _strlen - return the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
 int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}
/**
 * _strcmp - performs lexicogarphic comparison of two strangs.
 * @x: the first strang
 * @y: the second strang.
 * Return: negative if x < y, positive if x > y, zero if x == y
 */
int _strcmp(char *x, char *y)
{
	while (*x && *y)
	{
		if (*x != *y)
			return (*x - *y);
		x++;
		y++;
	}
	if (*x == *y)
		return (0);
	else
		return (*x < *y ? -1 : 1);
}
/**
 * _strcat - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
/**
 **_strncat _ concatenates two strings
 * @dest: the first string.
 * @src: the second string.
 * @n: the amount of bytes to be maximally used.
 * Return: the concatenated string.
 */
char *_strncat(char *dest, char *src, int n)
{
	int a, b;
	char *s = dest;

	a = 0;
	b = 0;
	while (dest[a] != '\0')
		a++;
	while (src[b] != '\0' && b < n)
	{
		dest[a] = src[b];
		a++;
		b++;
	}
	if (b < n)
		dest[a] = '\0';
	return (s)
}
