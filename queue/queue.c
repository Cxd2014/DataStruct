#include "queue.h"
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>

/* 创建一个空队列，成功返回队列指针，失败返回 NULL */
struct Queue *InitQueue()
{
	struct Queue *Q;
	Q = (struct Queue *)malloc(sizeof(struct Queue));
	Q->head = (struct Node *)malloc(sizeof(struct Node));
	if(Q->head == NULL){
		printf("malloc error\n");
		return NULL;
	}
	Q->tail = Q->head;
	Q->head->next = NULL;
	return Q;
}

/* 显示所有队列元素 无返回值*/
void ShowQueue(struct Queue *Q)
{
	struct Node * p = Q->head->next; //从对头的下一个元素开始显示

	while (NULL != p){
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

/* 进队函数，成功返回 TRUE 失败返回 ERROR */
int InQueue(struct Queue *Q,int e)
{
	struct Node *p;
	p = (struct Node *)malloc(sizeof(struct Node));
	if(p == NULL){
		printf("malloc error\n");
		return ERROR;
	}

	p->data = e;
	p->next = NULL;
	Q->tail->next = p;
	Q->tail = p;
	return TRUE;
}

/* 出队函数，成功返回 TRUE 失败返回 ERROR */
int OutQueue(struct Queue *Q)
{
	struct Node *p;
	if(Q->head == Q->tail){
		printf("The Queue is empty!");
		return ERROR;
	}

	p = Q->head->next;
	Q->head->next = p->next;
	if(Q->tail == p) //如果删除的是队尾元素，要将队尾指针指向对头指针
		Q->tail = Q->head;
	free(p);
	return TRUE;
}