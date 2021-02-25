#include<stdio.h>
#include<stdlib.h>
#define eprintf(...) printf(__VA_ARGS__); fflush(stdout); //for Windows enviroment
//可以先選一個起點跟終點，再加起來看看。
int maxsubarray(int *num,int numsize,int money){
	 int i,j,k;
	 int max=0;
	 int count=0;
	 for(i=0;i<numsize;i++){//起點
	 	int sum =0;
	 	for(j=i;j<numsize;j++){//終點
			sum+=num[j];//起終點元素和
			count = j-i+1;//起終點元素數量
			if(count>max && sum <= money){
				max = count;
			}
		}
	 }
	return max;
}


int main(){
	int numsize,money;
	eprintf("Input the subarray size of string and money:");
	scanf("%d %d",&numsize,&money);
	int *num = (int*)malloc(sizeof(int)*numsize);
	int i;
	eprintf("Input each element of array.\n:");
	for(i=0;i<numsize;i++){
		scanf("%d",num+i);
	}
	
	eprintf("answer is %d\n",maxsubarray(num,numsize,money));



	return 0;
}
