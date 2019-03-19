#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>



int main (int argc, char *argv[])
{

	pid_t pid;

	int maxnum, seq , d=1;

//make sequences to get different outcomes on time
	int slow [33][4]= {
{1,1,1,1},
{1,1,1,8},
{1,1,8,1},
{1,1,8,8},
{1,4,1,1},
{1,4,1,4},
{1,4,4,1},
{1,4,4,4},
{4,1,1,1},
{4,1,1,4},
{4,1,4,1},
{4,1,4,4},
{4,4,1,1},
{4,4,1,4},
{4,4,4,1},
{4,4,4,4},
{1,1,10,4},
{1,4,10,1},
{1,4,10,1},
{4,1,10,1},
{4,1,10,4},
{4,4,10,1},
{4,4,10,4},
{4,4,16,4},
{1,10,1,1},
{1,10,1,4},
{1,10,4,1},
{1,10,4,4},
{4,10,1,1},
{4,10,1,4},
{4,10,4,1},
{4,10,4,4},
{4,16,4,1}
};

	maxnum = atoi(argv[1]);//convert command lin to int
	seq = atoi(argv[2]);

//fork a child
	pid = fork();

if(pid<0){//failed
printf("failed\n");
return 1;
}

else if(pid == 0){//child1
	int i;
	for (i=2; i<=maxnum; i=i+3){
	sleep(d*slow[seq][i]);
	printf("child1 process: ");
	printf("%d\n", i);
	 }
}

else{
	pid = fork();//fork second child
	if(pid<0){//failed second
printf("second failed");
return 1;
}
      else if(pid == 0){
	int i;
	for(i=0; i<=maxnum; i=i+3){
	sleep(d*slow[seq][i]);
	printf("Child2 process: ");
	printf("%d\n", i);
    }
}

else{
//parent

	int i;
	for(i=1; i<=maxnum; i=i+3){
	sleep(d*slow[seq][i]);
	printf("Parent process: ");
	printf("%d\n", i);
}
//parent wait
wait(NULL);
wait(NULL);
  }
}
return 0;
}
