#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

ssize_t readln (int fd, void* buf, int cap){
	int tam=0;
	char* p=buf;
	while(1){
		if(tam>=cap) break;
		int n = read(fd, p, 1);
		if(n==0) break;
		if(n==-1) return -1;
		tam++;
		if(*p=='\n') break;
		p+=1;
	}
	return tam;
}

void ex5(){
	void* buf=malloc(1);
	int r=0;
	while((r=readln(0,buf,1)))
		write(1,buf,r);
}

int main(int argc, char* argv[]){
	ex5();
	return 0;
}