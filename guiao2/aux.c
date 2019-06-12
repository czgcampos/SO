#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char const *argv[]){
	printf("L0\n");
	if(fork()==0){
		printf("L1\n");
		if(fork()==0){
			printf("L2\n");
			fork();
			printf("Forked\n");
		}
	}
	printf("Bye\n");
}