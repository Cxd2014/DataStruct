#ifndef TREE_H
#define TREE_H

/* 二叉树的基本操作 */
#define ERROR -1
#define TRUE  1
#define LENGTH 20 //节点数据的最大长度

extern char *str;
typedef char ElemType; 

struct Tree
{
    ElemType data[LENGTH];  
	struct Tree *Lchild,*Rchild; //左右孩子指针
};


/* 创建二叉树，成功返回二叉树根节点指针，失败返回 NULL */
struct Tree *CreateTree(ElemType *ch,int begin,int end);

/* 递归算法实现后序遍历二叉树 成功返回 TRUE 失败返回ERROR*/
int PostOrderTraverse(struct Tree *T);

/* 递归算法实现先序遍历二叉树 */
int PreOrderTraverse(struct Tree *T);

#endif