#include<stdio.h>
#define eprintf(...) printf(__VA_ARGS__); fflush(stdout); //for Windows enviroment
int singlenumber(int *num,int numsize){
	//int x[5] = {1,2,2,3,4};
	int i,j;
	for(i=0;i<numsize;i++){
		int count = 0;
		for(j=0;j<numsize;j++){
			if(num[j]==num[i])
				count++;
		}
		if(count == 1)
			return num[i];
	}
	return -1;
}

int main(){
	
	int x[5]={2,2,2,3,3};
	eprintf("find the single number in this strings.\n");
	eprintf("single number is %d\n",singlenumber(x,5));
	
	return 0;

}
