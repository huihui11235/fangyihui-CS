#ifndef _Cursor_H

typedef int PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

typedef int ElementType;

void InitializeCursorSpace( void);

List MakeEmpty( List L);
int IsEmpty( const List L );
int IsLast(const Position P, const List L);
Position Find( ElementType X, const List L);
void Delete( ElementType X, List L);
Position FindPrevious( ElementType X, const List L);
void Insert( ElementType X, List L, Position P);
void DeleteList( List L);
Position Header( const List L);
Position First( const List L);
Position Advance( const Position P );
ElementType Retrieve( const Position P );

#endif _Cursor_H

/*Place in the implementationfile */

#include <stdio.h>
#include <stdlib.h>
#define SpaceSize 100
struct Node {
	ElementType Element;
	Position Next;
};
struct Node CursorSpace[ SpaceSize ];
//链表游标实现的声明//

static Position
CursorA1loc( void) {
	Position P;
	P = CursorSpace[ 0 ].Next;
	CursorSpace[ 0 ].Next = CursorSpace[ P ].Next;
	return P;
}
static void

CursorFree( Position P) {
	CursorSpace[ P ].Next = CursorSpace[ 0 ].Next;
	CursorSpace[ 0 ].Next = P;
}
//CursorA1loc申请一个位置用来存放新数据和CursorFree释放p所指向的数据及其空间//

/*Return true if L is empty*/
void
InitializeCursorSpace(void) {
	int i;
	for (i = 0; i < SpaceSize; i++)
		CursorSpace[i].Next = i + 1;
	CursorSpace[SpaceSize - 1].Next = 0;
}

//初始化//
List MakeEmoty(List L) {
	if (L != NULL)
		DeleteList(L);
	L = CorsorAlloc();
	if (L == 0)
		printf("Out of memory");
	CursorSpace[L].Next = 0;
	return L;
}

int
IsEmpty( List L ) {
	return CursorSpace[ L ].Next == 0;
}
//测试一个链表是否为空的函数——游标实现//
/*Return true if P is the last position in list L */
/* Parameter L is unused in this implementation */

int
IsLast( Position P, List L) {
	return CursorSpace[ P ].Next == 0;
}
//测试 P是否是链表的末尾的函数——游标实现//

/* Return Position of X in L; 0 if not found*/
/* Uses a header node */
Position
Find( ElementType X, List L ) {
	Position P;
	P = CursorSpace[ L].Next;
	while ( P && CursorSpace[ P ].Element != X)
		P = CursorSpace[ P].Next;
	return P;
}
//例程 Pind——游标实现//

/* Delete first occurrence of X from a list */
/* Assume use of a header node*/
void
Delete( ElementType X, List L) {
	Position P, TmpCell;
	P = FindPrevious(X, L);
	if ( !IsLast( P, L)) { /* Assumption of header use */
		/* X is found; delete it */
		TmpCell = CursorSpace[ P ].Next;
		CursorSpace[ P ].Next = CursorSpace[TmpCell].Next;
		CursorFree( TmpCell);
	}
}
//对链表进行删除操作的例程 Delete——游标实现//
Position

FindPrevious( ElementType X, List L) {
	Position P;
	P = L;
	while ( CursorSpace[P].Next && CursorSpace[CursorSpace[P].Next].Element != X)
		P = CursorSpace[P].Next;
	return P;
}

/*Insert (after legal position P)*/
/*Header implementation assumed*/
/*Parameter L is unused in this implementation*/
void
Insert( ElementType X, List L, Position P) {

	Position TmpCell;
	TmpCell = CursorAlloc();
	if (TmpCell == 0)
		printf("Out of space!!!");
	CursorSpace[TmpCell].Element = X;
	CursorSpace[TmpCell].Next = CursorSpace[ P ].Next;
	CursorSpace[ P ].Next = TmpCell;
}
//对链表进行插入操作的例程Ingert——游标实现//
