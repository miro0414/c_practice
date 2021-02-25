#include<stdio.h>
#include <stdlib.h>
#define eprintf(...) printf(__VA_ARGS__); fflush(stdout); //for Windows enviroment
int Move(int *Input,int size){
	//every move can use plus and minus.
	//finantial number will be the Median number m if length is odd,and will be the avg of middle number if length is even.
	//assume move i times.
	//m = (max + min) /2
	//sum of difference between m and every number is the answer.
	int i,j,m,temp;
	int answer = 0;
	
    for(i=0;i<size-1;i++)
    {
        for(j=i+1;j<size;j++)
        {
            if(Input[i]>Input[j])
            {
                temp=Input[i];
                Input[i]=Input[j];
                Input[j]=temp;
            }
        }
	}
	if(size%2>0){
		m = Input[(size/2)];
	}else{
		m = (Input[size/2] + Input[(size/2)-1])/2;
	}
	eprintf(" Median number m is %d\n",m);
	for(i=0;i<size;i++){
		answer += abs(Input[i] - m);
	}

	return answer;
}

int main(void){
	int size=0,i;
	int answer;
	eprintf("Question is : Do the lest move to let the element of matrix be same.\nevery move choose one element + or - 1.\n");
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
