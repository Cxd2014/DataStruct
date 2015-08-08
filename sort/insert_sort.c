/*
* 插入排序算法 
* 将一个记录插入到已排好的有序表中，得到一个新的
* 记录数增一的有序表
*/

#include <stdio.h>
#include <stdlib.h>

int insert_sort(int *a,int num);

int main(int argc, char const *argv[])
{
	int a[] = {15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
	insert_sort(a,15);
	return 0;
}

int insert_sort(int *a,int num)
{
	int i,j,tmp;
	for(i=1;i<num;i++){ 
		tmp = a[i]; // 取出一个记录

		j = i - 1; //插入到有序表中去
		while(tmp < a[j]){
			a[j+1] = a[j];
			j--;
			if(j == -1)
				break;
		}
		a[j+1] = tmp;

		for(j=0;j<num;j++)
			printf("%d ",a[j]);
		printf("\n");
	}
	return 1;
}