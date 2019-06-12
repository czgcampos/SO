#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]){
	int status=0;
	char** args = malloc(sizeof(char*)*argc);
	for(int i=1;i<argc;i++)
		args[i-1]=strdup(argv[i]);
	args[argc]=NULL;
	if((status=fork())==0){
		execvp(args[0],args);
		_exit(2);
	}else if(status<0){
		_exit(-1);
	}
	wait(NULL);
	return status;
}