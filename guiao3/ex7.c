#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

void myBash(char* args){
    const char s[2]=" ";
    char** cmd=NULL;
    int i=0;
    for(char* token=strtok(args, s);token;token=strtok(NULL, s)){
        if(strcmp("&",token)!=0){
            cmd=(char**)realloc(cmd,(i+1)*sizeof(char*));
            cmd[i]=strdup(token);
            i++;
        }
    }
	cmd=(char**)realloc(cmd,(i+1)*sizeof(char*));
	cmd[i+1]=NULL;
    if(fork()==0){
    	execvp(cmd[0],cmd);
        _exit(-1);
    }
}

int main(){
	char str[1024];
    char* args;
	while(fgets(str,1024,stdin)){
        args=strtok(str,"\n");
        if(strcmp(args,"exit")==0)
            break;
        else
            myBash(args);
    }
}