//树的节点声明
typedef struct TreNode *PtrToNode;
struct TreeNode
{
    ElementType Element;
    PtrToNode FirstChild;
    PtrToNode NextSibling;
};
//二叉树节点声明
typedef struct BinaryTreeNode *PtrNode;
typedef struct PtrNode Tree;
struct BinaryTreeNode
{
    ElementType Element;
    Tree Left;
    Tree Right;
};
//AVL树节点声明
#ifndef AVLTREE_H
struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;
typedef int ElementType;

AvlTree MakeEmpty(AvlTree T);
Position Find(int X, AvlTree T);
Position FindMin(AvlTree T);
Position FindMax(AvlTree T);
AvlTree Insert(int X, AvlTree T);
AvlTree Delete(int X, AvlTree T);
int Retrieve(Position P);
void PostOrderTraversal(AvlTree T);
void InOrderTraversal(AvlTree T);
void PreOrderTraversal(AvlTree T);

#endif // AVLTREE_H
struct AvlNode {
	int Element;
	AvlTree Left;
	AvlTree Right;
	int Height;
};
