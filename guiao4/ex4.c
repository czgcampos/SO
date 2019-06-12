#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]){
	if(strcmp(argv[1],"-i")==0 && strcmp(argv[3],"-o")==0){
		int in = open(argv[2], O_CREAT | O_RDONLY , 0666);
		int out = open(argv[4], O_CREAT | O_WRONLY, 0666);
		dup2(in,0);
		dup2(out,1);
		char** args = malloc(sizeof(char*)*argc);
		for(int i=5;i<argc;i++)
			args[i-5]=strdup(argv[i]);
		args[argc]=NULL;
		if(fork()==0){
			execvp(args[0],args);
			_exit(-1);
		}
		wait(NULL);
		close(out);
		close(in);
	}else if(strcmp(argv[1],"-o")==0){
		int out = open(argv[2], O_CREAT | O_WRONLY, 0666);
		dup2(out,1);
		char** args = malloc(sizeof(char*)*argc);
		for(int i=3;i<argc;i++)
			args[i-3]=strdup(argv[i]);
		args[argc]=NULL;
		if(fork()==0){
			execvp(args[0],args);
			_exit(-1);
		}
		wait(NULL);
		close(out);
	}else if(strcmp(argv[1],"-i")==0){
		int in = open(argv[2], O_CREAT | O_RDONLY , 0666);
		dup2(in,0);
		char** args = malloc(sizeof(char*)*argc);
		for(int i=3;i<argc;i++)
			args[i-3]=strdup(argv[i]);
		args[argc]=NULL;
		if(fork()==0){
			execvp(args[0],args);
			_exit(-1);
		}
		wait(NULL);
		close(in);
	}else{
		char** args = malloc(sizeof(char*)*argc);
		for(int i=1;i<argc;i++)
			args[i-1]=strdup(argv[i]);
		args[argc]=NULL;
		if(fork()==0){
			execvp(args[0],args);
			_exit(-1);
		}
		wait(NULL);
	}
	return 0;
}