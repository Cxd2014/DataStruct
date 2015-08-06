#ifndef _TREE_H_
#define _TREE_H_

/* 二叉树的基本操作 */
#define ERROR -1
#define TRUE  1

typedef char ElemType;

struct Tree
{
	ElemType data;  
	struct Tree *Lchild,*Rchild; //左右孩子指针
};


/* 非递归算法实现创建二叉树，成功返回二叉树根节点指针，失败返回 NULL */
struct Tree *CreateTree(ElemType *ch);

/* 递归算法实现先序遍历二叉树 成功返回 TRUE 失败返回ERROR*/
int PreOrderTraverse(struct Tree *T);

/* 递归算法实现中序遍历二叉树 成功返回 TRUE 失败返回ERROR*/
int InOrderTraverse(struct Tree *T);

/* 递归算法实现后序遍历二叉树 成功返回 TRUE 失败返回ERROR*/
int PostOrderTraverse(struct Tree *T);

/* 非递归算法实现先序遍历二叉树 成功返回 TRUE 失败返回ERROR*/
int PreOrderTraverseStack(struct Tree *T); 

/* 非递归算法实现中序遍历二叉树 成功返回 TRUE 失败返回ERROR*/
int InOrderTraverseStack(struct Tree *T); 

/* 非递归算法实现后序遍历二叉树 成功返回 TRUE 失败返回ERROR*/
int PostOrderTraverseStack(struct Tree *T);

#endif