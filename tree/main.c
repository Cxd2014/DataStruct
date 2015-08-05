#include "tree.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int err;
	struct Tree *T;
	char *ch = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
	T = CreateTree(ch);
	err = PreOrderTraverse(T);
	printf("\n");
	printf("err = %d\n",err);
	return 0;
}