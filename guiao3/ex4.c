#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]){
	char** args = malloc(sizeof(char*)*argc);
	for(int i=1;i<argc;i++)
		args[i-1]=strdup(argv[i]);
	args[argc]=NULL;
	execvp(args[0],args);
	_exit(-1);
}