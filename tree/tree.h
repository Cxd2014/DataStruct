/* 二叉树的基本操作 */
#define ERROR -1
#define TRUE  1

typedef char ElemType;

struct Tree
{
	ElemType data;  
	struct Tree *Lchild,*Rchild; //左右孩子指针
};

/* 非递归算法实现创建二叉树，成功返回二叉树根节点指针，失败返回 NULL */
struct Tree *CreateTree(char *ch);

/* 递归算法实现先序遍历二叉树 */
int PreOrderTraverse(struct Tree *T);