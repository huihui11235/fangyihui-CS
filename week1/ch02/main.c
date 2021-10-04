#include <stdio.h>
#include <stdlib.h>
#ifndef _List_H
#define MaxDegree 100
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

typedef struct StackRecord {
	ElementType date[MaxDegree];
	int top;
	int bottom;
} stack;

typedef struct {
	int CoeffArray[MaxDegree + 1];
	int HighPower;
} *Polynomial;

void
ZeroPolynomial(Polynomial Poly) {
	int i;
	for (i = 0; i <= MaxDegree; i++)
		Poly->CoeffArray[i] = 0;
	Poly->HighPower = 0;
}

int Max(int m, int n) {
	if (m > n)
		return m;

	else {
		return n;
	}
}

void
AddPolynomial(const Polynomial Poly1,
              const Polynomial Poly2, Polynomial PolySum) {
	int i;
	ZeroPolynomial( PolySum );
	PolySum->HighPower = Max( Poly1->HighPower,
	                          Poly2->HighPower);
	for ( i = PolySum->HighPower; i >= 0; i-- )
		PolySum->CoeffArray[ i ] = Poly1->CoeffArray[ i]
		                           + Poly2->CoeffArray[ i ];
}//两个多项式相加的过程//

void
MultPolynomial( const Polynomial Poly1,
                const Polynomial Poly2, Polynomial PolyProd) {
	int i, j;
	ZeroPolynomial( PolyProd);
	PolyProd->HighPower = Poly1->HighPower + Poly2->HighPower;
	if (PolyProd->HighPower > MaxDegree )
		printf("Exceeded array size");
	else
		for ( i = 0; i <= Poly1->HighPower; i++)
			for (j = 0; j <= Poly2->HighPower; j++)
				PolyProd->CoeffArray[i + j] +=
				    Poly1->CoeffArray[i] *
				    Poly2->CoeffArray[j];
}//两个多项式相乘的过程//

void PrintPoly(const Polynomial Q) {
	int i;
	for (i = Q->HighPower; i > 0; i--)
		// CoeffArray[i]代表系数，i代表指数
		printf("%dx^%d + ", Q->CoeffArray[i], i);
	printf("%d\n", Q->CoeffArray[0]);
}


int main(void) {
	Polynomial P, Q;
	P = (Polynomial) malloc(sizeof(*P));
	Q = (Polynomial) malloc(sizeof(*Q));

	P->HighPower = 1;
	P->CoeffArray[0] = 1;
	P->CoeffArray[1] = 1;
	MultPolynomial(P, P, Q);
	MultPolynomial(Q, Q, P);
	AddPolynomial(P, P, Q);
	PrintPoly(Q);
	return 0;
}
