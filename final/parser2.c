#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#include "parser.h"


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







char  * parser(char *c_ptr,ssize_t read)
{
	//printf("%s\n",c_ptr );

	char c;
	int i,length;

	char *r_ptr=(char *)malloc(sizeof(char)*read);
	r_ptr=c_ptr;

	length=strlen(r_ptr);

 //-------------------------- removing spaces-----------------------------------//
	for(i=0;i<length;i++)
	{
		if (isspace(*r_ptr))
			{
				r_ptr=r_ptr+1;

			}
			else
				continue;
	}

	



	
	
	
	//printf("%c\n",*r_ptr);
	



	return r_ptr;

}

