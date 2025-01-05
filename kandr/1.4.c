#include <stdio.h>

#define CELCIUS_MIN -50
#define CELCIUS_MAX 50

int main()
{
    printf("|%10s|%10s|\n", "Celcius", "Fahrenheit");
    for (int c = CELCIUS_MIN; c <= CELCIUS_MAX; c += 10)
    {
        printf("|----------|----------|\n");
        printf("|%10d|%10.2f|\n", c, c * 1.8 + 32);
    }
    printf("-----------------------\n");
}