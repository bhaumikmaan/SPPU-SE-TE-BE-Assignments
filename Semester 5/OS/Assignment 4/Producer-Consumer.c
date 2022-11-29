//PRODUCER - CONSUMER PROBLEM 

#include<stdio.h>
#include<pthread.h>
int buff[10];
pthread_mutex_t m;		// Delcaration

void producer()
{
	int i=0,n;
	while(1)
		{
			pthread_mutex_lock(&m);
			n=random()%10;
			buff[i++]=n;
			printf("%d Element is added at %d Location", n, i-1);
			if(i==10) i=0;
			pthread_mutex_unlock(&m);
			sleep(2);
		}
}

void consumer()
{
	int key, i=0;
	while(1)
	{
		pthread_mutex_lock(&m);
		key=buff[i++];
		printf("%d Element is extracted at %d Location", key, i-1);
		if(i==10) i=0;
		pthread_mutex_unlock(&m);
		sleep(2);
	
	}
}

void main()
{
	pthread_mutex_init(&m,NULL);		// Initialize 
	pthread_t pt, ct;
	pthread_create(&pt, NULL, producer, NULL);
	pthread_create(&ct, NULL, consumer, NULL);
	
	pthread_join(pt, NULL);
	pthread_join(ct, NULL);
	
}


