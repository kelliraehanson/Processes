/*
Write a program that will find the average time it takes for your computer
to make a system call an empty write to stdout. Your program should use the 
`clock_gettime` procedure to time how long a single system call takes. It'll 
do this for one million iterations, and then find the average of all of those 
iterations in nanoseconds.
For some helpful documentation and examples of using time-related system calls,
visit this site: https://www.cs.rutgers.edu/~pxk/416/notes/c-tutorials/gettime.html
While the linked site does say that `clock_gettime()` does not work on OSX, this 
turns out to only be the case for OSX versions < 10.12. Anything later than that 
and `clock_gettime()` should work just fine. 
*/

#include <stdio.h>
#include <unistd.h>
#include <time.h>
// C requires importing system / header files
// This is when you import functionalities from other libraries. 
//These could contain functions that you would like to use in  your program so you have to import them. 
//You typically include these at the top of your C file. 
//These could be header files from the standard library or header files that you write.

#define number_iter 1000000
#define BILLION 1000000000L


// Remember!
// gcc -o ex6 ex6.c
// ./ex6
// open another terminal window and ps al for a process list command
// S+ ./ex6 means is in some form of sleep because it is wainting for keyboard input.
int main()
{
    // Your code here
    struct timespec start, end;
    int sum = 0;
    int difference = 0;
    int average = 0;

    for (int i = 0; i < number_iter; i++) {
        
        clock_gettime(CLOCK_MONOTONIC, &start);

        write(fileno(stdout), NULL, 0);

        clock_gettime(CLOCK_MONOTONIC, &end);

        difference = BILLION * (end.tv_sec - start.tv_sec);
        sum += difference;
    }

    average = sum / number_iter;

    printf("Average: %d ", average);
    
    return 0;
}
