#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

#include <stdbool.h>


#define QUEUESIZE 10
#define LOOP 20


void *producer(void *args);
void *consumer(void *args);

typedef struct
{
	int buf[QUEUESIZE];
	long head, tail;
	int full, empty;
	pthread_mutex_t *mut;
	pthread_cond_t *notFull, *notEmpty;
} queue;

queue *queueInit(void);
void queueDelete(queue *q);
void queueAdd(queue *q, int in);
void queueDel(queue *q, int *out);

//FILE *fptr1, *fptr2, *fptr3, *fptr4;
int maxConsumers = 0, maxProducers = 4;

int main(int argc, char *argv[])
{	
	int i,j;
	

	if (argc < 2)
	{
		printf("\n Not Given value needed! \n");
		return 1;
	}else {
		maxConsumers = atoi(argv[1]);	
	}

	
	/* File Pointers to write in files */ 
	
	/*
	fptr1 = fopen("/home/nickgian/ENSW/egrasia1/source/timeProducer.txt", "w");
	if (fptr1 == NULL)
	{
		printf("Error Opening file for Producer");
		exit(1);
	}
	fptr2 = fopen("/home/nickgian/ENSW/egrasia1/source/timeConsumer.txt", "w");
	if (fptr2 == NULL)
	{
		printf("Error Opening file for Consumer");
		exit(1);
	}

	fptr3 = fopen("/home/nickgian/ENSW/egrasia1/source/timeOnlyProducer.txt", "w");
	if (fptr3 == NULL)
	{
		printf("Error Opening file for timeOnlyProducer");
		exit(1);
	}
	fptr4 = fopen("/home/nickgian/ENSW/egrasia1/source/timeOnlyConsumer.txt", "w");
	if (fptr4 == NULL)
	{
		printf("Error Opening file for timeOnlyConsumer");
		exit(1);
	} */

	queue *fifo;
	pthread_t pro[maxProducers], con[maxConsumers];

	fifo = queueInit();
	if (fifo == NULL)
	{
		fprintf(stderr, "main: Queue Init failed.\n");
		exit(1);
	}

	for (i = 0; i < maxProducers; i++ ){
		pthread_create(&pro[i], NULL, producer, fifo);
	}
	for (j = 0; j < maxConsumers; j++ ){
		pthread_create(&con[j], NULL, consumer, fifo);
	}
	
	for (i = 0; i < maxProducers; i++ ){
		pthread_join(pro[i], NULL);
	}
	for (j = 0; j < maxConsumers; j++ ){
		pthread_join(con[j], NULL);
	}
	
	queueDelete(fifo);

	//fclose(fptr1);
	//fclose(fptr2);
	//fclose(fptr3);
	//fclose(fptr4); 
	printf(" maxProducers = %d \t maxConsumers = %d ", maxProducers, maxConsumers);

	return 0;
}

void *producer(void *q)
{
	queue *fifo;
	int i;
	
	struct timeval startTime;

	fifo = (queue *)q;

	for (i = 0; i < LOOP; i++)
	{
		pthread_mutex_lock(fifo->mut);
		while (fifo->full)
		{
			//printf("producer: queue FULL.\n");
			pthread_cond_wait(fifo->notFull, fifo->mut);
		}
		gettimeofday(&startTime, NULL);
		queueAdd(fifo, i);

		printf("Start Time = 0.%ld\n", startTime.tv_usec);

		//fprintf(fptr1, "Producer %d = 0.%ld\n", i, startTime.tv_usec);
		//fprintf(fptr3, "0.%ld\n", startTime.tv_usec);

		pthread_mutex_unlock(fifo->mut);
		pthread_cond_signal(fifo->notEmpty);
	}
	return (NULL);
}

int globalCounter = 0;
void *consumer(void *q)
{
	queue *fifo;
	int i, d;

	struct timeval end;
	fifo = (queue *)q;

	while(1)
	{
		pthread_mutex_lock(fifo->mut);
		while (fifo->empty)
		{
			//printf("consumer: queue EMPTY.\n");
			pthread_cond_wait(fifo->notEmpty, fifo->mut);
		}
		gettimeofday(&end, NULL);
		queueDel(fifo, &d);
		printf("End Time = 0.%ld\n", end.tv_usec);

		//fprintf(fptr2, "Consumer %d = 0.%ld\n", i, end.tv_usec);
		//fprintf(fptr4, "0.%ld\n", end.tv_usec);
		pthread_mutex_unlock(fifo->mut);
		pthread_cond_signal(fifo->notFull);
		//printf("consumer: recieved %d.\n", d);
	}
	return (NULL);
}

queue *queueInit(void)
{
	queue *q;

	q = (queue *)malloc(sizeof(queue));
	if (q == NULL)
		return (NULL);

	q->empty = 1;
	q->full = 0;
	q->head = 0;
	q->tail = 0;
	q->mut = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(q->mut, NULL);
	q->notFull = (pthread_cond_t *)malloc(sizeof(pthread_cond_t));
	pthread_cond_init(q->notFull, NULL);
	q->notEmpty = (pthread_cond_t *)malloc(sizeof(pthread_cond_t));
	pthread_cond_init(q->notEmpty, NULL);

	return (q);
}

void queueDelete(queue *q)
{
	pthread_mutex_destroy(q->mut);
	free(q->mut);
	pthread_cond_destroy(q->notFull);
	free(q->notFull);
	pthread_cond_destroy(q->notEmpty);
	free(q->notEmpty);
	free(q);
}

void queueAdd(queue *q, int in)
{
	q->buf[q->tail] = in;
	q->tail++;
	if (q->tail == QUEUESIZE)
		q->tail = 0;
	if (q->tail == q->head)
		q->full = 1;
	q->empty = 0;

	return;
}

void queueDel(queue *q, int *out)
{
	*out = q->buf[q->head];

	q->head++;
	if (q->head == QUEUESIZE)
		q->head = 0;
	if (q->head == q->tail)
		q->empty = 1;
	q->full = 0;

	return;
}