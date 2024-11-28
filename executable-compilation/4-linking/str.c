#include <string.h>
#include <stdio.h>

#define MAX_COMMAND_LENGTH 100

int main() {
    char command[MAX_COMMAND_LENGTH];

    printf("Enter a command: ");

    if (fgets(command, MAX_COMMAND_LENGTH, stdin))
    {
        command[strlen(command) - 1] = 0;
    }

    printf("%d\n", strlen(command));

    return 0;
}