#include<stdlib.h>
#include<stdio.h>
#define eprintf(...) printf(__VA_ARGS__); fflush(stdout); //for Windows enviroment
typedef enum {
	CBRS_CHANNEL_UNKNOW = 0,
	/* Decrement by priority, the highest priority with the lowest number. See cbrs_get_available_grant() */	
	CBRS_CHANNEL_NORMAL,
	CBRS_CHANNEL_SUGGESTION,
	CBRS_CHANNEL_RESEND,
	CBRS_CHANNEL_SUSPENSION,
	CBRS_CHANNEL_INVALID,
	CBRS_CHANNEL_MAX
} CBRS_CHANNEL_STATUS;


typedef struct
{
	int id;
	CBRS_CHANNEL_STATUS status;
} CBRS_AVAILABLE_GRANT;

CBRS_AVAILABLE_GRANT number[] = { {0,2},{1,3},{2,1},{3,4},{4,1}  };

int main(){
	int i = 0, maxEirp = 0, size = 0;
	CBRS_AVAILABLE_GRANT *grant = NULL, *retGrant[CBRS_CHANNEL_MAX] = {NULL};
	eprintf("max=%d\n",CBRS_CHANNEL_MAX);
	char lastGrantId[256]={0};

	for(i = 0; i < 6; i++){
		eprintf("i=%d\n",i);
		grant = number+i;
		if(grant == NULL) break;
		
		if(grant->status == CBRS_CHANNEL_NORMAL){
				retGrant[CBRS_CHANNEL_NORMAL] = grant;
		}
		else if (grant->status == CBRS_CHANNEL_SUGGESTION){
			retGrant[CBRS_CHANNEL_SUGGESTION] = grant;
		}		
		else if (grant->status == CBRS_CHANNEL_RESEND){
			retGrant[CBRS_CHANNEL_RESEND] = grant;
		}
		else if (grant->status == CBRS_CHANNEL_SUSPENSION){
			retGrant[CBRS_CHANNEL_SUSPENSION] = grant;
		}
	}	
	for(i = CBRS_CHANNEL_NORMAL; i < CBRS_CHANNEL_MAX; i++){
		if(retGrant[i] != NULL){
			eprintf("id=%d,status=%d\n",retGrant[i]->id,retGrant[i]->status);
			grant = retGrant[i];
		}
	}
	eprintf("great grant: id=%d,status=%d\n",grant->id,grant->status);

	return 0;
}
