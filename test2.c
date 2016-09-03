#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>




void split(char *commmand)
{



}


int main(int argc, char const *argv[])
{
	FILE *fp;
	char *buf;
	//fp=fopen("out.txt","a+");






	execl("/bin/ls","ls","-al",0);
	//fprintf(fp, "%s\n",buf);

	return 0;
}
