
#include <stdio.h>
#include <stdlib.h>
#define eprintf(...) printf(__VA_ARGS__); fflush(stdout); //for Windows enviroment
int main()
{
    int num, *arr, i;
    eprintf("Input the size:\n");
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
	eprintf("Input the array space with each number:\n");
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }


    /* Write the logic to reverse the array. */
#if 1
	for(i=0;i<num/2;i++){
        if(i != (num-1-i)){
            int temp;
            temp = arr[i];
            arr[i] = arr[num-1-i];
            arr[num-1-i] = temp;
        }
    }   
	for(i = 0; i < num; i++)
        eprintf("%d ", *(arr + i));
	puts("");

#else
	int *ans;
	int j=0;
	ans = (int*)malloc(num*sizeof(int));
	for(i=num-1;i>=0;i--){
		ans[j] = arr[i];	
		j++;
	}
	for(i=0;i<num;i++)
		eprintf("%d ",ans[i]);	
	puts("");
#endif


    return 0;
}
