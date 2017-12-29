#include <ctype.h>
#include <xlocale.h>
#include "str.h"
#include <stdio.h>


/**
 * my_strncasecmp - Case insensitive, length-limited string comparison
 * @s1: One string
 * @s2: The other string
 * @len: the maximum number of characters to compare
 */

int my_strncasecmp(const char *s1, const char *s2, int len)
{
	unsigned char c1, c2;

	if (!len)
		return 0;

	do {
		c1 = *s1++;
		c2 = *s2++;
		if (!c1 || !c2)
			break;
		if (c1 == c2)
			continue;
		c1 = tolower(c1);
		c2 = tolower(c2);
		if (c1 != c2)
			break;
	} while (--len);
	return (int)c1 - (int)c2;
}

/**
 * strcpy - Copy a %NUL terminated string
 * @dest: Where to copy the string to
 * @src: Where to copy the string from
 */
char *strcpy(char *dest, const char *src){
	char c = *src;

	while (c!='\0'){
		*dest++ = c;
		c = *++src;
	}

	*dest = '\0';

	return dest;
}

/**
 * my_strncpy - Copy a length-limited, C-string
 * @dest: Where to copy the string to
 * @src: Where to copy the string from
 * @count: The maximum number of bytes to copy
 *
 * The result is not %NUL-terminated if the source exceeds
 * @count bytes.
 *
 * In the case where the length of @src is less than  that  of
 * count, the remainder of @dest will be padded with %NUL.
 *
 */
char *my_strncpy(char *dest, const char *src, int count){
	char c = *src;

	do {
		*dest++ = c;
		c = *++src;
	}while (--count && c!='\0');

	while (count--){
		*dest++ = '\0';
	}

	return dest;
}

/**
 * strcat - Append one %NUL-terminated string to another
 * @dest: The string to be appended to
 * @src: The string to append to it
 */
char *strcat(char *dest, const char *src){
	char c = *dest;
	//Go to the end of dest
	while (c!='\0'){
		c = *dest++;
	}

	dest--;

	do {
		c = *src++;
		*dest++ = c;
	} while (c!='\0');

	return dest;

}

/**
 * my_strncat - Append a length-limited, C-string to another
 * @dest: The string to be appended to
 * @src: The string to append to it
 * @count: The maximum numbers of bytes to copy
 *
 * Note that in contrast to strncpy(), strncat() ensures the result is
 * terminated.
 */
char *my_strncat(char *dest, const char *src, int count){
	char c = *dest;
	//Go to the end of dest
	while (c!='\0'){
		c = *dest++;
	}

	dest--;

	do {
		c = *src++;
		*dest++ = c;
	} while (--count && c!='\0');

	*dest++ = '\0';
	return dest;
}


/**
 * strcmp - Compare two strings
 * @cs: One string
 * @ct: Another string
 */
int strcmp(const char *cs, const char *ct){
	char c1, c2;

	do {
		c1 = *cs++;
		c2 = *ct++;
		if (c1 == '\0' || c2 == '\0')
			break;
	} while (c1==c2);
	if((int)c1 - (int)c2)
		return -1;
	else
		return 0;
}

/**
 * my_strncmp - Compare two length-limited strings
 * @cs: One string
 * @ct: Another string
 * @count: The maximum number of bytes to compare
 */
int my_strncmp(const char *cs, const char *ct, int count){
	char c1, c2;

	do {
		c1 = *cs++;
		c2 = *ct++;
	} while (c1==c2 && --count);

	if((int)c1 - (int)c2)
		return -1;
	else
		return 0;
}

/**
 * strchr - Find the first occurrence of a character in a string
 * @s: The string to be searched
 * @c: The character to search for
 */
char *my_strchr(const char *s, int c){
	char a = (char) c;
	char b = *s;
	int found = 0;

	/*char *sptr = s;
	char c1 = *sptr;
	printf("my_strchr, string is: %s\n", sptr);
	while (c1!='\0'){
		printf("%c\n", c1);
		c1 = *++s;
	}

	s= sptr;
	c1 = *s;

	printf("my_strchr, string is: %s\n", sptr);
	while (c1!='\0'){
		printf("%c\n", c1);
		c1 = *++s;
	}

	s= sptr;*/


	// printf("c1 is: %c\n",c1);

	while (a!=b && b!='\0'){
		printf("a = %c, b = %c\n",a, b);
		b = *++s;
	}
/*
	if (b=='\0')
		return NULL;*/

	return s;

}


/**
 * strchrnul - Find and return a character in a string, or end of string
 * @s: The string to be searched
 * @c: The character to search for
 *
 * Returns pointer to first occurrence of 'c' in s. If c is not found, then
 * return a pointer to the null byte at the end of s.
 */
char *strchrnul(const char *s, int c){
	char a = (char) c;
	char b = *s;

	while (a!=b && b!='\0'){
		printf("%c\n", b);
		b = *++s;
	}

	return s;
}

/**
 * strrchr - Find the last occurrence of a character in a string
 * @s: The string to be searched
 * @c: The character to search for
 */
char *strrchr(const char *s, int c){
	char a = (char) c;
	char b = *s;
	char *s1;
	int found = 0;

	while (b!='\0'){
		if (a==b){
			s1 = s;
			found =1 ;
		}
		b = *++s;
	}

	/*if (b=='\0' && !found)
		s1 = NULL;*/

	return s1;
}


/**
 * strnchr - Find a character in a length limited string
 * @s: The string to be searched
 * @count: The number of characters to be searched
 * @c: The character to search for
 */
char *strnchr(const char *s, int count, int c){
	char a = (char) c;
	char b = *s;
	char *s1;
	int found = 0;

	while (count--){
		if (a==b){
			s1 = s;
			found =1 ;
		}
		b = *++s;
	}

	if (b=='\0' && !found)
		s1 = s;

	return s1;
}

/**
 * skip_spaces - Removes leading whitespace from @str.
 * @str: The string to be stripped.
 *
 * Returns a pointer to the first non-whitespace character in @str.
 */
char *skip_spaces(const char *str){
	char c = *str;
	while (c==' '){
		printf("char c: '%c'\n",c);
		c = *++str;
	}
	return str;
}


/**
 * strim - Removes leading and trailing whitespace from @s.
 * @s: The string to be stripped.
 *
 * Note that the first trailing whitespace is replaced with a %NUL-terminator
 * in the given string @s. Returns a pointer to the first non-whitespace
 * character in @s.
 */
char *strim(char *s){
	s = skip_spaces(s);
	printf("%s\n", s);
	int len = my_strlen(s);
	printf("len = %d\n", len);
	s+=len-1;
	int a = 0;
	for (;*s == ' ';s--){
		// printf("%s\n", s);
		// printf("%c\n", *s);
		a++;
	}
	*++s = '\0';
	s-=(len-a);
	return s;
}

/**
 * my_strlen - Find the length of a string
 * @s: The string to be sized
 */
int my_strlen(const char *s){
	printf("my_strlen, s = %s\n", s);
	int a = 0;
	char c = *s;
	while (c!='\0'){
		// printf("%c\n", c);
		s++;
		// printf("here\n");
		c = *s;
		a++;
		// printf("%d\n", a);
	}
	// printf("%d\n", a);
	return a;
}

/**
 * strnlen - Find the length of a length-limited string
 * @s: The string to be sized
 * @count: The maximum number of bytes to search
 */
int strnlen(const char *s, int count){
	int a;
	char c = *s;
	while (c!='\0' && count--){
		a++;
	}
	return a;
}

/**
 * my_memset - Fill a region of memory with the given value
 * @s: Pointer to the start of the area.
 * @c: The byte to fill the area with
 * @count: The size of the area.
 *
 */
void *my_memset(void *s, int c, int count){
	int *s1 = (int*) s;
	for (int i = 0; i<count; i++){
		*s1++ = c;
	}
	return s;
}