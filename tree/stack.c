#include "stk.h"
#include <stdio.h>
#include <stdlib.h>

struct Stack *InitStack()
{
	struct Stack *S;
	/*  结构体指针初始化，必须要初始化不然会出现段错误 */
	S = (struct Stack *)malloc(sizeof(struct Stack));

	S->base = (StackType *)malloc(STACK_SIZE * sizeof(StackType));
	if(! S->base){
		printf("内存分配失败！\n");
		exit(-1);
	}
	S->top = S->base;
	S->stacksize = STACK_SIZE;

	return S;
}

void PushStack(struct Stack *S,StackType e)
{
	struct Stack *p = S;
	if(p->top - p->base >= p->stacksize){ //判断栈是否满，则追加空间
		S->base = (StackType *)realloc(S->base,((S->stacksize + 10)* sizeof(StackType)));
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
 
StackType PopStack(struct Stack *S)
{
	StackType e;
	if(S->top == S->base){
		printf("The stack is null\n");
		exit(-1);
	}
	(S->top)--;
	e = *(S->top);
	return e;
}

/**
 * 若栈S为空，返回1， 否则返回0
 */
int EmptyStack(struct Stack *S)
{
	return (S->base == S->top)?1:0;
}

StackType TopStack(struct Stack *S)//返回栈顶元素，不出栈
{
	StackType *temp;   
	temp = (S->top) - 1;    
	return *(temp);
}
