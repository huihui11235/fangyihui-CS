#include<stdio.h>
typedef struct SkipNode* Position;
typedef Position SkipList;
typedef int ElementType;
#define Infinity 10000
struct SkipNode
{
	ElementType Element;
	SkipList Right;
	SkipList Down;
};
static Position Bottom = NULL;
static Position Tail = NULL;

SkipList Initialize(void);
Position Find(ElementType Item, SkipList L);
SkipList Insert(ElementType Item, SkipList L);

SkipList Initialize(void)
{
	SkipList L;
	if (Bottom == NULL)
	{
		Bottom = malloc(sizeof(struct SkipNode));
		if (Bottom == NULL)
			perror("Out of space!!!");
		Bottom->Right = Bottom->Down = Bottom;
		Tail = malloc(sizeof(struct SkipNode));
		if (Tail == NULL)
			perror("Out of space!!!");
		Tail->Element = Infinity;
		Tail->Right = Tail;
	}
	//建立头结点
	L = malloc(sizeof(struct SkipNode));
	if (L == NULL)
		perror("Out of space!!!");
	L->Element = Infinity;
	L->Right = Tail;
	L->Down = Bottom;
	return L;
}
Position Find(ElementType Item, SkipList L)
{
	Position Current = L;
	Bottom->Element = Item;
	while (Item != Current->Element)
		if (Item < Current->Element)
			Current = Current->Down;
		else
			Current = Current->Right;
	return Current;
}
SkipList Insert(ElementType Item, SkipList L)
{
	Position Current = L;
	Position NewNode;

	Bottom->Element = Item;
	while (Current != Bottom)
	{
		while (Item > Current->Element)
			Current = Current->Right;
		if (Current->Element > Current->Down->Right->Right->Element)
		{
			NewNode = malloc(sizeof(struct SkipNode));
			if (NewNode == NULL)
				perror("Out of space!!!");
			NewNode->Right = Current->Right;
			NewNode->Down = Current->Down->Right->Right;
			Current->Right = NewNode;
			NewNode->Element = Current->Element;
			Current->Element = Current->Down->Right->Element;
		}
		else
			Current = Current->Down;
	}
	if (L->Right != Tail)
	{
		NewNode = malloc(sizeof(struct SkipNode));
		if (NewNode == NULL)
			perror("Out of space!!!");
		NewNode->Down = L;
		NewNode->Right = Tail;
		NewNode->Element = Infinity;
		L = NewNode;
	}
	return L;
}
