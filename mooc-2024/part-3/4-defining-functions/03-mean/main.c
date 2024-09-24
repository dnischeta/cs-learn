#include <stdio.h>

float mean(int, int, int);

int main() {
    printf("%.1f\n", mean(1,2,3));
}

float mean(int a, int b, int c) {
    return (a + b + c) / 3;
}