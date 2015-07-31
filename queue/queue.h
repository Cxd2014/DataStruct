/* 单链队列 -- 队列的链式存储结构 */

#define ERROR 0
#define TRUE  1

struct Node
{
	int data;
	struct Node *next;
};

struct Queue
{
	struct Node *head; //对头指针
	struct Node *tail; //队尾指针
};

/* 创建一个空队列，成功返回队列指针，失败返回 NULL */
struct Queue *InitQueue();

/* 显示所有队列元素 无返回值*/
void ShowQueue(struct Queue *Q);

/* 进队函数，成功返回 TRUE 失败返回 ERROR */
int InQueue(struct Queue *Q,int e);

/* 出队函数，成功返回 TRUE 失败返回 ERROR */
int OutQueue(struct Queue *Q);