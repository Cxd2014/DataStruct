#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

/* 按先序次序创建二叉树，成功返回二叉树指针，失败返回 NULL */
struct Tree *CreateTree(char *ch)
{
	struct Tree *T;
	int i = 0;
	int j = 0;
	int len = strlen(ch);
	struct Tree **queue; //用于保存每个节点的地址
	queue = (struct Tree **)malloc(len*sizeof(struct Tree *));

	for(i=0;i<len;i++){
		T = (struct Tree *)malloc(sizeof(struct Tree));
		if(T == NULL)
			return NULL;
		T->data = *(ch + i);
		T->Lchild = NULL;
		T->Rchild = NULL;
		queue[i] = T;

		if(i>=1){ // queue[0] 为根节点 
			if(i%2 == 1) //新节点为左子树
				queue[j]->Lchild = T;
			else{ //新节点为右子树
				queue[j]->Rchild = T;
				j++;
			}
		}
	}
	T = queue[0]; //将第一个节点作为根节点
	return T; 
}

/* 递归算法实现先序遍历二叉树 */
int PreOrderTraverse(struct Tree *T)
{
	if(T != NULL){
		printf("%c ",T->data);
		if(PreOrderTraverse(T->Lchild))
			if(PreOrderTraverse(T->Rchild))
				return TRUE;
	}else
		return TRUE;
}