#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    char command[100];

    while (1) {
        printf("myshell> ");
        fgets(command, sizeof(command), stdin);

        // Remove newline
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "exit") == 0) {
            break;
        }

        pid_t pid = fork();

        if (pid == 0) {
            // Child process
            execlp(command, command, NULL);
            perror("exec failed");
            exit(1);
        } else if (pid > 0) {
            // Parent process
            wait(NULL);
        } else {
            perror("fork failed");
        }
    }

    return 0;
}