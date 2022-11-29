#include<unistd.h>
#include<pthread.h>
#include<stdio.h>
#include<semaphore.h>
sem_t ch[5];
void *philosopher(void *arg)
{
	int i=(int)arg;
	int left,right;
	printf("\n%d philosopher is created\n",arg);
	sleep(5);
	left=i;
	right=(i+1)%5;
	printf("\n%d philosopher is hungry\n",arg);
	sem_wait(&ch[left]);
	sem_wait(&ch[right]);
	printf("\n%d philosopher is eating\n",arg);
	sleep(5);
	sem_post(&ch[right]);
	sem_post(&ch[left]);
	printf("\n%d philosopher is complete\n",arg);
}
int main()
{
	int i;
	pthread_t pid[5];
	for(i=0;i<5;i++)
		sem_init(&ch[i],0,1);
	for(i=0;i<5;i++)
	{
		pthread_create(&pid[i],NULL,philosopher,(void *)i);
		sleep(1);
	}
	for(i=0;i<5;i++)
		pthread_join(pid[i],NULL);
}
