#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	int fd = open("pipe",O_WRONLY);
	void* buf=malloc(1);
	while(read(0,buf,1))
		write(fd,buf,1);
	return 0;
}