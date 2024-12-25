#include <stdio.h>

#include "./include/cli.h"
#include "./include/calc.h"

int main()
{
    char *HELP_MESSAGE = "\nSimple Calculator is able to calculate single-line expressions.\nExpression is a string: A <OP> B, where:\n  - A, B - operands;\n  - <OP> - is one of supported operations: +, -, *, /, //, %%, **.\n";
    printf("Welcome to Simple Calculator program.\nEnter 'h' to see an instruction.\n");
    run_cli_app(HELP_MESSAGE, process_cmd);
}
