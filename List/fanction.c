#include "list.h"
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>


//创造链表函数，返回值是链表的头指针
struct Node *CreateList(void)
{
    int len;
    int i;

    //创建头节点
    struct Node *pHead = (struct Node *)malloc(sizeof(struct Node));  
    if (NULL == pHead)
    {
    	printf("内存分配失败！\n");
    	exit(-1);
    }    
    pHead->Next = NULL;

	printf("请输入链表节点个数：");
	scanf("%d",&len);

	for(i = 0 ; i < len ; i++)
	{
		struct Node *pNew = (struct Node *)malloc(sizeof(struct Node));
		if(NULL == pNew)
		{
			printf("内存分配失败！");
			exit(-1);
		}

		pNew->data = i+1;//节点值
		pNew->Next = pHead->Next;
		pHead->Next = pNew;//将 pNew 节点放在 pHead 节点后面
	} 
	printf("the size of struct = %d\n", sizeof(struct Node));
	pHead->data = i+1; //给头指针赋值
	return pHead; 
}

//遍历链表中的所有元素，并打印出来
void ShowList(struct Node * pHead)
{
	struct Node * p = pHead;

	while (NULL != p)
	{
		printf("%d ", p->data);
		p = p->Next;
	}
	printf("\n");
}

//在第i个节点处插入一个元素值为 val 
void InsertList(struct Node * pHead,int i,int val)
{
	struct Node *p = pHead;
	int j = 0;

	while(p && (j<i-1)) { //寻找第 i-1 个节点
		p = p->Next;
		++j;
	}

	if(!p || (j > i-1)) {
		printf("i小于1或者大于链表长度！\n");
		exit(-1);
	}

	struct Node *s =  (struct Node *)malloc(sizeof(struct Node));
	if(NULL == s) {
		printf("内存分配失败！");
		exit(-1);
	}

	s->data = val;
	s->Next = p->Next;
	p->Next = s;
}

//将第i个节点删除
void DeleteList(struct Node * pHead,int i)
{
	struct Node *p = pHead;
	int j = 0;

	while(p && (j<i-1)) { //寻找第 i-1 个节点，要删除元素的前一个节点
		p = p->Next;
		++j;
	}

	if(!p || (j > i-1)) {
		printf("你要删除的节点不在链表内！\n");
		exit(-1);
	}

	struct Node *q;

	// p 是要删除元素的前一个节点
	q = p->Next; //将要删除的节点赋值给q
	p->Next = q->Next; 
	free(q); //释放 q 占用的内存

}

 // 查找第 i 个节点的值
void GetList(struct Node * pHead,int i)
{
	struct Node *p = pHead;
	int j = 0;

	while(p && (j<i)) { //寻找第 i 个节点
		p = p->Next;
		++j;
	}

	if(!p || (j > i)) {
		printf("你要找的节点不在链表内！\n");
		exit(-1);
	}

	printf("第%d个节点的值是：%d\n",i,p->data);
}

//倒序链表
struct Node *ReverseList(struct Node * pHead)
{
	if(pHead == NULL || pHead->Next == NULL)
		return pHead;
	
	struct Node *p,*p1,*p2;

	p = pHead;
	p1 = p->Next;
	p->Next = NULL;

	while(p1 != NULL){

		p2 = p1->Next; 
		p1->Next = p;
		p = p1;
		p1 = p2;

	}
	return p;
}

//链表排序
void SortList(struct Node * pHead)
{
	struct Node *p,*p1;
	int i = 0;

	p = pHead;
	p1 = pHead->Next;
	
	while(p != NULL){
		while(p1 != NULL){
			if(p->data <= p1->data){
				i = p1->data;
				p1->data = p->data;
				p->data = i;
			}
			p1 = p1->Next;
		}
		p1 = p->Next;
		p = p->Next;
	}
}