#include<stdio.h>
#include<stdlib.h>
#define eprintf(...) printf(__VA_ARGS__); fflush(stdout); //for Windows enviroment
//可以先選一個起點跟終點，再加起來看看。 但要用到三個for
int maxsubarray(int *num,int numsize){
	 int i,j,k;
	 int max = num[0]; // 也可以設為INT_MIN
	 for(i=0;i<numsize;i++){
	 	int sum =0;
	 	for(j=i;j<numsize;j++){
			/*
			int sum=0;
			
			for(k=i;k<=j;k++){
				sum+=num[k];
			}
			// i:0 ,j:0 => sum = num[0];
			// i:0 ,j:1 => sum = sum+num[1];
			// ...
			// i:0 ,j:8 => sum = sum+num[8];
			*/
			sum+=num[j];
			if(sum > max){
				max = sum;
			}
		}
	 }
	return max;
}


int main(){
	int numsize;
	eprintf("Input the subarray size of string.:");
	scanf("%d",&numsize);
	int *num = (int*)malloc(sizeof(int)*numsize);
	int i;
	eprintf("Input each element of array.\n:");
	for(i=0;i<numsize;i++){
		scanf("%d",num+i);
	}
	
	eprintf("answer is %d\n",maxsubarray(num,numsize));



	return 0;
}
