#include <stdlib.h>
#include <stdio.h>
#include <string.h>

FILE *srcfile = NULL;
#define printstatus() printf("%d,%d\n",index,inner)
#define print_char(c) putchar(c)

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
			print_char(*(buffer));
		}
////paragraph
    if(!strncmp(buffer,"paragraph",strlen("paragraph")))
		{
			print_char('\n');
		}
//heading
    if(!strncmp(buffer,"heading",strlen("heading")))
		{
			print_char('\n');
		}
		buffer++;
	}
}
int main(int argc, char *argv[])
{
	if(argc <= 1)
	{
		printf("no file to input,program will exit.\n");
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

