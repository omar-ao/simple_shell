#include "main.h"

/**
 * _strpbrk - locates the first occurrence in the string s
 * @s: string
 * @accept: string
 * Return: Pointer
 */
char *_strpbrk(char *s, char *accept)
{
	int i, j, occurance = 0;
	char *r;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; accept[j] != '\0'; j++)
			if (s[i] == accept[j])
				occurance = 1;
		if (occurance)
		{
			r = (s + i);
			break;
		}
	}
	if (occurance)
		return (r);
	else
		return (NULL);
}

/**
 * _strcat - Concatenates two strings
 * @dest: destination
 * @src: source
 * Return: pointer to the concatenated string
 */
char *_strcat(char *dest, char *src)
{
	int i, j, k, destlen, srclen;
	char *result;

	destlen = _strlen(dest);
	srclen = _strlen(src);
	result = dest;

	for (j = 0, i = 0; j < destlen; j++, i++)
		*(result + i) = *(dest + j);
	for (k = 0; k <= srclen; k++, i++)
		*(result + i) = *(src + k);
	return (result);
}

/**
 * _strncmp - Compares two strings
 * @s1: First string
 * @s2: Second string
 * @len: Number of characters to compare
 * Return: Difference of the strings
 */
int _strncmp(char *s1, char *s2, int len)
{
	int i, diff;

	for (i = 0; i < len; i++)
	{
		diff = s1[i] - s2[i];
		if (diff != 0)
			break;
	}
	return (diff);
}

/**
 * _strchr - locates a character in string
 * @s: String
 * @c: character to locate.
 * Return: first occurance of @c if found otherwise NULL
 */
char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i] >= '\0'; i++)
		if (s[i] == c)
			return (s + i);
	return (NULL);
}
