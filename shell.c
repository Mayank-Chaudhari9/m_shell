#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#include "shell.h"



void run()
{
	execl("/bin/ls","ls","-l",0);
}


void parse(FILE *f_ptr)
{

	FILE *fp1=f_ptr; 
	char *line = NULL,*read_l,c;
	size_t len = 0;
	ssize_t read;
	int error=0,b_flag=0;

	// while loop to read the file line by line and removing the comments

	while ((read = getline(&line,&len,fp1)) != -1)
	{
		printf("Retrived line of length %zu :\n",read);
		read_l=(char *)malloc(sizeof(char)*read);
		read_l=line;
		c=*read_l;
		while(isspace(c))
			{
				read_l=read_l+1;
				c=*read_l;
			}
		//ignore lines starting with #
		if(*read_l=='#')
			continue;
		
		//remove blank lines
		if(read<=1)
			continue;

		if(read>1)
		{
			

			if(strstr(read_l,"%BEGIN")&&(b_flag==0))
				{
					printf("BEGIN Found\n");
					b_flag=1;
					error=1;
					//printf("%s\n",read_l);
				}

			if(b_flag==1)
				{
					if(strstr(read_l,"%BEGIN"))
						{
							continue;
						}
					printf("%s\n",read_l);	
				}

			if(strstr(read_l,"%END")&&(b_flag==1))
			{
				b_flag=0;
				error=0;
			}
			
		}
		

		//printf("%s\n",line);
	}
	if(error)
		{
			printf("Batch file finished abruptly\n");
		}


	free(line);

	run();

}


