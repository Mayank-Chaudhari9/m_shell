#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char const *argv[])
{

	FILE *fp;
	char *input,c;
	char *line;
    size_t bufsize;
    size_t characters;
	//printf("%s working\n",argv[1]);
	

	fp=fopen(argv[1],"r");
	if(!fp)
	{
		perror("Error : ");
		return (-1);
	}
	
	printf("$>> This is a mimimal shell\n");
	printf("$>> Please choose the way to proceed\n");
	printf("$>> dup2 :    to pcoceed with dup2 \n");
	printf("$>> tee  :    tee to proceed with tee\n");
	printf("$>> exit :    exit to quit\n");

	while(1)
	{
		printf("$>>");
		
		//fflush(NULL);
		getline(&line,&bufsize,stdin);
		
		input=(char *)malloc(sizeof(char)*bufsize);			
		input=line;	
		c=*input;
		while(isspace(c))
			{
				input=input+1;
				c=*input;
			}

		if((strncmp(input,"dup2",4))==0)
			printf("$>> you choose dup2\n");
		else if ((strncmp(input,"tee",4))==0)
		{
			printf("$>> you choose tee\n");
		}
		else if ((strncmp(input,"exit",4))==0)
			return 0;
		else
			printf("$>> No such command found \n");;

		
		
		
		
	}
	
	fclose(fp);

}

