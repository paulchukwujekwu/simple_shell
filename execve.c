#include <stdio.h>
#include <unistd.h>

int main() {
    char *args[] = {"/bin/ls", "-l", NULL};
    char *env[] = {NULL};

    execve("/bin/ls", args, env);
    printf("This line will not be executed as execve replaces the process.\n");

    return 0;
}

