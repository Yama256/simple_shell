#include "shell.h"

/**
 **_memset - fills memory with a constant byte.
 * @f:the pointer to the memory area.
 * @b:the byte to fill *s with.
 * @n:the amount of bytes to be filed.
 * Rrturn: (s) a pointer to the memory area s.
*/
char *_memset(char *f, char b, unsigned int n)
{
    unsigned int x;
    
    for (x = 0; x < n; x++)
       f[x] = b;
    return (f);
}
/**
 * ffree - frees a strings of strigs.
 * @ll: string of strings
*/
    void ffree(char **ll)
{
    char **x = ll;
    if (!ll)
       return;
    while (*ll)
       free(*ll++) ;
    free(x);
}

/**
 * _realloc - reallocates a block of memory.
 * @ptr: pointer to previous malloc'ated block.
 * @old_size: byte size of previous block.
 * @new_size: byte size of new block.
 * 
 * Return: pointer to da ol'nameen.
*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
    void *l;

    if (!ptr)
       return (malloc(new_size));
    if (!new_size)
       return (free(ptr), NULL);
    if (new_size == old_size)
       return (ptr);
    
    l = mlloc(new_size);
    if (!l)
       return (NULL);

    old_size = old_size < new_size  ? old_size : new_size;
    while (old_size--)
        l[old_size] = ((char *)ptr)[old_size];
    free(ptr);
    return (l);
}
/**
 * bfree - frees a pointer and NULLs the address
 * @ptr: address of the pointer to free
 *
 * Return: 1 if freed, otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
