#include <unistd.h>
#include <fcntl.h>

void ex1(char* name){
	int fd = open(name, O_CREAT | O_RDWR, 0666);
	int size = 1000 * 1000 * 10;
	int i=0;
	if(fd>0){
		for(;i<size;i++)
			write(fd, "a", 1);
	}
}

int main(int argc, char* argv[]){
	ex1(argv[1]);
	return 0;
}