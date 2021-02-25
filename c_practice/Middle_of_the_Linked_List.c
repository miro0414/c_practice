#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<stdbool.h>
struct ListNode{
	int value;
	struct ListNode *next;
};
typedef struct *ListNode ListNode_t;
ListNode_t *middleNode(ListNode_t * head){
#if 0
//算長度的一半回傳
	int len=0;
	int i;
	ListNode_t *current;
	for(current = head;current!=NULL;current=current->next){
		len++;
	}
	
	ListNode_t *result = head;
	for(i=0;i<len/2;i++){
		result = result->next;
	}

#else
//龜兔法
	ListNode_t *fast=head;
	ListNode_t *slow=head;

	while(fast->next !=NULL && fast->next->next != NULL){
		fast = fast->next->next;
		slow = slow->next;
	}
	result = slow;

#endif
	return result;
}
int main(){

	return 0;
}
