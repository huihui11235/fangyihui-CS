/*红黑树*/
#include<stdio.h>
#include"RedBlackTree.h"

RedBlackTree Initialize(void)
{
	RedBlackTree T;
	if (NullNode = NULL)
	{
		NullNode = malloc(sizeof(struct RedBlackNode));
		if (NullNode = NULL)
			perror("Out of space!!!");
		NullNode->Left = NullNode->Right = NullNode;
		NullNode->Color = Black;
		NullNode->Element = Infinity;
	}
	T = malloc(sizeof(struct RedBlackNode));
	if (T == NULL)
		perror("Out of space!!!");
	T->Element = NegInfinity;
	T->Left = T->Right = NullNode;
	T->Color = Black;
	return T;
}
static void DoPrint(RedBlackTree T)
{
	if (T != NullNode)
	{
		DoPrint(T -> Left);
		Output(T->Element);
		DoPrint(T->Right);
	}
}
void PrintTree(RedBlackTree T)
{
	DoPrint(T->Right);
}
static Position Rotate(ElementType Item, Position Parent)
{
	if (Item < Parent->Element)
		return Parent->Left = Item < Parent->Left->Element ?
		SingleRotateWithLeft(Parent->Left) :
		SingleRotateWithRight(Parent->Left);
	else
		return Parent->Right = Item < Parent->Right->Element ?
		SingleRotateWithLeft(Parent->Right) :
		SingleRotateWithRight(Parent->Right);	
}
static Position X, P, GP, GGP;
static void HandleReorient(ElementType Item, RedBlackTree T)
{
	X->Color = Red;
	X->Left->Color = Black;
	X->Right->Color = Black;
	if (P->Color == Red)
	{
		GP->Color = Red;
		if ((Item < GP->Element) != (Item < P->Element))
			P = Rotate(Item, GP);//双旋转
		X = Rotate(Item, GGP);
		X->Color = Black;
	}
	T->Right->Color = Black;
}
RedBlackTree Insert(ElementType Item, RedBlackTree T)
{
	X = P = GP = T;
	NullNode->Element = Item;
	while (X->Element != Item)
	{
		GGP = GP; GP = P; P = X;
		if (Item < X->Element)
			X = X->Left;
		else
			X = X->Right;
		if (X->Left->Color == Red && X->Right->Color == Red)
			HandleReorient(Item, T);
	}
	if (X != NullNode)
		return NullNode;
	X = malloc(sizeof(struct RedBlackNode));
	if (X == NULL)
		perror("Out of space!!!");
	X->Element = Item;
	X->Left = X->Right = NullNode;
	if (Item < P->Element)
		P->Left = X;
	else
		P->Right = X;
	HandleReorient(Item, T);
	return T;
}
