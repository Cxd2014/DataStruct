#define STACK_SIZE 100   /* 存储空间初始分配量 */

typedef void NoReturn;

struct Stack
{
	int *base;       //栈底指针
	int *top;        //栈顶指针
	int stacksize;   //当前栈剩余的存储空间，以元素为单位
};

struct Stack *InitStack(); //创建一个栈

NoReturn PushStack(struct Stack *S,int e);//压栈

int PopStack(struct Stack *S);//出栈
