#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define eprintf(...) printf(__VA_ARGS__); fflush(stdout); //for Windows enviroment
int maxProfit(int *prices,int size){
#if 1
	//DP(動態規劃) 
	//想法:最後一天要不要賣
	if(size<=1) return 0; //邊際條件，終止的條件
	int profits[size]; //存放答案的地方，避免一直重複計算 profits[i] = maxProfit(prices,i)
	profits[1] = 0;//只剩一天的話，沒得做所以是0
	int k;
	for(k=2;k<=size;k++){ //由第一天往後推
		int max = 0;
		int profit,i;
		//不賣
		//[7,1,5,3,6,4] => [7,1,5,3,6] => maxProfit([7,1,5,3,6,4),5)
		profit = profits[k-1];
		if(profit>max){
			max = profit;
		}
		//賣
		//max(
		//[7,1,5,3,6]+(6,4)=>maxProfit([7,1,5,3,6,4],5)+(4-6)
		//[7,1,5,3]+(3,4)=>maxProfit([7,1,5,3,6,4],4)+(4-3)
		//[7,1,5]+(5,4)=>maxProfit([7,1,5,3,6,4],3)+(4-5)
		//[7,1]+(1,4)=>maxProfit([7,1,5,3,6,4],2)+(4-1)
		//[7]+(7,4)=>maxProfit([7,1,5,3,6,4],1)+(4-7)
			//)
		for(i=1;i<k;i++){
			profit = profits[i]+prices[k-1]-prices[i-1];
			if(profit>max){
				max = profit;
			}
		}
		profits[k] = max;
	}
	return profits[size];
#else
	//Greedy(貪婪)
	
	//只比較相鄰兩天
	int i,total = 0;
	for(i=0;i+1<size;i++){
		if(prices[i]<prices[i+1]){
			total += prices[i+1]-prices[i];
		}
	}
	return total;
#endif
}
int main(){

	int i,size;
	//I: 找出哪天買哪天賣獲利最高，只能買賣一次
	//II:可以買賣很多天，但每天只能選擇買或賣，當天賣完還可以買，且還沒賣就不能買(本題)
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
	eprintf("%d\n",maxProfit(Input,size));
	return 0;
}
