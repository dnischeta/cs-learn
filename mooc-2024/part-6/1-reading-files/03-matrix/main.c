#include <stdio.h>
#include <stdlib.h>

#define MAX_MATRIX_SIZE 1000

int matrix_sum(int matrix[], int size);
int matrix_max(int matrix[], int size);
int row_sum(int matrix[], int width, int height, int row_idx);

int main() {
    int matrix[MAX_MATRIX_SIZE];
    int width = 0;
    int height = 0;
    char *line;
    size_t line_len;
    FILE *fp;

    fp = fopen("matrix.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    int idx = 0;
    while ((line = fgetln(fp, &line_len)) != NULL) {
        char *line_end = line + line_len;
        char *end_ptr;

        while (line < line_end) {
            matrix[idx] = strtol(line, &end_ptr, 10);
            line = end_ptr + 1;
            idx++;
        }

        if (width == 0) {
            width = idx;
        }

        height++;
    }

    printf("Matrix sum: %d\n", matrix_sum(matrix, width*height));
    printf("Matrix max: %d\n", matrix_max(matrix, width*height));
    printf("Matrix 1st row sum: %d\n", row_sum(matrix, width, height, 1));

    fclose(fp);
    
    return 0;
}

int matrix_sum(int matrix[], int size) {
    int sum = 0;

    for (int idx = 0; idx < size; idx++) {
        sum += matrix[idx];
    }

    return sum;
}

int matrix_max(int matrix[], int size) {
    int max = matrix[0];

    for (int idx = 1; idx < size; idx++) {
        if (matrix[idx] > max) {
            max = matrix[idx];
        }
    }

    return max;
}

int row_sum(int matrix[], int width, int height, int row_idx) {
    if (row_idx >= height) {
        return 0;
    }

    int sum = 0;

    for (int idx = row_idx * width; idx < (row_idx + 1) * width; idx++) {
        sum += matrix[idx];
    }

    return sum;
}
