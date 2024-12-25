#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>

#include "math_utils.h"

#define EPSILON 1e-10

int process_cmd(int maxlen, char *command)
{
    float result = 0;
    char aParsed = 0, bParsed = 0, opParsed = 0;
    int idx = 0, op_length = 0;
    float a, b;
    char *rest, *op_start = NULL;

    while (command[idx] && idx < maxlen && !(aParsed && bParsed && opParsed))
    {
        if (isspace(command[idx]))
        {
            idx++;
            continue;
        }

        if (!aParsed)
        {
            aParsed = parseFloat(&a, command, &rest);
            idx += rest - command;

            if (!aParsed)
            {
                break;
            }
        }
        else if (!opParsed)
        {
            if (op_start == NULL)
            {
                op_start = command + idx;
            }
            op_length++;
            idx++;

            if (isspace(command[idx]) || isdigit(command[idx]) || isalpha(command[idx]))
            {
                opParsed = 1;
            }
        }
        else if (!bParsed)
        {
            bParsed = parseFloat(&b, command + idx, &rest);

            if (!bParsed)
            {
                break;
            }
        }
    }

    if (!aParsed || !bParsed || !opParsed)
    {
        return 1;
    }

    if (op_length > 2 || op_length == 0)
    {
        *(op_start + op_length) = 0;
        return 2;
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
                return 3;
            }
            result = a / b;
            break;
        }
        case '%':
        {
            if (fabs(b) < EPSILON)
            {
                printf("Error. Division by zero.\n");
                return 3;
            }
            result = fmod(a, b);
            break;
        }
        default:
        {
            // printf(UNKNOWN_OP_MESSAGE, op_start);
            return 2;
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
                return 3;
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
            // printf(UNKNOWN_OP_MESSAGE, op_start);
            return 2;
        }
    }
    }

    if (isinf(result) || isnan(result))
    {
        printf("Error. Result is infinity or not a number.\n");
        return 3;
    }

    printf("%s = %g\n", command, result);
    return 0;
};
