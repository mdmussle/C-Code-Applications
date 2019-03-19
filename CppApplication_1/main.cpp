#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<signal.h>


//main class
int main(int argc, char *argv[])
{

int i, number1, number2;

//%s is to print out a string, %d means to print out an int.


//check num of args. Must be 2 args
if (argc==3)
{

printf("The args supplied are %s and %s\n", argv[1], argv[2]);
}

else if (argc>3)
{

printf("Too many args\n");
printf("Need two args that are positive ints X is printed Y times.", argv[0]);
}

else
{

printf("Two args needed.\n");
}

//converty the args to ints by using atoi
number1=atoi(argv[1]);
number2=atoi(argv[2]);

//check if args are negative if so then print error
if(number1<0)
{

printf("Error %d is negative.", number1);
}
if(number2<0)
{

printf("Error %d is negative.", number2);
}


//display
printf("Print %d, %d times..\n", number1, number2);
//for loop to print out number however many times
for(i=0;i<number2;i++)
{

//counter
printf("%d\n", number1);
}
return 0;
}
