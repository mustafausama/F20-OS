#include <stdio.h>

void main()
{
	char str[1024];
	printf("Enter your command:\n");
	gets(str);

	system(str);
}
