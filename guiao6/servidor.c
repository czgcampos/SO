#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	mkfifo("pipe",0777);
	int rd = open("pipe",O_RDONLY);
	int wr = open("log",O_CREAT | O_WRONLY, 0666);
	void* buf=malloc(1);
	while(read(rd,buf,1))
		write(wr,buf,1);
	return 0;
}