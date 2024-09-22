#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <math.h>

#define COMMAND_EXIT 'q'
#define COMMAND_HELP 'h'
#define MAX_COMMAND_LENGTH 100
#define EPSILON 1e-10

int parseOperand(float *, char *, char **);

char UNKNOWN_OP_MESSAGE[] = "Unknown OP: %s. Please, use only supported OPs.\n";

int main()
{
    int closing = 0;
    float a, b, result;
    char command[MAX_COMMAND_LENGTH];

    printf("Welcome to Simple Calculator program.\nEnter 'h' to see an instruction.\n");

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
                    printf("Exiting calculator.\n");
                    closing = 1;
                    break;
                case COMMAND_HELP:
                    printf("\nSimple Calculator is able to calculate single-line expressions.\nExpression is a string: A <OP> B, where:\n  - A, B - operands;\n  - <OP> - is one of supported operations: +, -, *, /, //, %%, **.\n\n");
                    break;
                default:
                    printf("Unknown command: %s. Please, use only supported commands.\n", command);
                    continue;
            }
        }
        else
        {
            char aParsed = 0, bParsed = 0, opParsed = 0;
            int idx = 0, op_length = 0;
            float a, b;
            char *rest, *op_start = NULL;

            while (command[idx] && idx < MAX_COMMAND_LENGTH && !(aParsed && bParsed && opParsed)) {
                if (isspace(command[idx])) {
                    idx++;
                    continue;
                }

                if (!aParsed) {
                    aParsed = parseOperand(&a, command, &rest);
                    idx += rest - command;

                    if (!aParsed) {
                        break;
                    }
                } else if (!opParsed) {
                    if (op_start == NULL) {
                        op_start = command + idx;
                    }
                    op_length++;
                    idx++;

                    if (isspace(command[idx]) || isdigit(command[idx]) || isalpha(command[idx])) {
                        opParsed = 1;
                    }
                } else if (!bParsed) {
                    bParsed = parseOperand(&b, command + idx, &rest);

                    if (!bParsed) {
                        break;
                    }
                }
            }

            if (!aParsed || !bParsed || !opParsed) {
                printf("Failed to parse command: %s\n", command);
                continue;
            }

            if (op_length > 2 || op_length == 0)
            {
                *(op_start + op_length) = 0;
                printf(UNKNOWN_OP_MESSAGE, op_start);
                continue;
            }

            switch (op_length)
            {
            case 1:
            {
                switch (*op_start)
                {
                case '+':
                {
                    result = a + b;
                    break;
                }
                case '-':
                {
                    result = a - b;
                    break;
                }
                case '*':
                {
                    result = a * b;
                    break;
                }
                case '/':
                {
                    if (fabs(b) < EPSILON)
                    {
                        printf("Error. Division by zero.\n");
                        continue;
                    }
                    result = a / b;
                    break;
                }
                case '%':
                {
                    if (fabs(b) < EPSILON)
                    {
                        printf("Error. Division by zero.\n");
                        continue;
                    }
                    result = fmod(a, b);
                    break;
                }
                default:
                {
                    printf(UNKNOWN_OP_MESSAGE, op_start);
                    continue;
                }
                }
                break;
            }
            case 2:
            {
                if (*op_start == '/' && *(op_start + 1) == '/')
                {
                    if (b == 0)
                    {
                        printf("Error. Division by zero.\n");
                        continue;
                    }
                    result = (int)(a / b);
                }
                else if (*op_start == '*' && *(op_start + 1) == '*')
                {
                    result = 1;
                    for (int p = 1; p <= abs((int)b); p++)
                    {
                        result = b > 0 ? result * a : result / a;
                    }
                }
                else
                {
                    *(op_start + op_length) = 0;
                    printf(UNKNOWN_OP_MESSAGE, op_start);
                    continue;
                }
            }
            }

            if (isinf(result) || isnan(result))
            {
                printf("Error. Result is infinity or not a number.\n");
                continue;
            }

            printf("%s = %g\n", command, result);
        }
    }
}

int parseOperand(float *num, char *command, char **rest) {
    errno = 0;
    *num = strtof(command, rest);

    if (errno == ERANGE) {
        printf("Operand is too big.\n");
        return 0;
    }

    if (*rest == command) {
        printf("Operand is not a number.\n");
        return 0;
    }

    return 1;
}