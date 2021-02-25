#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define eprintf(...) printf(__VA_ARGS__); fflush(stdout); //for Windows enviroment
int balancedString(char * s){
    //看各元素有沒有出現過，少了哪些重複了幾個
    int i,j,n,Output=0;
    char string[4] = {'Q','W','E','R'};
    int count[4] = {0};
    
    n = strlen(s)/4;
    for(j=0;j<4;j++){
        for(i=0;i<strlen(s);i++){
            if(s[i]==string[j]){
                count[j]++;
            }
        }
        if(count[j] > n){
            //exchange, return answer; 
            Output += count[j]-n;
        }
    }
    return Output;
}

int main(){

	int i,size;
	eprintf("Input size:\n");
	scanf("%d",&size);
	char *Input = (char*)malloc(sizeof(char)*size);
	eprintf("Input string\n");
	for(i=0;i<size;i++){
		scanf("%c",Input+i);
	}
	eprintf("%d\n",balancedString(Input));
	return 0;
}
