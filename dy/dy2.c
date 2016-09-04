#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



void run()
{
	execl("./t1.out","t1.out",0);
}



int main(int argc, char const *argv[])
{
	int option,status;
	pid_t pid,child;
	printf("Choose the file to compile and run\n");
	printf("Choose 1 : for  t1\n");
	printf("Choose 2 : for t2\n");

	scanf("%d",&option);
	if (option==1)
	{
		
		child=fork();

		if ((child==0))
			{
				execl( "/usr/bin/gcc", "gcc","-o","t1.out","t1.c", 0 );
			}
		else
		{	
				waitpid(child,&status,0);
				printf("i am here\n");
				execl("./t1.out","t1.out","hello.txt",0);
				
		}	
	}
			
	
	execl( "/usr/bin/wc", "  wc","t1.c", 0 );
	
	return 0;
}