#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

void myBash(char* args){
    char** cmd=NULL;
    char* token=strtok(args," ");
    int i=0, j=0, anterior, seguinte[2];
    for(;token!=NULL;token=strtok(NULL," ")){
        if(strcmp("&",token)!=0 && strcmp("|",token)!=0){
            cmd=(char**)realloc(cmd,(i+1)*sizeof(char*));
            cmd[i]=strdup(token);
            i++;
        }else if(strcmp("|",token)==0){
            pipe(seguinte);
            cmd=(char**)realloc(cmd,(i+1)*sizeof(char*));
            cmd[i]=NULL;
            if(fork()==0){
                if(j>0){
                    dup2(anterior, 0);
                    close(anterior);
                }
                close(seguinte[0]);
                dup2(seguinte[1],1);
                close(seguinte[1]);
                execvp(cmd[0],cmd);
                _exit(-1);
            }else{
                for(int k=0;k<i;k++)
                    free(cmd[k]);
                i=0;
                if(j>0)
                    close(anterior);
                anterior = seguinte[0];
                close(seguinte[1]);
                j++;
            }
        }
    }
    cmd=(char**)realloc(cmd,(i+1)*sizeof(char*));
    cmd[i+1]=NULL;
    if(fork()==0){
        if(j>0){
            dup2(anterior, 0);
            close(anterior);
        }
        execvp(cmd[0],cmd);
        _exit(-1);
    }
}

int main(){
    char str[1024];
    char* args;
    while(fgets(str,1024,stdin)){
        args=strtok(str,"\n");
        if(args!=NULL && strcmp(args,"exit")==0)
            break;
        else if(args!=NULL){
            myBash(args);
        }
    }
    return 0;
}