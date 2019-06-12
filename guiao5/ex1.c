#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char const *argv[]){
	int fildes[2];
	pipe(fildes);
	char buf[4];
	if(fork()!=0){
		close(fildes[1]);
		read(fildes[0],buf,4);
		write(1,buf,4);
		close(fildes[0]);
	}else{
		sleep(5);
		close(fildes[0]);
		write(fildes[1],"ola\n",4);
		close(fildes[1]);
	}
	return 0;
}