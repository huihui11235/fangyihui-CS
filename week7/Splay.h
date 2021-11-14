/*自顶向下伸展树*/
#ifndef _Splay_H

struct SplayNode;
typedef struct SplayNode *SplayTree;
typedef int ElementType;

SplayTree MakeEmpty(SplayTree T);
SplayTree Splay(ElementType Item, Position X);
SplayTree Find(ElementType X, SplayTree T);
SplayTree FindMin(SplayTree T);
SplayTree FindMax(SplayTree T);
SplayTree Initialize(void);
SplayTree Insert(ElementType X, SplayTree T);
SplayTree Remove(ElementType X, SplayTree T);
ElementType Retrieve(SplayTree T);

#endif
struct SplayNode
{
	ElementType Element;
	SplayTree Left;
	SplayTree Right;
};
typedef struct SplayNode *Position;
static Position NullNode = NULL;
