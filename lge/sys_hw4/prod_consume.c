#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define	NLOOP	   	100
#define	Q_MAX	    16

typedef struct queue_t {
	int		data[Q_MAX];	
	int		nitem;		
	int		head;
	int		tail;
	pthread_mutex_t	mutex;
	pthread_cond_t	c_cond;	
	pthread_cond_t	p_cond;
}queue_t;

queue_t queue;

void put( int d ) 
{
	queue.data[queue.head] = d;
	queue.head = (queue.head+1)%Q_MAX;
	queue.nitem++;
}

int get() 
{
	int temp =  queue.data[queue.tail];
	queue.tail = (queue.tail+1)%Q_MAX;
	queue.nitem--;
	return temp;
}

int is_empty( )
{
	return queue.nitem == 0;
}

int is_full( )
{
	return queue.nitem ==  Q_MAX;
}

//===================================================================//
//===================================================================//
//===================================================================//
//===================================================================//

void * produce(void *vptr)
{
	int		i;
	int		produce_time;

	for (i = 0; i < NLOOP; i++) 
	{
  	pthread_mutex_lock(&queue.mutex);
		if (is_full()) {
			printf("PRODUCER THREAD is waiting for the items to be CONSUMED \n");
			pthread_cond_wait(&queue.c_cond, &queue.mutex);
		}
		
		produce_time = (rand() % 5) + 1;
		printf("PRODUCED TIME is %dms \n", produce_time);

		usleep(produce_time);
		put(i + 1);
		printf("produce %d \n", i+1);
	
		pthread_cond_signal(&queue.p_cond);
		pthread_mutex_unlock(&queue.mutex);
	}
	return 0;
}

void * consume(void *vptr)
{
	int		i, val;
	int 	consume_time;

	for (i = 0; i < NLOOP; i++) {
		pthread_mutex_lock(&queue.mutex);
		if (is_empty()) {
			printf("CONSUMER THREAD is waiting for the items to be PRODUCED \n");
			pthread_cond_wait(&queue.p_cond, &queue.mutex);
		}

		consume_time = (rand() % 2) + 2;
		printf("CONSUMED TIME is %dms \n", consume_time);

		usleep(consume_time);
		val = get();
		printf("consume %d \n", val);
		
		pthread_cond_signal(&queue.c_cond);
		pthread_mutex_unlock(&queue.mutex);

	}
	return 0;
}

//===================================================================//
//===================================================================//
//===================================================================//
//===================================================================//

int main(int argc, char **argv)
{
	int			n;
	pthread_t	tidA, tidB;
	srand(time(0));

	pthread_create(&tidA, 0, &produce, 0);
	pthread_create(&tidB, 0, &consume, 0);
	pthread_join(tidA, 0);
	pthread_join(tidB, 0);
	return 0;
}
