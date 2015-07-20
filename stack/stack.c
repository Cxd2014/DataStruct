#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

struct Stack *InitStack()
{
	struct Stack *S;
	/*  结构体指针初始化，必须要初始化不然会出现段错误 */
	S = (struct Stack *)malloc(sizeof(struct Stack));

	S->base = (int *)malloc(STACK_SIZE * sizeof(int));
	if(! S->base){
		printf("内存分配失败！\n");
		exit(-1);
	}
	S->top = S->base;
	S->stacksize = STACK_SIZE;

	return S;
}

NoReturn PushStack(struct Stack *S,int e)
{
	struct Stack *p = S;
	if(p->top - p->base >= p->stacksize){ //判断栈是否满，则追加空间
		S->base = (int *)realloc(S->base,((S->stacksize + 10)* sizeof(int)));
		if(! S->base){
			printf("内存分配失败！\n");
			exit(-1);
		}
		S->top = S->base + S->stacksize;
		S->stacksize += 10; 
	}
	*(p->top) = e;
	(p->top)++;
}

int PopStack(struct Stack *S)
{
	int e;
	if(S->top == S->base){
		printf("The stack is null\n");
		exit(-1);
	}
	(S->top)--;
	e = *(S->top);
	return e;
}