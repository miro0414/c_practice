#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<stdbool.h>
#define eprintf(...) printf(__VA_ARGS__); fflush(stdout); //for Windows enviroment
int countElement(int *Input,int size){
#if 0
	int i,j,sum=0;
	int plus1;
	for(i=0;i<size;i++){
		plus1 = Input[i]+1;
		for(j=0;j<size;j++){
			if(plus1 == Input[j]){
				sum++;
			}
		}
	}
#else
	int i,plus1,sum=0;
	bool isfound[1002]={false}; // 正比於數值大小

	for(i=0;i<size;i++){
		isfound[Input[i]]=true; //有出現過就在該陣列位置設為true
	}

	for(i=0;i<size;i++){
		plus1 = Input[i]+1;
		if(isfound[plus1])
			sum++;
	}
#endif
	
	return sum;

}
int main(){

	int i,size;
	//找出陣列中數字+1後還是陣列中的元素，共有幾個。size最多0~1000，數字大小0~1000
	eprintf("Input size:\n");
	scanf("%d",&size);
	int *Input = (int*)malloc(sizeof(int)*size);
	eprintf("Input price string\n");
	while(getchar()!='\n')
		continue;
	for(i=0;i<size;i++){
		scanf("%d",Input+i);
	}
	while(getchar()!='\n')
		continue;
	eprintf("%d\n",countElement(Input,size));
	return 0;
}
