
#include<stdio.h>

#define MAX 10

int main()
{
	int i,j;
	int temp;
    int a[MAX];
    
    srand(time(NULL));
    for(i=0;i<MAX;i++){ //产生随机数
        a[i] = rand()%100;
        printf("%d ",a[i]);
    }
	printf("\n");
	 
	for(i=0;i<MAX;i++)
		for(j=i+1;j<MAX;j++)
			if(a[i]>a[j]){
			
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;	
			}
			
	for(i=0;i<MAX;i++)
		printf("%d ",a[i]);	
	printf("\n");
    return 0;
}
