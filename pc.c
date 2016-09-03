#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>


int main(int argc, char const *argv[])
{
	int pipefd[2], nbytes;
	pid_t child1,child2;

	char string[] ="this is a message from running process";
	char r_buff[200];
	
	pipe(pipefd);

	/*if((child=fork()) == -1)
	{
		perror("fork");
		exit(1);
	}
	*/
	if ((child1 = fork()) == 0) {
        // attach stdin to the right side of pipe
        // and inherit stdout and stderr from parent
        dup2(pipefd[0],STDOUT_FILENO);

        close(pipefd[1]);              // not using the left side
        execl("/usr/bin/ls", "ls","-l",0);
        perror("exec wc failed");
        exit(0);
    }

	if ((child2 = fork()) == 0)
	{
        // attach stdin to the right side of pipe
        // and inherit stdout and stderr from parent
        dup2(pipefd[0], STDIN_FILENO);

        close(pipefd[1]);              // not using the left side
        execl("/usr/bin/wc", "wc", NULL);
        perror("exec wc failed");
        exit(0);
    }

	return 0;
}