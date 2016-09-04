#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char *cmd1[] = { "/bin/ls", "ls", "-l", 0 };
char *cmd2[] = {"/usr/bin/wc", "wc", "-l", 0 };

void run_source(int fd[]);
void run_destination(int fd[]);

int main(int argc, char const *argv[])
{

	int pid,s_flag;
	int fd[2];

	pipe(fd);

	run_source(fd);
	run_destination(fd);
	close(fd[0]);
	close(fd[1]);

	while((pid=wait(&s_flag))!=-1)
		fprintf(stderr,"process %d exits with %d\n",pid,WEXITSTATUS(s_flag));
	exit(0);

	//return 0;
}

void run_source(int fd[])
{
	int pid;

	switch(pid=fork())
	{
		case 0:
			dup2(fd[1],1);
			close(fd[0]);
			execl(cmd1[0], cmd1);	/* run the command */
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
			execl( "/usr/bin/wc", "  wc", 0 );	/* run the command */
			perror(cmd2[0]);

		default:
			break;

		case -1:
			perror("fork");
		exit(1);
	}
	
}
