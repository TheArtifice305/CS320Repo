#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT 1024  // Maximum input size
#define MAX_ARGS 64     // Maximum number of arguments
                        // I wasn't sure if these were necessary
                        // just thought I'd add them since
                        // an example I found online had them.

// Function to read input
void read_input(char *input) {
    printf("shell> ");  // Print prompt for the user
    if (fgets(input, MAX_INPUT, stdin) == NULL) {
        printf("\nEnd of input. Exiting.\n");
        exit(0);  // Handle EOF (HINT: you can user Ctrl+D)
    }
}

// Function to parse input into tokens (arguments)
void parse_input(char *input, char **args) {
    char *token = strtok(input, " \t\n");  // Split input by spaces, tabs, and newlines
    int i = 0;

    while (token != NULL) {
        args[i++] = token;  // Store token in argumentss
        token = strtok(NULL, " \t\n");  // Continues splitting
    }
    
    args[i] = NULL;  // NULL-terminate the argument list for execvp
}

int main() {
    char input[MAX_INPUT];  // Buffer (Temp storage area) to store user inputs
    char *args[MAX_ARGS];   // Array to store arguments

    while (1) {  // Loops prompt
        read_input(input);  // Read input

        if (input[0] == '\n') {
            continue;  // Ignore empty input and re-prompt
        }

        parse_input(input, args);  // Step 2: Parse input into arguments

        // Step 3: Fork a new process
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork failed");  // If the fork fails, print the error
            exit(1);
        } 
        else if (pid == 0) {
            // Step 4: In child process, execute the command
            if (execvp(args[0], args) == -1) {
                perror("execvp failed");  // Print error if execvp fails
                exit(1);  // Exit child process on failure
            }
        } 
        else {
            // Step 5: In parent process, wait for child to complete
            int status;
            wait(&status);  // Wait for child process to terminate
            if (WIFEXITED(status)) {
                printf("Child exited with status %d\n", WEXITSTATUS(status));
            }
        }
    }
    return 0;  // Program will end if EOF is detected
}