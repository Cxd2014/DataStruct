#include "tree.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
	//int err;
	struct Tree *T;
	char *ch = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
	T = CreateTree(ch);

	printf("递归先序遍历\n");
	PreOrderTraverse(T);
	printf("\n");

	printf("递归中序遍历\n");
	InOrderTraverse(T);
	printf("\n");

	printf("递归后序遍历\n");
	PostOrderTraverse(T);
	printf("\n");

	printf("非递归先序遍历\n");
	PreOrderTraverseStack(T);
	printf("\n");

	printf("非递归中序遍历\n");
	InOrderTraverseStack(T);
	printf("\n");

	printf("非递归后序遍历\n");
	PostOrderTraverseStack(T);
	printf("\n");
	return 0;
}