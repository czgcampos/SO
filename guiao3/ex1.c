#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[]){
	execlp("ls","ls","-l",NULL);
	printf("YOLO\n");
	return 0;
}