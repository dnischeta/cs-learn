#include <stdio.h>

int main()
{
    int whitespace_qty = 0;
    int c;

    while ((c = getchar()) != EOF)
    {
        if (c == '\n' || c == ' ' || c == '\t')
            whitespace_qty++;
    }

    printf("Result is %d\n", whitespace_qty);
}