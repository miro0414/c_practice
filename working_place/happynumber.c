	//題目:輸入一串數字，判斷是否是happynumber，即各個位數的平方和一直做下去最終是否為1
	//n = 123;
	//n1 = n % 10; 個位數 3
	//n2 = n / 10  % 10; 十位數 2
	//n3 = n / 100 % 10; 百位數 1
	//
	//n1 = n  % 10;
	//n2 = n1 % 10;
	//n3 = n2 % 10;
	//重複的所以要弄成迴圈，然後把不同的部分弄成一個變數。
	//先知道有幾位數(INT_MAX是10位數)
#include<stdio.h>
#include<stdbool.h>
#define eprintf(...) printf(__VA_ARGS__); fflush(stdout); //for Windows enviroment
int next_n(int n){
	int r = 0;
	while(n != 0){
		int d;
		d = n % 10;
		n /= 10; // n =1
		r += d * d;
	}
	return r;
}//算該數字個別位數的平方,也就是下個要判斷的數

bool existornot(int input,int *history,int size){
	int i;
	for(i=0;i<size;i++){
		if(history[i] == input)
			return true;
	}
	return false;
}
#if 1
bool ishappynumber(int input){
	// 9999999999 => 9*9*10 => 810  next_n最大只會是這個數。
	int history[1000];
	int size = 0;
	input = next_n(input); //可以先做一次，避免history要存很大
	while(!existornot(input,history,size)){
		input = next_n(input);
		size ++;
	}	

	return input ==1 ;
/*	if (input ==1)
		return true;
	else
		return false;
		*/
}
#else
//龜兔演算法 可以省去history來驗證有沒有出現過的記憶體空間
bool ishappynumber(int input){
	int slow = input;
	int fast = input;

	do{
		slow = next_n(slow);//一次走一格
		fast = next_n(next_n(fast));//一次走兩格
	}while(slow != fast);

	return fast == 1;
}
#endif
int main(){
	int answer,input;
	eprintf("input the number:\n");
	scanf("%d",&input);
	answer = ishappynumber(input);
	eprintf("%d\n",answer);

	return 0;
}
