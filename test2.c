#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
	execl("/bin/ls","ls","-l",0);

	return 0;
}
