#include <unistd.h>

int main(int argc, char const *argv[]){
	int fildes[2];
	pipe(fildes);
	int fildes2[2];
	pipe(fildes2);
	int fildes3[2];
	pipe(fildes3);
	if(fork()==0){
		close(fildes[0]);
		close(fildes2[0]);
		close(fildes2[1]);
		close(fildes3[0]);
		close(fildes3[1]);
		dup2(fildes[1],1);
		close(fildes[1]);
		execlp("grep","grep","-v","ˆ#","/etc/passwd",NULL);
	}else{
		if(fork()==0){
			close(fildes[1]);
			close(fildes3[0]);
			close(fildes3[1]);
			dup2(fildes[0],0);
			close(fildes[0]);
			close(fildes2[0]);
			dup2(fildes2[1],1);
			close(fildes2[1]);
			execlp("cut","cut","-f7","-d:",NULL);
		}else{
			if(fork()==0){
				close(fildes[0]);
				close(fildes[1]);
				close(fildes2[1]);
				dup2(fildes2[0],0);
				close(fildes2[0]);
				close(fildes3[0]);
				dup2(fildes3[1],1);
				close(fildes3[1]);
				execlp("uniq","uniq",NULL);
			}else{
				close(fildes3[1]);
				close(fildes2[0]);
				close(fildes2[1]);
				close(fildes[0]);
				close(fildes[1]);
				dup2(fildes3[0],0);
				close(fildes3[0]);
				execlp("wc","wc","-l",NULL);
			}
		}
	}
	return 0;
}