#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "stack.h"

/* 按先序次序创建二叉树，成功返回二叉树指针，失败返回 NULL */
struct Tree *CreateTree(ElemType *ch)
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
	free(queue);
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

/* 递归算法实现中序遍历二叉树 成功返回 TRUE 失败返回ERROR*/
int InOrderTraverse(struct Tree *T)
{
	if(T != NULL){
		if(InOrderTraverse(T->Lchild)){
			printf("%c ",T->data);
			if(InOrderTraverse(T->Rchild))
				return TRUE;
		}	
	}else
		return TRUE;
}

/* 递归算法实现后序遍历二叉树 成功返回 TRUE 失败返回ERROR*/
int PostOrderTraverse(struct Tree *T)
{
	if(T != NULL){
		if(PostOrderTraverse(T->Lchild))	
			if(PostOrderTraverse(T->Rchild)){
				printf("%c ",T->data);
				return TRUE;
			}
	}else
		return TRUE;
}

/* 非递归算法实现先序遍历二叉树 成功返回 TRUE 失败返回ERROR*/
int PreOrderTraverseStack(struct Tree *T)
{
	struct Stack *S;
	struct Tree *P;
	P = T;
	S = InitStack(); //初始化栈
	while(P != NULL || !EmptyStack(S)){
		if(P != NULL){
			printf("%c ", P->data);
			PushStack(S,P); //入栈
			P = P->Lchild;
		}else{
			P = PopStack(S); //出栈
			P = P->Rchild;
		}
	}
	return TRUE;
}

/* 非递归算法实现中序遍历二叉树 成功返回 TRUE 失败返回ERROR*/
int InOrderTraverseStack(struct Tree *T)
{
	struct Stack *S;
	struct Tree *P;
	P = T;
	S = InitStack(); //初始化栈
	while(P != NULL || !EmptyStack(S)){
		if(P != NULL){
			PushStack(S,P); //入栈
			P = P->Lchild;
		}else{
			P = PopStack(S); //出栈
			printf("%c ", P->data);
			P = P->Rchild;
		}
	}
	return TRUE;
}

/* 非递归算法实现后序遍历二叉树 成功返回 TRUE 失败返回ERROR*/
int PostOrderTraverseStack(struct Tree *T)
{
	struct Stack *S;
	struct Tree *P = T;  //指向当前节点
	struct Tree *Pre = NULL;//指向前一个节点
	S = InitStack(); //初始化栈
	while(P != NULL || !EmptyStack(S)){
		while(P != NULL){
			PushStack(S,P); //入栈
			P = P->Lchild;
		}
		P = TopStack(S);//得到栈顶元素
		if(P->Rchild == NULL || P->Rchild == Pre){
			printf("%c ",P->data);
			Pre = P;
			PopStack(S);//出栈
			P = NULL;
		}else
			P = P->Rchild;
	}
	return TRUE;
}
