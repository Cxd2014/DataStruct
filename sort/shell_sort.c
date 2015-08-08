/*
* 希尔排序算法
* 
* 插入排序的改良版
* 假设要排序的元素有n个，则每次进行插入排序时
* 并不是所有的元素同时进行时，而是取一段间隔。
* Shell首先将间隔设定为n/2，然后跳跃进行插入排序，再来将间隔n/4，跳跃进行排序动作，再来
* 间隔设定为n/8、n/16，直到间隔为1之后的最后一次排序终止，由于上一次的排序动作都会将
* 固定间隔内的元素排序好，所以当间隔越来越小时，某些元素位于正确位置的机率越高，因此
* 最后几次的排序动作将可以大幅减低。
*/
#include <stdio.h>

#define SWAP(x,y) {int t;t=x;x=y;y=t;}

int shell_sort(int *a,int num);

int main(int argc, char const *argv[])
{
	int a[] = {15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
	shell_sort(a,sizeof(a)/sizeof(int));
	return 0;
}

int shell_sort(int *a,int num)
{
	int i,j,gap,k,t;
	gap = num/2;

	while(gap > 0){
		for(k=0;k<gap;k++)
			for(i=k+gap;i<num;i+=gap)
				for(j=i-gap;j>=k;j-=gap)
					if(a[j]>a[j+gap])
						SWAP(a[j],a[j+gap])
					else
						break;
		printf("gap = %d\n",gap);
		for(i=0;i<num;i++)
			printf("%d ",a[i]);
		printf("\n");	
		gap = gap/2;
	}
}