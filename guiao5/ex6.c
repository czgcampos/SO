#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char const *argv[]){
	int fildes[2];
	pipe(fildes);
	if(fork()==0){
		close(fildes[1]);
		return fildes[0];
	}
	return 0;
}