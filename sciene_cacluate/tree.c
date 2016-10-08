#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

int indexOfOpt(char *ch,int begin ,int end)   //寻找最后执行的操作符的下标
{
    int i;
    int brackets=0;                    //所在括号层次
    int index = -1;
    int existAddOrMinus = 0;

    for(i = begin;i <= end;i++)
    {
        if(ch[i]=='(')
            brackets++;
        else if(ch[i]==')')
            brackets--;
        else if((ch[i]=='+'||ch[i]=='-')&&brackets==0)
        {
            index = i;
            existAddOrMinus = 1;    //存在加减号
        }
        else if((ch[i]=='*'||ch[i]=='/')&&brackets==0&&existAddOrMinus==0)
        {
            index = i;
        } 
        
    }
    return index;
}

/* 创建二叉树，成功返回二叉树指针，失败返回 NULL */
struct Tree *CreateTree(ElemType *ch,int begin,int end)
{
	struct Tree *T;
    int index = indexOfOpt(ch,begin,end);

    T = (struct Tree *)malloc(sizeof(struct Tree));
    if(T == NULL){
        printf("malloc error !\n");
        exit(-1);
    }
    
    if(index != -1){
        T->data[0] = ch[index];
        T->data[1] = ' '; 
        T->data[2] = '\0';   

        T->Lchild = CreateTree(ch,begin,index-1);
        T->Rchild = CreateTree(ch,index+1,end);
    } else {
        int i,j=0;
        if(end-begin >= LENGTH){
            printf("ERROR the str in Brackets are too long please less than %d \n",LENGTH);
            exit(-1);
        }

        for(i = begin;i <= end;i++) 
            T->data[j++] = ch[i];

        T->data[j] = ' '; 
        T->data[j+1]='\0';
        T->Lchild = NULL;
        T->Rchild = NULL;
    }
	return T; 
}

/* 递归算法实现后序遍历二叉树 成功返回 TRUE 失败返回ERROR*/
int PostOrderTraverse(struct Tree *T)
{
    static int i;
	if(T != NULL){
		if(PostOrderTraverse(T->Lchild))	
			if(PostOrderTraverse(T->Rchild)){
                strcat(str,T->data);
				return TRUE;
			}
	}else
		return TRUE;
}

/*  检查该节点数据中有没有括号，
    如果有括号将括号去除然后将括号内的表达式创建一个子树，
    将子树放置在该节点下 
*/
int checkBrackets(struct Tree *T)
{
    struct Tree *SonT = NULL;
    char ch[LENGTH] = {0};
    char *temp = T->data + 1;
    int len = strlen(T->data);

    if(T->data[0] == '(' && T->data[len-2] == ')'){    

        strncpy(ch,temp,len-3);
        printf("ch = %s\n",ch);
        len = strlen(ch);

        SonT = CreateTree(ch,0,len-1);

        memcpy(T->data,SonT->data,LENGTH);
        T->Lchild = SonT->Lchild;
        T->Rchild = SonT->Rchild;

        free(SonT);
    }

    return TRUE;
}


/* 递归算法实现先序遍历二叉树 */
int PreOrderTraverse(struct Tree *T)
{
    if(T != NULL){
        checkBrackets(T);
        if(PreOrderTraverse(T->Lchild))
            if(PreOrderTraverse(T->Rchild))
                return TRUE;
    }else
        return TRUE;
}
