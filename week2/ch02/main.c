#include "tree.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define FatalError( Str )   fprintf( stderr, "%s\n", Str ), exit( 1 )
struct TreeNode {
	int Element;
	SearchTree Left;
	SearchTree Right;
};

//建立空树//
SearchTree MakeEmpty(SearchTree T) {
	if (T != NULL) {
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}

SearchTree Insert(int x, SearchTree T) {
	if (T == NULL) {
		T = (SearchTree)malloc(sizeof(struct TreeNode)); //申请内存//
		if (T == NULL)
			printf("Out of space");
		else {
			T->Element = x;
			T->Left = T->Right = NULL;
		}
	} else if (x < T->Element)
		T->Left = Insert(x, T->Left);
	else if (x > T->Element)
		T->Right = Insert(x, T->Right);
	return T;
}

//查找指向x的节点的指针//
Position Find(int x, SearchTree T) {
	if (T == NULL)
		return NULL;
	if (x < T->Element)
		return Find(x, T->Left);
	else if (x > T->Element)
		return Find(x, T->Right);
	else
		return T;
}

//查找最小元//
Position FindMin(SearchTree T) {
	if (T == NULL)
		return NULL;
	else if (T->Left == NULL)
		return T;
	else
		return FindMin(T->Left);
}

Position FindMax(SearchTree T) {
	if (T != NULL)
		while (T->Right != NULL)
			T = T->Right;
	return T;
}


//先序遍历//
void PreorderTraversal(SearchTree T) {
	if (!T)
		return ;
	printf(" %d", T->Element);
	PreorderTraversal(T->Left);
	PreorderTraversal(T->Right);
}

//后序遍历//
void InorderTraversal(SearchTree T) {
	if (!T)
		return ;
	InorderTraversal(T->Left);
	printf(" %d", T->Element);
	InorderTraversal(T->Right);
}

//删除元素//
SearchTree Del(int x, SearchTree T) {
	Position TmpCell;
	if (T == NULL)
		FatalError("Element not found");
	else if (x < T->Element)
		T->Left = Del(x, T->Left);
	else if (x > T->Element)
		T->Right = Del(x, T->Left);
	else if (T->Left && T->Right) {
		TmpCell = FindMin(T->Right);
		T->Element = TmpCell->Element;
		T->Right = Del(T->Element, T->Right);
	} else {
		TmpCell = T;
		if (T->Left == NULL)
			T = T->Right;
		else if (T->Right == NULL)
			T = T->Left;
		free(TmpCell);

	}
	return T;

}

int main() {
	SearchTree BST, MinP, MaxP, Tmp;
	int X;
	int N, i;
	printf("输入节点数：\n");

	BST = NULL;
	scanf("%d", &N);
	printf("输入树中的元素：");
	for (i = 0; i < N; i++) {
		scanf("%d", &X);
		BST = Insert(X, BST);
	}
	printf("先序遍历");
	PreorderTraversal(BST);
	printf("\n");
	MinP = FindMin(BST);
	MaxP = FindMax(BST);
	printf("输入节点数：\n");
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		printf("输入寻找的元素：");
		scanf("%d", &X);
		Tmp = Find(X, BST);
		if (Tmp == NULL)
			printf("%d 不在树内\n", X);
		else {
			printf("%d 在树内\n", Tmp->Element);
			if (Tmp == MinP)
				printf("%d 是最小元\n", Tmp->Element);
			if (Tmp == MaxP)
				printf("%d 是最大元\n", Tmp->Element);
		}
	}
	printf("输入树中的元素：");
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &X);
		BST = Del(X, BST);
	}
	printf("后序遍历");
	InorderTraversal(BST);
	printf("\n");
	return 0;
}
