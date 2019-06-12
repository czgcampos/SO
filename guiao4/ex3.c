#include <unistd.h>
#include <fcntl.h>

int main(int argc, char const *argv[]){
	int fd1 = open("/etc/passwd", O_RDONLY, 00400);
	int fd2 = open("./saida.txt", O_CREAT | O_WRONLY | O_TRUNC, 0666);
	int fd3 = open("./erros.txt", O_CREAT | O_WRONLY | O_TRUNC, 0666);
	dup2(fd1,0);
	dup2(fd2,1);
	dup2(fd3,2);
	if(fork()==0){
		execlp("wc","wc",NULL);
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return 0;
}