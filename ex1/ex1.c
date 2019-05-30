// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// C requires importing system / header files 

// NOTES:
// Processes:
// What does a computer need to execute a program?
// - some time of a CPU
// - some memory

// Processes are all isolated  by default. Which means they aren't able to communicate by default. No process is ever aware of another process.

// on mac you can type the command top into a terminal it will pull up a process list

// The steps to initialize a process:
// - some segment of working memory is allocated for the program being executed. 
// - An entry is added to the operating system's process list
// - the newly- initialized process will now be scheduled by the OS's scheduling algorithm. 

// Not all processes are created equal:
// - The operating system is nothing more than a conglomeration of multiple processes that each perform some privileged operation.
// privileged vs. non-privileged processes
// Most are going to be non-privileged processes by default.
// The schedule process is a privileged process.

// What are privileged operations?
// - creating new processes
// - destroying existing processes
// - allocating memory
// - accessing hardware functionality 

// System calls:
// learn how processes utilize privileged operations:

// How do run of the mill processes perform privileged operations?
// The answer is system calls!
// System calls are requests to the operation system for it to perform a privileged operation on behalf of the calling process. 
// A lot like api calls.
// Why do we do it this way? 
// Because it is more secure. The operating system act like a gate keeper. When it wasn't this way years ago that is how gaming got popular on windows etc. 

// Some commonly used system calls:
// - fork() - creates a copy of an existing process
// - exec() - executes a specified file 
// - chdir() - changes the current working directory
// - pipe() - creates a pipe for interprocess communication

// rc is convention for “return code” 
// `rv`, that's "return value"

// a zombie process is defined as a process that has finished executing but has as of yet not been cleaned up


// Remember!
// gcc -o ex1 ex1.c
// ./ex1
// open another terminal window and ps al for a process list command
// S+ ./ex1 means is in some form of sleep because it is wainting for keyboard input.
// When you give it keyboard input it will wake up and go and get scheduled to run on CPU and actually respond to the keyboard input.
// Z+ (ex1) Z stands for zombie process which means it is terminated but not cleaned up
// Hit enter once on other terminal and then on other terminal do ps al again and zombie will be cleaned up
// Hit enter again on other terminal and then go to other terminal and do ps al again and it will be completely cleaned up.

int main(void)
{
    // Your code here
    int x = 0;

    printf("\n");
    printf("Hi! Here is the processID: (pid: %d). Now let's call fork()\n", (int)getpid());
    printf("\n");

    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "Oh no, fork() failed!\n");
        printf("\n");
    } else if(rc == 0) {
        x = 10;
        printf("Hi again! Here is the child: (pid: %d) (x: %d) \n", (int) getpid(), x);
        printf("\n");
    } else {
        x = 100;
        printf("Hi again! Here is the parent: (pid: %d) of child %d (x: %d)\n", (int) getpid(), rc, x);
        printf("\n");
    }

    return 0;
}

// int main(void)
// {
//     pid_t pid = fork();

//     if (pid == 0) {
//         printf("Child!\n");
//         exit(3);
//     } else {
//         printf("Parent!\n");
//         printf("Press RETURN to wait\n");
//         getchar();

//         wait(NULL);

//         printf("Press RETURN to exit\n");
//         getchar();
//     }

//     return 0;
// }