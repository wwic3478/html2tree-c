#include <stdlib.h>
#include <stdio.h>
#include <string.h>

FILE *srcfile = NULL;
#define printstatus() printf("%d,%d\n",index,inner)

#define MAX_ASCII	10240
char buffer[MAX_ASCII];
int inner = 0;
int index = 0;

int calc_line(char* buffer)
{
	while(*buffer != '\0')
	{
		index++;
		if(*buffer == '<')//into html
		{
			++inner;
			//printf(",%c,+,%d\n",*(buffer-1),index);
		}
		else if(*buffer == '>')//out html
		{
			//printf(",%c,-,%d\n",*(buffer-1),index);
			--inner;
		}
		if((inner == 0) && (*buffer != '>'))
		{
			//printstatus();
			printf("%c",*(buffer));
		}
//paragraph
		if(buffer[0] ==  'p' 
		&& buffer[1] ==  'a'
		&& buffer[2] ==  'r'
		&& buffer[3] ==  'a'
		&& buffer[4] ==  'g'
		&& buffer[5] ==  'r'
		&& buffer[6] ==  'a'
		&& buffer[7] ==  'p'
		&& buffer[8] ==  'h')
		{
			printf("\n");
		}
//heading
		if(buffer[0] ==  'h' 
		&& buffer[1] ==  'e'
		&& buffer[2] ==  'a'
		&& buffer[3] ==  'd'
		&& buffer[4] ==  'i'
		&& buffer[5] ==  'n'
		&& buffer[6] ==  'g')
		{
			printf("\n");
		}
		buffer++;
	}
}
int main(int argc, char *argv[])
{
	if(argc <= 1)
	{
		printf("您还没有输入文件名。\n");
		return 0;
	}
	//srcfile = fopen("src.txt","r");
	srcfile = fopen(argv[1],"r");
	while(!feof(srcfile))
	{
		//memset(line,strlen(line),0);
		fgets(buffer,MAX_ASCII,srcfile);
		calc_line(buffer); 
		//printf("%s\n",buffer);
	}
	fclose(srcfile);
	return 0;
 } 

