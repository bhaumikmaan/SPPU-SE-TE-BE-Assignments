#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "shm_com.h"
int main()
{
	int running = 1;
	void *shared_memory = (void *)0;
	struct shared_m *shared_stuff;
	char buffer[2048];
	int shmid;
	shmid = shmget((key_t)1234, sizeof(struct shared_m), 0666 | IPC_CREAT);
	if (shmid == -1) 
	{
		fprintf(stderr, "shmget failed\n");
		exit(EXIT_FAILURE);
	}
	shared_memory = shmat(shmid, (void *)0, 0);
	if (shared_memory == (void *)-1) 
	{
		fprintf(stderr, "shmat failed\n");
		exit(EXIT_FAILURE);
	}
	printf("Memory attached at %X\n", (int)shared_memory);
	shared_stuff = (struct shared_m *)shared_memory;
	while(running) 
	{
		while(shared_stuff->flag == 1) 
		{
			sleep(1);
			printf("waiting for client...\n");
		}
		printf("Enter some text: ");
		fgets(buffer, 2048, stdin);
		strncpy(shared_stuff->text, buffer, 2048);
		shared_stuff->flag = 1;
		if (strncmp(buffer, "end", 3) == 0) 
		{
			running = 0;
		}
	}
	if (shmdt(shared_memory) == -1) 
	{
		fprintf(stderr, "shmdt failed\n");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
