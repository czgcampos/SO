#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int ctrl_c = 0;
int time=0;

void sigalrm(int signum){
	time++;
	alarm(1);
}

void sigint(int signum){
	printf("Passaram %d segundos\n", time);
	ctrl_c++;
}

void sigquit(int signum){
	printf("O utilizador carregou %d vezes em CTRL+C\n", ctrl_c);
	_exit(1);
}

int main(int argc, char const *argv[]){
	signal(SIGALRM,sigalrm);
	signal(SIGINT,sigint);
	signal(SIGQUIT,sigquit);
	alarm(1);
	while(1)
		pause();
	return 0;
}