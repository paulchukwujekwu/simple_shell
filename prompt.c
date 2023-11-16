#define _GNU_SOURCE  // This is needed to use getline with glibc
#include <stdio.h>
#include <stdlib.h>

/**
*Main - This program will read and print user commands,
*	and you can exit it by using Ctrl+D
*	or the equivalent method on your platform.
*	We include _GNU_SOURCE to enable the getline function 
*	with glibc (GNU C Library).
*	It enters an infinite loop that waits for user input.
*	It prints "$ " as a command prompt.
*	It uses getline to read the user's command 
*	into the dynamically allocated line buffer.
*	If the user presses Ctrl+D (or another equivalent key 
*	depending on the system), getline returns -1, 
*	and the loop breaks, allowing you to exit the program.
* 	It removes the trailing newline character from the user's input.
*	It prints the entered command on the next line.
*	It frees the dynamically allocated memory for the line after usage.
*/



int main() {
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    while (1) {
        printf("$ ");

        
        nread = getline(&line, &len, stdin);

        if (nread == -1) {
            
            break;
        }

        
        if (nread > 0 && line[nread - 1] == '\n') {
            line[nread - 1] = '\0';
        }

        
        printf("You entered: %s\n", line);
    }

    
    free(line);

    return 0;
}

