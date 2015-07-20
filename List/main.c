#include "list.h"

int main(void)
{
	struct Node *pHead; //pHead用来存放链表头节点的地址
	
	pHead = CreateList(); 

	ShowList(pHead);

	InsertList(pHead,6,11);

	ShowList(pHead);

	DeleteList(pHead,3);

	ShowList(pHead);

	GetList(pHead,4);

	pHead = ReverseList(pHead);

	ShowList(pHead);

	SortList(pHead);

	ShowList(pHead);


	return 0;
}


