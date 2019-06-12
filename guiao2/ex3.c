#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char const *argv[]){
	int status;
	int i=0;
	for(i=0;i<10;i++){
		if(fork() == 0){
			printf("O meu id é %d, e o do meu pai é %d\n",getpid(),getppid());
			_exit(i);
		}else{
			wait(&status);
			printf("O filho %d terminou\n", WEXITSTATUS(status));
		}
	}
	return 0;
}