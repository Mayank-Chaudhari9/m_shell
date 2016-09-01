#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

	FILE *fp;
	printf("%s working\n",argv[1]);
	

	fp=fopen(argv[1],"r");
	if(!fp)
	{
		perror("Error : ");
		return (-1);
	}

	fclose(fp);

	return 0;
}