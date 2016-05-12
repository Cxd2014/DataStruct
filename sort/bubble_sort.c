/*
* 冒泡排序算法 
* 最大的元素会如同气泡一样移至右端，其利用比较相邻元素的方法，
* 将大的元素交换至右端，所以大的元素会不断的往右移动，直到适当的位置为止
*
* 冒泡排序法可以利用旗标的方式稍微减少一些比较的时间，当寻访完阵列后都没有发生
* 任何的交换动作，表示排序已经完成，而无需再进行之后的回圈比较与交换动作
*/
#include <stdio.h>
#include <stdlib.h>

#define SWAP(x,y) {int t;t=x;x=y;y=t;}

int bubble_sort(int *a,int num);

int main(int argc, char const *argv[])
{
	int a[] = {1,3,2,7,0,8,5,4,9,6};
	bubble_sort(a,10);
	return 0;
}

int bubble_sort(int *a,int num)
{
	int i,j,flag;
	flag = 1;

	for(i=0;i<(num-1)&&flag == 1;i++){
		flag = 0;
		for (j = 0; j < (num-i-1);j++)
		{
			if(a[j+1]>a[j]){
				SWAP(a[j+1],a[j]);
				flag = 1;
			}
		}
		for(j=0;j<num;j++)
			printf("%d ",a[j]);
		printf("\n");
	}
	return 1;
}
