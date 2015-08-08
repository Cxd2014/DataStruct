/*
* 快速排序法一  将最右边的数设定为轴
* 快速排序法的基本精神是在数列中找出适当的轴心，然后将数列一分为二，
* 分别对左边与右边数列进行排序，而影响快速排序法效率的正是轴心的选择
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10
#define SWAP(x,y) {int t;t=x;x=y;y=t;}

int quicksort(int a[], int left, int right);
int partition(int number[], int left, int right);

int main(int argc, char const *argv[])
{
	int i,t;
	int a[MAX];
	srand(time(NULL));

	for(i=0;i<MAX;i++){ //产生随机数
		a[i] = rand()%100;
		printf("%d ",a[i]);
	}

	printf("\n\n");
	quicksort(a,0,MAX-1);
	for(t=0;t<MAX;t++)
		printf("%d ",a[t]);
	printf("\n");
	return 0;
}

int partition(int a[], int left, int right) 
{ 
    int i = left - 1; 
    int j;
    for(j = left; j < right; j++) { 
        if(a[j] <= a[right]) { 
            i++; 
            SWAP(a[i], a[j]); 
			
        } 
    } 
    SWAP(a[i+1], a[right]); 
    return i+1; 
} 


int quicksort(int a[], int left, int right)
{
	 if(left < right) { 
        int q = partition(a, left, right); 
        quicksort(a, left, q-1); 
        quicksort(a, q+1, right); 
    } 
}
