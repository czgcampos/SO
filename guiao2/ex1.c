#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char const *argv[]){
	printf("O meu id é %d, e o do meu pai é %d\n",getpid(),getppid());
	return 0;
}