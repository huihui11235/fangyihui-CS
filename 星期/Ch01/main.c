#include <stddef.h>
#ifndef _List_H
#include <stdio.h>
#include <malloc.h>

struct Node;

typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;
List MakeEmpty( List L );
int IsEmpty( List L);
int IsLast( Position P, List L);
Position Find(ElementType X, List L);
void Delete( ElementType X, List L);
Position FindPrevious( ElementType X, List L);
void Insert( ElementType X, List L, Position P);
void DeleteList( List L);
Position Header( List L );
Position First( List L );
Position Advance( Position P);
ElementType Retrieve( Position P );
#endif /*_List_H*/
/*Place in the implementation file */
//链表的声明类型//

struct Node {
	ElementType Element;
	Position Next;
};

/*Return true if L is empty */
int
IsEmpty( List L) {
	return L->Next == NULL;

}


//测试当前位置是否是链表的末尾函数//
/*Return true if P is the last position in list L*/
/*Parameter L is unused in this implementation */
int

IsLast( Position P, List L) {
	return P->Next == NULL;
}

//find例程//
/*Return Position of X in L; NULL if not found*/
Position

Find( ElementType X, List L) {
	Position P;
	P = L->Next;
	while (P != NULL && P->Element != X)
		P = P->Next;
	return P;

}
//列表的删除例程//
/*Delete first occurrence of X from a list*/
/*Assume use of a header node*/
void

Delete( ElementType X, List L) {
	Position P;
	Position Tmp;

	P = FindPrevious(X, L);
	if ( !IsLast( P, L)) { /* Assumption of header use*/
		/* X is found;delete it */
		Tmp = P->Next;
		P->Next = Tmp->Next; /* Bypass deleted cell*/
		free(Tmp);
	}
}
/*If X is not found,then Next field of returned*/
/*Position is NULL */
/* Assumes a header*/
Position

FindPrevious( ElementType X, List L) {
	Position P;
	P = L;
	while ( P->Next != NULL && P->Next->Element != X)
		P = P->Next;
	return P;

}
//Findprevious——与Delete一起使用的Find例程//
/*Insert (after legal position P)*/
/* Headerimplementation assumed*/
/*arameter L is unused in this implementation */
void

Insert( ElementType X, List L, Position P) {
	Position Tmp;
	Tmp = malloc( sizeof( struct Node ));
	if ( Tmp == NULL )
		printf("out of space!!!");
	Tmp->Element = X;
	Tmp->Next = P->Next;
	P->Next = Tmp;
}
//链表的插入例程//

/* Correct DeleteList algorithm */
void
DeleteList( List L) {
	Position P, Tmp;
	P = L->Next; /* Header assumed*/
	L->Next = NULL;
	while ( P != NULL ) {

		Tmp = P->Next;
		free( P);
		P = Tmp;
	}
}

PtrToNode create( int n) { //创建一个链表
	List Head, p, r;
	Head = (List)malloc(sizeof(struct Node));
	if (Head == NULL)
		printf("内存分配不成功！\n");
	else {
		Head->Next = NULL;
		r = Head;
		for (int i = 0; i < n; i++) {
			p = (List)malloc(sizeof(struct Node));
			if (p == NULL)
				printf("内存分配不成功！\n");
			else {
				p->Element = i + 1;
				r->Next = p;
				r = p;
				printf("%4d", p->Element);
			}

		}
		printf("\n");
		r->Next = NULL;
	}
	return Head;
}

void show(List L) {
	List p;
	p = L->Next;
	while (p != NULL) {
		printf("%4d", p->Element);
		p = p->Next;
	}
	printf("\n");
}

int main(void) {
	List l;
	l = create(10);
	Delete( 4, l);
	show(l);
	DeleteList(l);
	show(l);
	


	return 0;
}

