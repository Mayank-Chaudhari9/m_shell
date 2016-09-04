#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int option;
	printf("Choose the file to compile and run\n");
	printf("Choose 1 : for  t1\n");
	printf("Choose 2 : for t2\n");

	scanf("%d",&option);
	if (option==1)
	{
		execl( "/usr/bin/gcc", "gcc","t1.c", 0 );
		execl("./a.out",0);
	}
	execl( "/usr/bin/wc", "  wc", 0 );
	return 0;
}