#include <stdio.h>
#include <string.h>
#include "shell.h"

#define BUFFER_SIZE 1024

void run_shell() {
    char input[BUFFER_SIZE];

    while (1) {
        printf("myshell> ");
        fgets(input, BUFFER_SIZE, stdin);

        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "exit") == 0) {
            break;
        }

        printf("You typed: %s\n", input);
    }
}