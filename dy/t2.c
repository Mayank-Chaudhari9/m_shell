#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char const *argv[])
{
	int compare;
	char a[5]="mayank";
	char *b="mayank";
	compare=strncmp(a,b,6);
	if (compare==0)
	{
		printf("%s\n", a);
	}
	else
		printf("%s\n", b);

	return 0;
}