#include <stdio.h>
#include "str.h"


int main(){
	char s[4] = "Hel";
	*s = 'o';
	printf("%s\n", s);

	char s1[4];

	strcpy(s1,s);
	printf("strcopy \n");
	printf("%s\n", s);
	printf("%s\n\n", s1);

	char s2[4];

	my_strncpy(s2,s,3);
	printf("my_strncpy(s2,s,6)\n");
	printf("%s\n\n", s2);


	char s3[4];
	strcpy(s3,s2);
	printf("strcat\n");
	printf("Append %s to %s\n", s,s3);
	strcat(s3,s);
	printf("%s\n\n", s3);


	char s4[8] = "Hel";
	char s5[5] = "Iaghr";
	printf("my_strncat\n");
	my_strncat(s4,s5,4);
	printf("%s\n\n", s4);

	printf("strcmp\n");
	strcpy(s4,s5);
	*s4='i';
	printf("compare %s and %s\n", s4,s5);
	printf("%d\n", strcmp(s4,s5));
	printf("compare %s and %s\n", s,s1);
	printf("%d\n\n", strcmp(s,s1));


	printf("my_strncmp\n");
	strcpy(s4,s5);
	// *s4++;
	s4[2]='i';
	printf("compare %s and %s for length 4\n", s4,s5);
	printf("%d\n", my_strncmp(s4,s5,4));

	printf("compare %s and %s for length 5\n", s4,s5);
	printf("%d\n\n", my_strncmp(s4,s5,5));


	//It can be seen that for not found, the address of the null at the end of the string is returned.
	printf("strchr\n");
	printf("search for 'e' in %s\n", s);
	// printf("%c\n", *strchr(s,(int)'l'));
	printf("char - %c, ptr adr - %p\n\n", *strchr(s,(int)'e'),strchr(s,(int)'e'));	
	printf("search for 'a' in %s\n", s);
	printf("char - %c, ptr adr - %p\n\n", *strchr(s,(int)'a'),strchr(s,(int)'a'));


	printf("strchrnul\n");
	printf("search for 'e' in %s\n", s);
	printf("char - %c, ptr adr - %p\n\n", *strchr(s,(int)'e'),strchr(s,(int)'e'));	
	printf("search for 'a' in %s\n", s);
	printf("char - %c, ptr adr - %p\n\n", *strchr(s,(int)'a'),strchr(s,(int)'a'));


	//ptr address of 't' should be 1 greater than that of 'g'
	char s6[4] = "atgt";
	printf("strrchr\n");
	printf("search for 'g' in %s\n", s6);
	// printf("%c\n", *strchr(s,(int)'l'));
	printf("%p\n", s6);
	printf("char - %c, ptr adr - %p\n\n", *strrchr(s6,(int)'g'),strrchr(s6,(int)'g'));	
	printf("search for 't' in %s\n", s6);
	printf("char - %c, ptr adr - %p\n", *strrchr(s6,(int)'t'),strrchr(s6,(int)'t'));
	printf("search for 'e' in %s\n", s6);
	printf("char - %c, ptr adr - %p\n\n", *strchr(s6,(int)'e'),strchr(s6,(int)'e'));


}