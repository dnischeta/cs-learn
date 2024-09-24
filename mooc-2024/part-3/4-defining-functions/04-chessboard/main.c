#include <stdio.h>

void chessboard(int);

int main() {
    chessboard(3);
    printf("\n");
    chessboard(6);
}

void chessboard(int n) {
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            putchar((row + col) % 2 == 0 ? '1' : '0');
        }
        putchar('\n');
    }
}