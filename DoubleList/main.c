#include "doubleList.h"
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
	struct Node *pHead;
	pHead = CreateList(); //创建一个双向链表
	if(pHead == NULL){
		printf("CreateList error\n");
		exit(0);
	}
	ShowList(pHead);

	if(InsertList(pHead,4,80) == ERROR){ //插入一个元素
		printf("InsertList error\n");
		exit(0);
	}
	ShowList(pHead);

	if(DeleteList(pHead,6) == ERROR){ // 删除一个元素
		printf("DeleteList error\n");
		exit(0);
	}
	ShowList(pHead);

	struct Node *p; // 在链表查找元素
	p = FindList(pHead,3);
	if(p == NULL){
		printf("没有找到节点\n");
	}else{
		printf("The val of the node is %d\n",p->data);
	}
	return 0;
}