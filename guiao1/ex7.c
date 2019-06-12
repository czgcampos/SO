#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include "../guiao0/person.h"

int main(int argc, char* argv[]){
	int fd=open("dados.txt", O_CREAT | O_RDWR, 0666);
	if(strcmp("-i",argv[1])==0){
		Person new = new_person(argv[2],atoi(argv[3]));
		write(fd,&new,sizeof(Person));
	}else if(strcmp("-u",argv[1])==0){

	}
	return 0;
}