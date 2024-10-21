#include <stdio.h>

struct Matrix {
    int data[10][10];
    int height;
    int width;
};

void row_sums(struct Matrix*);

int main() {
    struct Matrix matrix = {
        .data = {{1, 2}, {1, 2}},
        .width = 2,
        .height = 2
    };

    row_sums(&matrix);
    row_sums(&matrix);

    printf("%d\n", matrix.width);
}

void row_sums(struct Matrix* matrix) {
    for (int i = 0; i < matrix->height; i++) {
        int sum = 0, j = 0;
        for (; j < matrix->width; j++) {
            sum+=matrix->data[i][j];
        }
        matrix->data[i][j+1] = sum;
    }
    matrix->width++;
}