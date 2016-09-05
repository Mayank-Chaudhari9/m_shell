#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
<sys/wait.h>

char *tokens[20];
int main(int argc, char const *argv[])
{
	char  string[]="/bin/rm	 x.txt";

	char *token,*tokeni,*arg[200];
	int i=0,count,j=0;
	token=strtok(string," ,	");
	count=0;
	 while(token !=NULL)
	 {
	 	count=count+1;
	 	
	 	tokeni=token;
	 	tokens[i]=tokeni;
	 	
	 	i++;
	 	token = strtok(NULL, " ,	");

	 }
	 execvp("ls","")
	// execl( "/bin/ls","ls -l", NULL );

	/*for(i=1;i<count;i++)
	 {
	 	arg[j]=tokens[i];
	 }

	
	 printf("%s\n",tokens );
	 execv(tokens[0],tokens);

	 


	 	/*token=strchr(string,'|');
	 	if(token!=NULL)
	 		printf("it exists\n");
	*/

	return 0;
}