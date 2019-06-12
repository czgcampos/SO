#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char const *argv[]){
	mkfifo("pipe",0777);
	return 0;
}