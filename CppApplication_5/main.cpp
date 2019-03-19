#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>



//create the sempahore between the children and parent
#define SEM_NAME1 "mdmussle.mut1"
#define SEM_NAME2 "mdmussle.mut2"
#define SEM_NAME3 "mdmussle.mut3"


int main(int argc, char *argv[])
{

pid_t pid;

sem_t *mut1, *mut2, *mut3;
int maxnum;

//convert command line
maxnum = atoi(argv[1]);

//initialize to 0
mut1 = sem_open(SEM_NAME1, O_CREAT, O_RDWR, 0);
if (mut1==SEM_FAILED){
printf("%s failed ", SEM_NAME1);
return (-1);
}
//initialize to 0
mut2 = sem_open(SEM_NAME2, O_CREAT, O_RDWR, 0);
if(mut2==SEM_FAILED){
printf("%s failed ", SEM_NAME2);
return (-1);
}
//initialize to 1
mut3 = sem_open(SEM_NAME3, O_CREAT, O_RDWR, 1);
if(mut3==SEM_FAILED){
printf("%s Failed ", SEM_NAME3);
return (-1);
}



//fork a child
pid = fork();
//error check
if(pid<0){
printf("failed\n");
return 1;
}

else if(pid==0){
int i;
for(i=2; i<=maxnum; i=i+3){
sem_wait(mut1);
printf("Child1 is: ");
printf("%d\n", i);
sem_post(mut2);
}
}
//error check
else{
	pid = fork();
	if(pid<0){
	printf("Second failed");
	return 1;
}
//second child
else if(pid==0){
int i;
for(i=0; i<=maxnum; i=i+3){
sem_wait(mut2);
printf("Child2 is: ");
printf("%d\n", i);
sem_post(mut3);
}
}

//parent
else{
int i;
for(i=1; i<=maxnum; i=i+3){
sem_wait(mut3);
printf("Parent is: ");
printf("%d\n", i);
sem_post(mut1);
}

//parent wait
wait(NULL);
wait(NULL);

//remove the semaphore
sem_unlink(SEM_NAME1);
sem_unlink(SEM_NAME2);
sem_unlink(SEM_NAME3);
}
}
return 0;
}

