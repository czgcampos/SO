#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void ex2(){
	void* buf=malloc(1);
	while(read(0,buf,1))
		write(1,buf,1);
}

int main(int argc, char* argv[]){
	ex2();
	return 0;
}