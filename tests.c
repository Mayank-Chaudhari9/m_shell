#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char *string1,*string2,*string3;

	string1="hello i mhere %amhere";

	string2="i";

	string3=strstr(string1,"%am");

	printf("%s\n",string3);


	return 0;
}