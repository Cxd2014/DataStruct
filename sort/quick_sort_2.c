//快速排序法二

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 15

void quick_sort(int s[], int l, int r);

int main(int argc, char const *argv[])
{
    int i;
    int a[MAX];
    srand(time(NULL));

    for(i=0;i<MAX;i++){ //产生随机数
        a[i] = rand()%100;
        printf("%d ",a[i]);
    }

    printf("\n");
    quick_sort(a,0,MAX-1);

    return 0;
}

void quick_sort(int s[], int l, int r)
{
    if (l < r){
        int i = l, j = r, x = s[l];//初始化
        while (i < j){
            while(i < j && s[j] >= x) // 从右向左找第一个小于x的数，如果不小于j就前移
                j--;

            if(i < j)
                s[i++] = s[j];//填坑并将i后移一个位置
 
            while(i < j && s[i] < x) // 从左向右找第一个大于等于x的数，如果小于i就后移
                i++;

            if(i < j)
                s[j--] = s[i];//填坑并将j前移一个位置
        }//退出while

        s[i] = x;
        quick_sort(s, l, i - 1); // 递归调用
        quick_sort(s, i + 1, r);
    }
}