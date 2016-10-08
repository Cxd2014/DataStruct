#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tree.h"

/* README
*  利用二叉树解析数学表达式并计算结果
*  # make (生成可执行文件calculate)
*  # ./calculate 3+\(3.3+3+4*5.4+2+3*2\)*2+3.2*\(3+2\)
*/

char *str = NULL;

double calculateResult()
{
    int len = strlen(str);
    int count = 0;
    int index = 0;
    double Num[10] = {0.0};

    while(count <= len)
    {
        int i = 0; 
        char a[10] = {0};

        while(str[count + i] != ' ' && str[count + i] != '\0')
        {
            a[i] = str[count + i];
            i++;
        }

        if(a[0] == '+'){
            Num[index-2] = Num[index-2] + Num[index-1];
            index--;
           
        }else if(a[0] == '-'){
            Num[index-2] = Num[index-2] - Num[index-1];
            index--;  

        }else if(a[0] == '*'){
            Num[index-2] = Num[index-2] * Num[index-1];
            index--;
            
        }else if(a[0] == '/'){
            Num[index-2] = Num[index-2] / Num[index-1];
            index--;
            
        }else{
            Num[index] = atof(a);
            index++;
        }
        count = count + i + 1;
    }
    return Num[index-2];
}

int main(int argc, char **argv)
{
    printf("argv[1] = %s\n",argv[1]);

    str = (char *)malloc(128);
    if(str == NULL){
        printf("error\n");
        return -1;
    }

    /* 生成二叉树 */
    struct Tree *T;
    int end = strlen(argv[1]);
    T = CreateTree(argv[1],0,end-1);

    /*  
        去括号,如果有多级括号嵌套可以先计算出有多少级括号嵌套，
        然后重复调用此函数,这里我就懒得去做了
    */
    PreOrderTraverse(T);

    /* 后序遍历生成逆波兰表达式，复制到 str 中 */
    PostOrderTraverse(T);
    printf("str = %s\n",str);

    /* 根据波兰表达式计算结果 */
    double result = 0.0;
    result = calculateResult();
    printf("result = %f\n",result);

    free(str);
    return 0;
}


