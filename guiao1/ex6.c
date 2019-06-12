#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void ex6(int fd){
	void* buf=malloc(1);
	int r=0, i=1;
	char* count=malloc(32);
	while((r=read(fd,buf,1024))){
		write(1,"    ",4);
		sprintf(count, "%d", i);
		write(1,count,strlen(count));
		write(1,"  ",2);
		write(1,buf,r);
		i++;
	}
	write(1,"\n",1);
	free(buf);
	free(count);
}

int main(int argc, char* argv[]){
	if(argc!=1){
		int fd=open(argv[1], O_CREAT | O_RDWR, 0666);
		ex6(fd);
	}else{
		ex6(0);
	}
	return 0;
}