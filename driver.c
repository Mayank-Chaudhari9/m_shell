#include <stdio.h>
#include <stdlib.h>

void parse(FILE *f_ptr);

int main(int argc, char const *argv[])
{

	FILE *fp;
	printf("%s working\n",argv[1]);
	

	fp=fopen(argv[1],"r");
	if(!fp)
	{
		perror("Error : ");
		return (-1);
	}
	
	/**
	*	Operations to control processing
	*/
	parse(fp);


	fclose(fp);

	return 0;
}

/**
*
*Function to parse the file line by line.
*
**/
void parse(FILE *f_ptr)
{

	FILE *fp1=f_ptr; 
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	// while loop to read the file line by line and removing the comments

	while ((read = getline(&line,&len,fp1)) != -1)
	{
		printf("Retrived line of length %zu :\n",read);
		if(*line=='#')
			continue;
		printf("%s\n",line);
	}

	free(line);

}