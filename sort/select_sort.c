/*
* 选择排序算法 
* 将要排序的对象分作两部份，一个是已排序的，一个是未排序的，
* 从后端未排序部份选择一个最小值，并放入前端已排序部份的最后一个
*/
#include <stdio.h>
#include <stdlib.h>

#define SWAP(x,y) {int t;t=x;x=y;y=t;}

int select_sort(int *a,int num);

int main(int argc, char const *argv[])
{
	int a[] = {1,3,2,7,0,8,5,4,9,6};
	select_sort(a,10);
	return 0;
}

int select_sort(int *a,int num)
{
	int i,m,j;

	for(i=0;i<(num-1);i++){ //总共要选择 num-1 个最小值
		m = i;

		for(j=i+1;j<num;j++) //找到最小值
			if(a[j]<a[m])
				m = j;

		if(i != m)
			SWAP(a[i],a[m]);

		for(j=0;j<num;j++)
			printf("%d ",a[j]);
		printf("\n");
	}
	return 1;
}