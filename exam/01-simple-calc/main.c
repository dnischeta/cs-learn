#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <math.h>

const char WELCOME_MESSAGE[] = "Welcome to Simple Calculator program.\nEnter 'h' to see an instruction.\n";
const char ASK_FOR_COMMAND_MESSAGE[] = "Enter a command: ";
const char INCORRECT_COMMAND_MESSAGE[] = "Failed to parse last command. Please, enter correct command.";
const char EXITING_MESSAGE[] = "Exiting calculator.\n";
const char CALCULATION_ERROR[] = "Calculation error appeared.";
const char UNKNOWN_COMMAND_MESSAGE[] = "Unknown OP: %s. Please, use only supported OPs.\n";
const char ANSWER_MESSAGE[] = "%s = %g\n";
const char HELP_MESSAGE[] = "\nSimple Calculator is able to calculate single-line expressions.\nExpression is a string: A <OP> B, where:\n  - A, B - operands;\n  - <OP> - is one of supported operations: +, -, *, /, //, %%, **.\n\n";

const char COMMAND_EXIT = 'q';
const char COMMAND_HELP = 'h';
const int MAX_COMMAND_LENGTH = 100;
const float EPSILON = 0.000000001;

int main()
{
    int closing = 0;
    float a, b, result;
    char command[MAX_COMMAND_LENGTH];

    printf(WELCOME_MESSAGE);

    while (!closing)
    {
        printf(ASK_FOR_COMMAND_MESSAGE);

        if (fgets(command, MAX_COMMAND_LENGTH, stdin))
        {
            command[strcspn(command, "\n")] = 0;
        }

        if (command[0] == 0) // Empty command -> just ask again
        {
            continue;
        }

        if (strlen(command) == 1)
        {
            switch (command[0])
            {
            case COMMAND_EXIT:
            {
                printf(EXITING_MESSAGE);
                closing = 1;
                break;
            }
            case COMMAND_HELP:
            {
                printf(HELP_MESSAGE);
                break;
            }
            }
        }
        else
        {
            int op_length = 0;
            char *rest, *op_start;
            errno = 0;
            a = strtof(command, &rest);

            if (errno == ERANGE)
            {
                printf("A is too big.\n");
                continue;
            }

            if (rest == command) // It took 0 chars to read float
            {
                printf("A is not a number.\n");
                continue;
            }

            while (isspace(*rest))
            {
                rest++;
            }

            op_start = rest;
            while (!isspace(*rest))
            {
                rest++;
                op_length++;
            }

            while (isspace(*rest))
            {
                rest++;
            }

            char *end_b;

            errno = 0;
            b = strtof(rest, &end_b);

            if (errno == ERANGE)
            {
                printf("B is too large\n");
                continue;
            }

            if (rest == end_b)
            {
                printf("B is not a number.\n");
                continue;
            }

            if (op_length > 2 || op_length == 0)
            {
                *(op_start + op_length) = 0;
                printf(UNKNOWN_COMMAND_MESSAGE, op_start);
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
                    result = (int)a % (int)b;
                    break;
                }
                default:
                {
                    printf(UNKNOWN_COMMAND_MESSAGE, op_start);
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
                    printf("LOL LOL\n");
                    printf(UNKNOWN_COMMAND_MESSAGE, op_start);
                    continue;
                }
            }
            }

            if (result > INT_MAX || result <= INT_MIN)
            {
                printf("Error. Result is too large.\n");
                continue;
            }

            printf(ANSWER_MESSAGE, command, result);
        }
    }
}