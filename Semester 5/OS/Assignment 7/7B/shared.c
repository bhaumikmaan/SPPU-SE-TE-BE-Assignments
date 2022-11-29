#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "shm_com.h"
int main()
{
	int running = 1;
	void *shared_memory = (void *)0;
	struct shared_m *shared_stuff;
	int shmid;
	srand((unsigned int)getpid());
	shmid = shmget((key_t)1234, sizeof(struct shared_m), 0666 | IPC_CREAT);
	if (shmid == -1)
	{
		fprintf(stderr,"shmget failed\n");
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
	shared_stuff->flag = 0;
	while(running)
	{
		if (shared_stuff->flag)
		{
			printf("You wrote: %s", shared_stuff->text);
			sleep( rand() % 4 ); /* make the other process wait for us ! */
			shared_stuff->flag = 0;
			if (strncmp(shared_stuff->text, "end", 3) == 0) 
			{
				running = 0;
			}
		}
	}


	if (shmdt(shared_memory) == -1) 
	{
		fprintf(stderr, "shmdt failed\n");
		exit(EXIT_FAILURE);
	}
	
		exit(EXIT_SUCCESS);
}

