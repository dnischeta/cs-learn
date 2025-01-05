#include <stdio.h>

int main()
{
    int current_space_qty = 0;
    char is_space_string = 1;
    int c;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            if (is_space_string)
            {
                current_space_qty++;
            }
            else {
                putchar(c);
            }
        }
        else if (c == '\n')
        {
            if (is_space_string && current_space_qty > 0)
            {
                putchar(' ');
            }
            putchar('\n');
            is_space_string = 1;
            current_space_qty = 0;
        }
        else
        {
            if (is_space_string && current_space_qty > 0)
            {
                is_space_string = 0;
                while (current_space_qty--)
                    putchar(' ');
            }
            putchar(c);
        }
    }
}