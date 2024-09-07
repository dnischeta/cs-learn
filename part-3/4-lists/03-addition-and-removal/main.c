#include <stdio.h>

#define MAX_LENGTH 5

void print_arr(int *ptr, int length) {
    printf("The list is now [");
    for (int idx = 0; idx < length; idx++) {
        printf("%i", *(ptr+idx));

        if (idx < length - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void get_command(char *command) {
    char c = 0;
    printf("a(d)d, (r)emove or e(x)it: ");
    while ((c = getchar()) != '\n') {
        if (c >= 97 && c <= 122) {
            *command = c;
        }
    }
}

int main() {
    unsigned int length = 0; 
    int arr[MAX_LENGTH];
    char command;

    while (1) {
        print_arr(arr, length);
        get_command(&command);

        switch(command) {
            case 'd': {
                if (length == MAX_LENGTH) {
                    printf("Maximum array length reached. Element won't be added.\n");
                    break;
                }

                arr[length] = length + 1;
                length++;
                break;
            }
            case 'r': {
                if (length > 0) {
                    length--;
                }
                break;
            }
            case 'x': {
                printf("Bye!\n");
                break;
            }
            default: {
                printf("Unknown command %i\n", command);
                break;
            }
        }

        if (command == 'x') {
            break;
        }

        command = 0;
    }

    return 0;
}