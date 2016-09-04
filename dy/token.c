#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *tokens[20];
int main(int argc, char const *argv[])
{
	char  string[]="/bin/ls		ls	-l";

	char *token,*tokeni;
	int i=0,count;
	token=strtok(string," ,	");
	count=0;
	 while(token !=NULL)
	 {
	 	count=count+1;
	 	tokeni=(char *)malloc(sizeof(strlen(token)));
	 	tokeni=token;
	 	tokens[i]=tokeni;
	 	//count++;
	 	//printf("%d\n", strlen(token));

	 	i++;
	 	token = strtok(NULL, " ,	");

	 }

	// execl( "/bin/ls","ls -l", NULL );


	 for(i=0;i<count;i++)
	 {
	 	printf("%s\n", tokens[i]);
	 }
	 execl( "/bin/ls","ls -la>","a.txt", NULL );


	 	/*token=strchr(string,'|');
	 	if(token!=NULL)
	 		printf("it exists\n");
	*/

	return 0;
}