#ifndef _STACK_H_
#define _STACK_H_

#include "tree.h"

#define STACK_SIZE 100   /* 存储空间初始分配量 */

#define StackType struct Tree *

struct Stack
{
	StackType *base;       //栈底指针
	StackType *top;        //栈顶指针
	int stacksize;   //当前栈剩余的存储空间，以元素为单位
};

struct Stack *InitStack(); //创建一个栈

void PushStack(struct Stack *S,StackType e);//压栈

StackType PopStack(struct Stack *S);//出栈

int EmptyStack(struct Stack *S); //若栈S为空，返回1， 否则返回0

StackType TopStack(struct Stack *S);//返回栈顶元素，不出栈

#endif