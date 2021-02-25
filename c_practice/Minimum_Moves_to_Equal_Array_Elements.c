#include<stdio.h>
#include <stdlib.h>
#define eprintf(...) printf(__VA_ARGS__); fflush(stdout); //for Windows enviroment
int Move(int *Input,int size){
	//assume move n times, finantial number is x 
	//sum + (size-1)*n = x * size
	//x = min + n
	//=> sum + n*size -n = min*size + n*size
	//=> n = sum - min*size
	int i;
	int sum = 0;
	int min = Input[0];
	for(i=0;i<size;i++){
		sum +=	Input[i];
		if(Input[i]<min){
			min = Input[i];
		}
	}
	
	return sum - min*size;
}

int main(void){
	int size=0,i;
	int answer;
	eprintf("Question is:Do the lest move to let the element of matrix be same.\nevery move make every n-1 element +1\n");
	eprintf("Input the matrix size :");
	scanf("%d",&size);
	int *Input=(int*)malloc(sizeof(int)*size);
	
	eprintf("Input the matrix element shift by space :");
	for(i=0;i<size;i++){
		scanf("%d",&Input[i]);
	}
	
	answer = Move(Input,size);
	eprintf("The min move is :%d\n",answer);
}
