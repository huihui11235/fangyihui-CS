#ifndef QUEUE_H
#define QUEUE_H
#define NumOfQueue   20

typedef int ElementType;

struct queue
{
	int Capacity;
	int size;
	int front;
	int rear;
	ElementType* Array;
};

typedef struct queue* Queue;

Queue CreatQueue();

int IsEmpty(Queue Q);

int IsFull(Queue Q);

void MakeEmpty(Queue Q);

void EnQueue(Queue Q, ElementType data);

void DeQueue(Queue Q);

void PrintQueue(Q);
ElementType Front(Queue Q);
ElementType FrontAndDequeue(Queue Q);


#endif // QUEUE_H
