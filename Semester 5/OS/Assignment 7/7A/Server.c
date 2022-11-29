#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#define FIFO_PIPE "xyz"

int main()
{
int fd, i, c=0, w=0, l=0;
char str[100];

//mkfifo(FIFO_PIPE, 0777);		// mkfifo - create named pipe special file with 777 permission

fd=open(FIFO_PIPE,O_RDONLY);	// Open a File in Read Only Mode
read(fd, str, sizeof(str));		// Read file and store into "str" buffer

printf("\nReceived Data : %s", str);	// Print "str"

for(i=0; str[i]!='\0'; i++)				// Calculate no of lines, words and characters
{
	if(str[i] == ' ' || str[i] == '\n') 		w++;
	if(str[i] == '\n')							l++;
												c++;
}
printf("\n No of characters = %d", c);	// print no of lines, words and characters 
printf("\n No of lines = %d", l+1);
printf("\n No of words = %d \n", w+1);

close(fd);
return 0;
}
