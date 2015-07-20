//定义一个链表节点
struct Node
{
	int data;
	struct Node *Next;
};

struct Node *CreateList(void);//创造链表函数，返回值是链表的头指针

void ShowList(struct Node * pHead); //遍历链表中的所有元素，并打印出来

void GetList(struct Node * pHead,int i); // 查找第 i 个节点的值

void InsertList(struct Node * pHead,int i,int val); //在第i个节点处插入一个元素值为 val 

void DeleteList(struct Node * pHead,int i); //将第i个节点删除

struct Node *ReverseList(struct Node * pHead);//链表倒序

void SortList(struct Node * pHead); //链表排序,按照从大到小排列