#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#include "parser.h"

//char *tokens[100];


int process_INTERSTART(char *read_line)
{
	char *buf,*string;
	int index=0,compare;
	string="#INTERSTART";
	buf=read_line;
	compare=strncmp(string,buf,11);
	if (*buf=='#')
	{
		if (compare==0)
			{
				return 1;
			}
		else
			return 0;
	}
	else
		return 0;

} 

void run_non_pipe(char *command,ssize_t read)
{
	char *np_command;
	char tokens[read],*tok[20];

	char *token,*tokeni,arg[20];
	int i=0,count,j=0;
	ssize_t s=0;

	np_command=command;
	printf("%zu\n",read);
	 for(s=0;s<read-1;s++)
	 {
	 	tokens[s]=*command;
	 	command++;
	 }
	// printf("%s\n",tokens);
	/*printf("%s\n",np_command);*/
	token=strtok(tokens," ,	");
	count=0;

	 while(token !=NULL)
	 {
	 	count=count+1;
	 	
	 	tokeni=token;
	 	tok[i]=tokeni;
	 	i++;
	 	token = strtok(NULL, " ,	");
	 	//printf("%s\n",tokeni);

	 }
	 
	 for(i=1;i<count;i++)
	 {
	 	arg[j]=tok[i];
	 	//j++;
	 }
	printf("%s\n",arg);
	execv(tok[0],arg);
	 
}

// function to seperate piped from non piped 

void process_command(char *command,ssize_t read)
{
	char *command1;
	//printf("%d\n", sizeof(command));
	//command1=(char *)malloc(sizeof(char)*read);
	//printf("%s\n",command);
	command1=command;

	if(strchr(command1,'|')!=NULL)
		printf("It need pipe solution\n");
	else
		{
			run_non_pipe(command,read);
			//printf("%s\n",command1);
		}
}





void parse(FILE *f_ptr)
{

	FILE *fp1=f_ptr; 
	char *line = NULL,*read_l,c;
	size_t len = 0;
	ssize_t read;
	int error=0,b_flag=0,line_no=0,i_flag=0,test=0;

	// while loop to read the file line by line and removing the comments

	while ((read = getline(&line,&len,fp1)) != -1)
	{
		++line_no;
		//printf("Retrived line of length %zu :  on line number : %d\n",read,line_no);
		read_l=(char *)malloc(sizeof(char)*read);
		read_l=line;
		c=*read_l;
		while(isspace(c))
			{
				read_l=read_l+1;
				c=*read_l;
			}
		
		//remove blank lines
		if(read<=1)
			continue;

		if(read>1)
		{
			

			if(strstr(read_l,"%BEGIN")&&(b_flag==0))
				{
					//printf("BEGIN Found\n");
					b_flag=1;
					error=1;
					//printf("%s\n",read_l);
				}



			if(b_flag==1)
				{
					if(strstr(read_l,"%BEGIN"))     // Ignoring in between %BEGINS
						{
							continue;
						}
				/*--------------------------------------- check for single line comment and INTERSTART -------------------------*/		
					test=process_INTERSTART(read_l);
					if(*read_l=='#')
					{
						if (test)
							{
								printf("INTERSTART Found\n");   // here comes call for INTERSTART command
								/* code */
							}
						else
							continue;
					}

					//printf("%s\n",read_l);

					process_command(read_l,read);	
				}
				/*-------------------------------------------  condition checking for %END ------------------------------------*/
				
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

	//run();

}

void process_comment()
{

}

/*
void run_source(int fd[])
{
	int pid;

	switch(pid=fork())
	{
		case 0:
			dup2(fd[1],1);
			close(fd[0]);
			execl(cmd1[0], cmd1);	//run the command 
			perror(cmd1[0]);
		default:
			break;

		case -1:
			perror("fork");
		exit(1);
	}
}

void run_destination(int fd[])
{
	int pid;

	switch(pid=fork())
	{
		case 0:
			printf("control reached\n");
			dup2(fd[0],0);
			close(fd[1]);
			execl( "/usr/bin/wc", "  wc", 0 );	/* run the command 
			perror(cmd2[0]);

		default:
			break;

		case -1:
			perror("fork");
		exit(1);
	}
	
}

*/