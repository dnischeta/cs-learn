#include <stdio.h>
#include <string.h>

#define COMMAND_EXIT 'q'
#define COMMAND_HELP 'h'
#define MAX_COMMAND_LENGTH 100

void run_cli_app(char *help_message, int (*process_cmd)(int, char *)) {
    int closing = 0;
    char command[MAX_COMMAND_LENGTH];

    while (!closing)
    {
        printf("Enter a command: ");

        if (fgets(command, MAX_COMMAND_LENGTH, stdin))
        {
            command[strlen(command) - 1] = 0;
        }
        else
        {
            printf("Failed to read command.\n");
            break;
        }

        if (command[0] == 0)
        {
            continue;
        }

        if (strlen(command) == 1)
        {
            switch (command[0])
            {
                case COMMAND_EXIT:
                    printf("Exiting...\n");
                    closing = 1;
                    break;
                case COMMAND_HELP:
                    printf("%s\n", help_message);
                    break;
                default:
                    printf("Unknown command: %s. Please, use only supported commands.\n", command);
                    continue;
            }
        }
        else
        {
            int status = process_cmd(MAX_COMMAND_LENGTH, command);

            switch (status)
            {
            case 1:
                printf("Failed to parse command: %s\n", command);
                break;
            case 2:
                printf("Unknown operation\n");
                break;
            default:
                break;
            }
        }
    }
};