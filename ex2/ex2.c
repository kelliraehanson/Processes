// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
// C requires importing system / header files


// Remember!
// gcc -o ex2 ex2.c
// ./ex2
// open another terminal window and ps al for a process list command
// S+ ./ex2 means is in some form of sleep because it is wainting for keyboard input.
// When you give it keyboard input it will wake up and go and get scheduled to run on CPU and actually respond to the keyboard input.
// Z+ (ex2) Z stands for zombie process which means it is terminated but not cleaned up
// Hit enter once on other terminal and then on other terminal do ps al again and zombie will be cleaned up
// Hit enter again on other terminal and then go to other terminal and do ps al again and it will be completely cleaned up.

int main(void)
{
    // Your code here 
     FILE *fp;
    fp = fopen("text.txt", "w");

    int i = fork();
    if (i < 0) {
        fprintf(stderr, "Oh no, fork() failed!\n");
        exit(1);

    } else if (i == 0) {
        printf("** This is the child process **\n");
        char *child_string = "This is child string!\n";
        fwrite(child_string, sizeof(char), strlen(child_string), fp);

    } else {
        printf("** This is the parent process **\n");
        char *parent_string = "This is parent string.\n";
        fwrite(parent_string, sizeof(char), strlen(parent_string), fp);
    }

    return 0;
}
