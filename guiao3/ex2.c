#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[]){
	if(fork()==0)
		execlp("ls","-l",NULL);
	else
		printf("YOLO\n");
	return 0;
}