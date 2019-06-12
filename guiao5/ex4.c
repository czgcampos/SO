#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char const *argv[]){
	int fildes[2];
	pipe(fildes);
	if(fork()==0){
		close(fildes[1]);
		dup2(fildes[0],0);
		close(fildes[0]);
		execlp("wc","wc","-l",NULL);
	}else{
		close(fildes[0]);
		dup2(fildes[1],1);
		close(fildes[1]);
		execlp("ls","ls","/etc",NULL);
	}
	return 0;
}