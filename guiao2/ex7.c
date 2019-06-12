#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[]){
	int matrix[10][1000];
	int i,j;
	for(i=0;i<10;i++)
		for(j=0;j<1000;j++)
			matrix[i][j]=rand()%100;
	int res=atoi(argv[1]);
	for(i=0;i<10;i++){
		if(fork() == 0){
			for(j=0;j<1000;j++)
				if(matrix[i][j]==res)
					printf("Encontrei na linha %d e coluna %d\n", i,j);
			_exit(1);
		}else
			wait(NULL);
	}
	return 0;
}