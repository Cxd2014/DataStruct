#define ERROR 0
#define TRUE  1

/* 定义一个双向链表节点 */
struct Node
{
	int data;
	struct Node *prior; //前驱节点
	struct Node *next;  //后继节点
};

/* 创建一个双向链表，成功返回链表指针，错误返回 NULL */
struct Node *CreateList(void);

/* 遍历链表中的所有元素，并打印出来 无返回值*/
void ShowList(struct Node * pHead); 

/* 在第i个节点处插入一个元素值为 val 成功返回 TRUE 失败返回 ERROR */
int InsertList(struct Node * pHead,int i,int val); 

/* 将第i个节点删除 成功返回 TRUE 失败返回ERROR */
int DeleteList(struct Node * pHead,int i);

/* 查找链表元素值为 val 的节点，成功返回该节点的指针 失败返回 NULL */
struct Node *FindList(struct Node * pHead,int val);