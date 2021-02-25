#include <stdio.h>
#include <stdlib.h>
#define TR069_LOG_PATH "/mnt/sdb1/home/sam_tsai/C_code_test"
#define LOG_PATH "/mnt/sdb1/home/sam_tsai"
#define TR069_LOG "TR.log"
#define eprintf(...) printf(__VA_ARGS__); fflush(stdout); //for Windows enviroment
int CM_CopyFile(char* filein, char* fileout)
{
	FILE *In_file = NULL, *Out_file = NULL;
	char *buffer = NULL;
	int s = 4096; //4kByte
	int n;
	int ret = 0;
	buffer = (char*)malloc(s);
	if (buffer == NULL) {
		perror("Memory error");
		goto out;
	}
	
	In_file = fopen(filein, "rb");
	if (In_file == NULL) {
		perror("File open for reading");
		goto out;
	}
	
	Out_file = fopen(fileout, "wb");
	if (Out_file == NULL) {
		perror("File open for writing");
		goto out;
	}

	while(!feof(In_file)){
		n = fread(buffer,1,s,In_file);
		if(n==0) break;
		fwrite(buffer,1,n,Out_file);
	}
	ret = 1;
out:
	if(buffer) free(buffer);
	if (Out_file) fclose(Out_file);
	if (In_file) fclose(In_file);
	return ret;
}

int main(){
	
	char file_in[256], file_out[256];
	snprintf(file_in, sizeof(file_in), "%s/%s.%d", TR069_LOG_PATH, TR069_LOG, 0);
	snprintf(file_out, sizeof(file_out), "%s/%s.%d", LOG_PATH, TR069_LOG, 0);
	int ret;
	ret = CM_CopyFile(file_in, file_out);
	eprintf("ret = %d\n",ret);
	return 0;
}
