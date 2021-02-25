#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define eprintf(...) printf(__VA_ARGS__); fflush(stdout); //for Windows enviroment
#if 0
void Uniq(char *Input,int size,char *history){
	int i,j,k=0;
	int count;
	for(i=0;i<size;i++){
		count = 1;
		for(j=0;j<size;j++){
			if(Input[i] == history[j]){
				count++;
			}
		}
		if(count==1){
			history[k] = Input[i];
			k++;
		}
	}
}
#else
bool contains(char *history,int size,char n){
	int i;
	for(i=0;i<size;i++){
		if(history[i]==n)
			return true;
	}
	return false;

}

void Uniq(char *Input,int size,char *history){
	int i,j,k=0;
	int count=0;
	
	for(i=0;i<size;i++){
		if(!contains(history,size,Input[i])){
			history[count] = Input[i];
			count++;
		}
	}
}

#endif

int main(void){
     int size=0,i;
     char history[100]={'\0'};
     eprintf("Question is:Input a string and find the unique character in it.\n");
     eprintf("Input the matrix size :");
     scanf("%d",&size);
     char *Input=(char*)malloc(sizeof(char)*size);
	 char A = 'A';
	 char Z = 'Z';
	 eprintf("Z-A=%d\n",Z-A);
	 //because input by stdin will press enter then make '\n' in the buffer and will get by fgets.
	 //also we don't know how many \n in buffer
	 while(getchar()!='\n') 
     	continue;
     eprintf("Input the string :");
	 fgets(Input,size,stdin);

	 Uniq(Input,size,history);
     eprintf("The unique string is :%s\n",history);
 }
