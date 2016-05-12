/*
* 有1000个正整数，每个数的取值范围均在1到100之间，变成找出从小到大排在第 340（从0开始算起）的那个数，
* 将此数的值返回，要求不使用排序实现
*/

#include<stdio.h>

#define MAX 1000
#define MCC (MAX/10)

int main()
{
	int i,temp;
	int a[MAX],b[MCC];
	
	srand(time(NULL));
	for(i=0;i<MAX;i++){ //产生随机数
		a[i] = rand()%MCC;
		//printf("%d ",a[i]);
	}
	//printf("\n");
	
	for(i=0;i<MCC;i++) //初始化
		b[i]=0;
		
	for(i=0;i<MAX;i++){
		temp = a[i];
		b[temp]++;
	}
	
/*	
	for(i=0;i<MCC;i++){
		printf("%d ",b[i]);
	}
*/
	temp = 0;
	for(i=0;i<MCC;i++){
		temp = temp + b[i];
		if(temp>=340)
			break;
	}
	
	printf("The 340th num = %d\n",i);
		
    return 0;
}
