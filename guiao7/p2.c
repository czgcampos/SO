#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
	int fd = open("10mb2.txt", O_CREAT | O_RDWR, 0666);
	int size = 1000 * 1000 * 10;
	int i=0;
	if(fd>0){
		for(;i<size;i++)
			write(fd, "a", 1);
	}
	return 0;
}