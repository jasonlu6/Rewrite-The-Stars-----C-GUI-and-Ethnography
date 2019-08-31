/* This is a bare-bones implementation of a C shell to run both horoscopes.c and rewrite_the_stars_2.c */

// At your own risk, it will not fork bomb but segmentation faults are possible! 

// Implementation Credit to: https://www.geeksforgeeks.org/making-linux-shell-c/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/wait.h> 
#include <sys/types.h>


#define MAXCOM 100
#define MAXLIST 20

// clear the shell. 
#define clear() printf("\n\n")

// Greeting part of the shell. 

void init_shell() {
      clear();
      printf("\n");
      printf("REWRITE THE STARS SHELL.");
      printf("\n");

      // get the program name to run on. 
      char program[20];
      printf("Your program is: "); 
      scanf("%s", program);
      // optional, for OS purposes
      char* username = getenv("USER");
      printf("Username is: @%s\n", username);
      printf("Program is: %s\n", program);
      sleep(1);
      clear(); 
}

// Function to take input. 

int input(char* str) {
    if (strlen(str) !=  0) {
	char str_input = scanf("$ rewrite_the_star_shell ");
        return 1;
    } else {
        printf("No command found, shell exitiing ..");
        return -1;
	exit(0);
    }
    return 0;
}

// Run the program within this shell. 
// WARNING: shell will not fork bomb, given only 1 child process, but it may seg fault! 

void run_shell() {
      pid_t pid = fork();
      if (pid == 0) {
         static char *argv[] = {"echo","My program is:",NULL};
         execv("/bin/echo", argv);
         exit(127); // only if shell fails here. 
      } else {
         waitpid(pid,0,0); /* parent wait child to exit. */
      }
}

// Quick manual function. 
void print_manual() {
     printf("\n");
     printf("Here are the functions for the rewrite the stars shell: \n");
     printf("init_shell(): initializes the shell. \n");
     printf("input(char * str): takes input from user command line to shell. \n");
     printf("run_shell(): runs the shell. \n");
     printf("print_manual(): prints the manual of the shell. \n");
     printf("\n");
}

// main. 

int main(int argc, char **argv) {
    init_shell();
    input("gcc -c rewrite_the_stars_2.c");
    run_shell();

    // if user needs help. 

    if (strcmp(argv[0],"help") == 0) {
        print_manual();
    }
    print_manual();
    return 0;
}
