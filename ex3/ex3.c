// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
// C requires importing system / header files
// This is when you import functionalities from other libraries. 
//These could contain functions that you would like to use in  your program so you have to import them. 
//You typically include these at the top of your C file. 
//These could be header files from the standard library or header files that you write.

// Remember!
// gcc -o ex3 ex3.c
// ./ex3
// open another terminal window and ps al for a process list command
// S+ ./ex3 means is in some form of sleep because it is wainting for keyboard input.
// When you give it keyboard input it will wake up and go and get scheduled to run on CPU and actually respond to the keyboard input.
// Z+ (ex3) Z stands for zombie process which means it is terminated but not cleaned up
// Hit enter once on other terminal and then on other terminal do ps al again and zombie will be cleaned up
// Hit enter again on other terminal and then go to other terminal and do ps al again and it will be completely cleaned up.

int main(void)
{
    // Your code here
    pid_t pid = fork() ;
     if (pid < 0)
    {
        exit(1);
    }

    if (pid == 0) {
        printf("The child process printing: Hello! pid: %d\n", (int)getpid());
       
    }
    if ( pid > 0) {
        waitpid(pid, NULL, 0);
        printf("The parent process printing: Goodbye! pid: %d\n", (int)getpid());
       
    }

    return 0;
}
