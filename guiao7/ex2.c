#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

pid_t* pids = NULL;
int count = 0;
int pointer = 0;
int online = 0;

void sigquit(int signum){
	_exit(1);
}

int main(int argc, char const *argv[]){
	signal(SIGQUIT,sigquit);
	count = argc-2;
	online = argc-1;
	pids = malloc(sizeof(int)*count);
	for(int i=1;i<argc;i++){
		pids[i-1] = fork();
		if(pids[i-1] == 0){
			kill(getpid(),SIGSTOP);
			execlp(argv[i],argv[i],NULL);
			_exit(-1);
		}
	}
	while(online){
		sleep(1);
		if(pointer<count){
			kill(pids[pointer],SIGSTOP);
			kill(pids[pointer+1],SIGCONT);
			pointer++;
		}
		else{
			kill(pids[pointer],SIGSTOP);
			pointer=0;
			kill(pids[pointer],SIGCONT);
		}
	}
	return 0;
}