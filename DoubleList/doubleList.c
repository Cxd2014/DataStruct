#include "doubleList.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

/* 创建一个双向链表，成功返回链表指针，错误返回 NULL */
struct Node *CreateList(void)
{
	int len;
    int i;
    //创建头节点
    struct Node *pHead = (struct Node *)malloc(sizeof(struct Node));  
    if (NULL == pHead){
    	printf("内存分配失败！\n");
    	return NULL;
    }   
    pHead->prior = NULL; //将前驱节点指向头节点本身
	pHead->next  = NULL;
	

	printf("请输入链表节点个数：");
	scanf("%d",&len);

	for(i = 0 ; i < len ; i++){
		struct Node *pNew = (struct Node *)malloc(sizeof(struct Node));
		if(NULL == pNew){
			printf("内存分配失败！");
			return NULL;
		}

		pNew->data = i+1;//节点值
		pNew->next = pHead->next;
		pHead->next = pNew;  //将 pNew 节点放在 pHead 节点后面
	} 

	struct Node *p,*q; // 初始化前驱节点
	p = pHead;
	while (NULL != p){
		q = p;
		p = p->next;
		if(NULL != p)
			p->prior = q;
	}

	printf("the size of struct = %d\n", sizeof(struct Node));
	pHead->data = i+1;  //给头指针赋值

	return pHead; 
}


/* 遍历链表中的所有元素，并打印出来 成功返回 1 失败返回 0*/
void ShowList(struct Node * pHead)
{
	struct Node * p = pHead;
	struct Node * q;

	while (NULL != p){
		printf("%d ", p->data);
		q = p;
		p = p->next;
	}

	printf("\n");
	while (NULL != q){
		printf("%d ", q->data);
		q = q->prior;
	}
	printf("\n\n");
}

/* 在第i个节点处插入一个元素值为 val 成功返回 TRUE 失败返回ERROR */
int InsertList(struct Node * pHead,int i,int val)
{
	struct Node *p = pHead;
	int j = 0;

	if(i<1)
		return ERROR;

	while(p && (j<i-1)) { //寻找第 i-1 个节点
		p = p->next;
		++j;
	}

	if(p == NULL)
			return ERROR;

	struct Node *s =  (struct Node *)malloc(sizeof(struct Node));
	if(NULL == s) {
		printf("内存分配失败！");
		return ERROR;
	}

	s->data = val;
	s->next = p->next;
	p->next->prior = s;
	p->next = s;
	s->prior = p;

	return TRUE;
}

/* 将第i个节点删除 成功返回 TRUE 失败返回ERROR */
int DeleteList(struct Node * pHead,int i)
{
	struct Node *p = pHead;
	int j = 0;

	if(i<1)
		return ERROR;

	while(p && (j<i-1)) { //寻找第 i-1 个节点，要删除元素的前一个节点
		p = p->next;
		++j;
	}

	if(p == NULL)
			return ERROR;

	struct Node *q;

	// p 是要删除元素的前一个节点
	q = p->next; //将要删除的节点赋值给q
	p->next = q->next; 
	q->next->prior = p;
	free(q); //释放 q 占用的内存

	return TRUE;
}

/* 查找链表元素值为 val 的节点，成功返回该节点的指针 失败返回 NULL */
struct Node *FindList(struct Node * pHead,int val)
{
	struct Node *p = pHead;

	while(p != NULL) { 
		if(val == p->data)
			return p;
		p = p->next;
	}
	return NULL;
}