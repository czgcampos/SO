#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char const *argv[]){
	int fildes[2];
	int n=0;
	pipe(fildes);
	char buf[1024];
	if(fork()==0){
		close(fildes[1]);
		dup2(fildes[0],0);
		close(fildes[0]);
		execlp("wc","wc",NULL);
	}else{
		close(fildes[0]);
		while((n=read(0,buf,1024)))
			write(fildes[1],buf,n);
		close(fildes[1]);
	}
	return 0;
}