#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void ex3(int n){
	void* buf=malloc(n);
	int r=0;
	while((r=read(0,buf,n)))
		write(1,buf,r);
	free(buf);
}

int main(int argc, char* argv[]){
	ex3(atoi(argv[1]));
	return 0;
}