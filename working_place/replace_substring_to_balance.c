#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define eprintf(...) printf(__VA_ARGS__); fflush(stdout); //for Windows enviroment
#define CHR_NUM 4
#define MIN(a, b) (a) < (b) ? (a) : (b)

int CharMap(char x)
{
    switch (x) {
        case 'Q':
            return 0;
        case 'W':
            return 1;
        case 'E':
            return 2;
        case 'R':
            return 3;
        default:
            return -1;
    }    
}

int balancedString(char *s)
{
    if (!s) {
        return 0;
    }

    int len, avg, left, right, res, i;
    int nums[CHR_NUM] = {0};//計算QWER各別出現的數量
    len = strlen(s);
    avg = len / 4;
    res = len;
    for (i = 0; i < len; i++) {
        nums[CharMap(s[i])]++;
    }

    left = 0;
    right = 0;
	
    while (right < len) {
        nums[CharMap(s[right])]--;//s[right]是什麼，把他的數量扣1，直到滿足下面條件才進去下一層while
		//條件是先找到每個元素數量都小於等於avg = len/4，再計算剩餘數量就是要替換的字串數
        while (left < len && nums[0] <= avg && nums[1] <= avg && nums[2] <= avg && nums[3] <= avg) {
            res = MIN(res, right - left + 1);//更新最小替代字串
            nums[CharMap(s[left])]++;//s[left]是什麼，把他的數量+1，直到不滿足上面條件，離開while
            left++;
        }
        right++;//right位移1位
    }
    return res;
	}
int main(){

	int i,size;
	eprintf("Input size:\n");
	scanf("%d",&size);
	char *Input = (char*)malloc(sizeof(char)*size);
	eprintf("Input string\n");
	while(getchar()!='\n')
		continue;
	for(i=0;i<size;i++){
		scanf("%c",Input+i);
	}
	while(getchar()!='\n')
		continue;
	eprintf("%d\n",balancedString(Input));
	return 0;
}
