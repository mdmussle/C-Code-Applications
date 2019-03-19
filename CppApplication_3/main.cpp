#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>


//main
int main(){

pid_t c_pid;
//fisrt fork
c_pid=fork();
		//for the child
	if(c_pid>0){
	fork();
}
//fork the process again
	fork();
//sleep to help take screenshot
sleep(20);
return 0;
}
