/*
* 栈和队列的学习
*/
#include "stack.h"
#include <stdio.h>

int main()
{	
	int e;
	struct Stack *S;
	S  = InitStack(); //初始化栈

	PushStack(S,4);//入栈
	PushStack(S,5);

	e = PopStack(S); //出栈
	printf("The top num = %d \n",e);

	e = PopStack(S);
	printf("The top num = %d \n",e);

	return 0;
}

