#include "main.h"

/**
 * _strspn - Gets the length of prefix substring
 * @s: string
 * @accept: Prefix substring
 * Return: length
 */
unsigned int _strspn(char *s, char *accept)
{
	int i, j, occurance, len;

	len = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		occurance = 0;
		for (j = 0; accept[j] != '\0'; j++)
			occurance += (s[i] == accept[j]) ? 1 : 0;
		if (occurance)
			len += occurance;
		else
			break;
	}
	return (len);
}

/**
 * _strcmp - Compares two strings
 * @s1: First string
 * @s2: Second string
 * Return: Difference of the strings
 */
int _strcmp(char *s1, char *s2)
{
	int i, len, diff;
	int n = _strlen(s1), m = _strlen(s2);

	len = (n > m) ? n : m;
	for (i = 0; i < len; i++)
	{
		diff = s1[i] - s2[i];
		if (diff != 0)
			break;
	}
	return (diff);
}

/**
 * _atoi - Converts a string to an integer
 * @s: string
 * Return: int or -1 if failure
 */
int _atoi(char *s)
{
	int i, sign = 1;
	unsigned int num = 0;

	for (i = 0; s[i] != '\0'; ++i)
	{
		if (s[i] == '-')
			sign *= -1;
		if (s[i] >= '0' && s[i] <= '9')
		{
			num = 10 * num + (s[i] - '0');
			if (s[i + 1] == ' ')
				break;
		}
		else
		{
			return (-1);
		}
	}

	return (sign * num);
}

/**
 * _strlen - Returns the length of a string
 * @s: string
 * Return: Length of string
 */
int _strlen(char *s)
{
	int n;

	for (n = 0; *s != '\0'; s++)
		n++;
	return (n);
}

/**
 * _strdup - Returns a pointer to a newly allocated space in memory
 * which contains a copy of the string given as a parameter
 * @str: String to be copied
 * Return: A pointer
 */
char *_strdup(char *str)
{
	int i, len;
	char *dup;

	if (str == NULL)
		return (NULL);
	len = _strlen(str);
	dup = malloc(len + 1);
	if (dup == NULL)
		return (NULL);
	for (i = 0; i <= len; i++)
		dup[i] = str[i];
	return (dup);
}
