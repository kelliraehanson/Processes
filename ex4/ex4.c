// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
// C requires importing system / header files
// This is when you import functionalities from other libraries. 
//These could contain functions that you would like to use in  your program so you have to import them. 
//You typically include these at the top of your C file. 
//These could be header files from the standard library or header files that you write.


// Remember!
// gcc -o ex4 ex4.c
// ./ex4
// open another terminal window and ps al for a process list command
// S+ ./ex4 means is in some form of sleep because it is wainting for keyboard input.
// When you give it keyboard input it will wake up and go and get scheduled to run on CPU and actually respond to the keyboard input.
// Z+ (ex4) Z stands for zombie process which means it is terminated but not cleaned up
// Hit enter once on other terminal and then on other terminal do ps al again and zombie will be cleaned up
// Hit enter again on other terminal and then go to other terminal and do ps al again and it will be completely cleaned up.
int main(void)
{
    // Your code here
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "Oh no, fork() failed!\n");
        exit(1);

    } else if (rc == 0) {
        char *args[] = {"ls", "-l", (char *) NULL};
        // execl("/bin/ls", args);
        // execle("/bin/ls", args);
        execv("/bin/ls", args);
        
    } else {
        printf("Hi!");
    }

    return 0;
}
