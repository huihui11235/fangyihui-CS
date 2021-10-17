#include "queue.h"
#include<stdio.h>
#include<malloc.h>
#define FatalError( Str )   fprintf( stderr, "%s\n", Str ), exit( 1 )

Queue CreatQueue()；
{
	Queue Q = malloc(sizeof(struct queue));
	if (Q == NULL)
	{
		FatalError("out of space!!!");

	}

	Q->Array = malloc(sizeof(ElementType) * NumOfQueue);
	if (!Q->Array)
	{
		FatalError("out of space!!!");

	}

	Q->front = Q->rear = 0;
	Q->size = 0;
	Q->Capacity = NumOfQueue;


	return Q;
}


//判断队列是否为空//
int IsEmpty(Queue Q)；
{
	return Q->front == Q->rear;
}


//判断队列是否为满//
int IsFull(Queue Q)；
{
	return Q->rear == Q->Capacity-1;
}


//置空//
void MakeEmpty(Queue Q)
{
	Q->front = Q->rear = 0;
	Q->size = 0;
}

void EnQueue(Queue Q, ElementType data)//入队
{
	if (IsFull(Q))
	{
		FatalError("Enqueue Error:the queue is  full !!!");

	}

	Q->Array[Q->rear++] = data;
	++Q->size;
}


//出队//
void DeQueue(Queue Q)
{
	if (IsEmpty(Q))
	{
		FatalError("Dequeue Error: the queue is  empty !!!");

	}

	++Q->front;
	--Q->size;
}

void PrintQueue(Queue Q)//打印队列
{
	if (IsEmpty(Q))
	{
		printf("列表为空");
	}

	int i = Q->front;
	for (; i < Q->rear; i++)
	{
		printf("%d ", Q->Array[i]);
	}
	printf("\n");
}

int main()
{
	Queue Q=CreatQueue();//创建一个空队列

	for (int i = 0; i < 10; i++)
	{
		EnQueue(Q, i);//入队
	}
	PrintQueue(Q);//打印队列

	for (int i = 0; i < 3; i++)
	{
		DeQueue(Q);//出队
	}
	PrintQueue(Q);//打印队列


	MakeEmpty(Q);//置空
	PrintQueue(Q);//打印队列


	return 0;
}
