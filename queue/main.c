#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	struct Queue *Q;
	int i = 0;

	Q = InitQueue(); //初始化一个队列
	if(Q == NULL){
		printf("InitQueue error\n");
		exit(0);
	}

	for(i = 0;i<10;i++){
		if(InQueue(Q,i) == ERROR){
			printf("InQueue error\n");
			exit(0);
		}
	}
	ShowQueue(Q);

	for(i = 0;i<5;i++){
		if(OutQueue(Q) == ERROR){
			printf("OutQueue error\n");
			exit(0);
		}
	}
	ShowQueue(Q);
	
	return 0;
}