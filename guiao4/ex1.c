#include <unistd.h>
#include <fcntl.h>

int main(int argc, char const *argv[]){
	int fd1 = open("/etc/passwd", O_RDONLY, 00400);
	int fd2 = open("./saida.txt", O_CREAT | O_WRONLY | O_TRUNC, 0666);
	int fd3 = open("./erros.txt", O_CREAT | O_WRONLY | O_TRUNC, 0666);
	dup2(fd1,0);
	dup2(fd2,1);
	dup2(fd3,2);
	char buf[500];
	read(0,&buf,500);
	write(1,&buf,500);
	write(2,&buf,500);
	close(fd1);
	close(fd2);
	close(fd3);
	return 0;
}