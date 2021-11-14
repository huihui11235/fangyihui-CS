#include<stdio.h>
#include"Splay.h"
SplayTree FindMin(SplayTree T)
{
	Position P=T;
	while (P->Left != NullNode)
	{
		P = P->Left;
	}
	return P;
}
SplayTree FindMax(SplayTree T)
{
	Position P = T;
	while (P->Right != NullNode)
	{
		P = P->Right;
	}
	return P;
}
SplayTree Initialize(void)
{
	if (NullNode == NULL)
	{
		NullNode = malloc(sizeof(struct SplayNode));
		if (NullNode == NULL)
			perror("Out of space!!!");
		NullNode->Left = NullNode->Right = NullNode;
	}
	return NullNode;
}
SplayTree Insert(ElementType Item, SplayTree T)
{
	static Position NewNode = NULL;
	if (NewNode == NULL)
	{
		NewNode = malloc(sizeof(struct SplayNode));
		if (NewNode == NULL)
			perror("Out of space!");
	}
	NewNode->Element = Item;
	if (T == NullNode)
	{
		NewNode->Left = NewNode->Right = NullNode;
		T = NewNode;
	}
	else
	{
		T = Splay(Item, T);
		if (Item < T->Element)
		{
			NewNode->Left = T->Left;
			NewNode->Right = T;
			T->Left = NullNode;
			T = NewNode;
		}
		else if (T->Element<Item)
		{
			NewNode->Right = T->Right;
			NewNode->Left = T;
			T->Right = NullNode;
			T = NewNode;
		}
		else
			return T;
	}
	NewNode = NULL;
	return T;
}
SplayTree Remove(ElementType Item, SplayTree T)
{
	Position NewTree;
	if (T != NullNode)
	{
		T = Splay(Item, T);//找到离该点最近的节点
		if (Item == T->Element)
		{
			if (T->Left == NullNode)
				NewTree = T->Right;
			else
			{
				NewTree = T->Left;
				NewTree = Splay(Item, NewTree);
				NewTree->Right = T->Right;
			}
			free(T);
			T = NewTree;
		}
	}
	return T;
}
/*根节点*/
ElementType Retrieve(SplayTree T)
{
	return T->Element;
}
SplayTree Splay(ElementType Item, Position X)
{
	static struct SplayNode Header;
	Position LeftTreeMax, RightTreeMin;
	/*Header节点使得X接到R的最大节点上而不必担心R是空的*/
	Header.Left = Header.Right = NullNode;
	LeftTreeMax = RightTreeMin = &Header;
	NullNode->Element = Item;//一个单节点，值为Item
	//一个回溯，直到底循环结束
	while (Item != X->Element)
	{
		if (Item < X->Element)//左左
		{
			if(Item<X->Left->Element)
				X = SingleRotateWithLeft(X);//左左
			if (X->Left == NullNode)
				break;//到底
			RightTreeMin->Left = X;
			RightTreeMin = X;
			X = X->Left;
		}
		else//右
		{
			if (Item > X->Right->Element)
				X = SingleRotateWithRight(X);
			if (X->Right == NullNode)
				break;
			LeftTreeMax->Right = X;
			LeftTreeMax = X;
			X = X->Right;
		}
	}//while Item != X->Element
	/*重建*/
	LeftTreeMax->Right = X->Left;
	RightTreeMin->Left = X->Right;
	X->Left = Header.Right;//*
	X->Right = Header.Left;
	return X;
}
