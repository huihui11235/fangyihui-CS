#ifndef _RedBlackTree_H
#define Infinity 10000
#define NegInfinity -10000
#include<stdio.h>
typedef enum ColorType{Red,Black} ColorType;
typedef int ElementType;
typedef struct RedBlackNode* Position;
typedef Position RedBlackTree;

Position NullNode = NULL;

RedBlackTree Initialize(void);
static void DoPrint(RedBlackTree T);
void PrintTree(RedBlackTree T);
static Position Rotate(ElementType Item, Position Parrnt);
static void HandleReorient(ElementType Item, RedBlackTree T);
RedBlackTree Insert(ElementType Item, RedBlackTree T);

#endif
struct RedBlackNode
{
	ElementType Element;
	RedBlackTree Left;
	RedBlackTree Right;
	ColorType Color;
};
