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
 * _strcopy - copies a string
 * @dest: the destination
 * @srs: the source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (drst);
}
