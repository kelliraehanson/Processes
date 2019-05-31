// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
// C requires importing system / header files
// This is when you import functionalities from other libraries. 
//These could contain functions that you would like to use in  your program so you have to import them. 
//You typically include these at the top of your C file. 
//These could be header files from the standard library or header files that you write.

#define MSGSIZE 16

char* msg1 = "hello world #1";
char* msg2 = "hello world #2";
char* msg3 = "hello world #3";

// Remember!
// gcc -o ex5 ex5.c
// ./ex5
// open another terminal window and ps al for a process list command
// S+ ./ex5 means is in some form of sleep because it is wainting for keyboard input.
int main(void)
{
    // Your code here
    char inbuf[MSGSIZE];

    int p[2];
    printf("%d \n", p[0]);
    printf("%d \n", p[1]);

    if (pipe(p) < 0) {
        fprintf(stderr, "Oh no, pipe has failed!\n");
        exit(1);
    }
    write(p[1], msg1, MSGSIZE);
    write(p[1], msg2, MSGSIZE);
    write(p[1], msg3, MSGSIZE);

    for (int i = 0; i < 3; i++) {
        read(p[0], inbuf, MSGSIZE);

        printf("%s \n", inbuf);
    }
    
    return 0;
}
