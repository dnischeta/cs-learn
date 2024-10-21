#include <stdio.h>

struct Result {
    char *name;
    int result1;
    int result2;
    int result3;
} results[] = {
    "Mary", 2, 3, 3,
    "Gary", 5, 1, 8,
    "Larry", 3, 1 ,1
};

void print_result(struct Result *);
struct Result *find_min_avg(struct Result *, int);

int main() {
    struct Result *rp = find_min_avg(results, 3);
    print_result(rp);
}

struct Result *find_min_avg(struct Result results[], int resultsSize) {
    int min_idx = 0;
    float min = (results[0].result1+results[0].result3+results[0].result3) / 3;

    for (int i = 1; i < resultsSize; i++) {
        int avg = (results[i].result1+results[i].result3+results[i].result3) / 3;
        if (avg < min) {
            min_idx = i;
        }
    }

    return &results[min_idx];
}

void print_result(struct Result *result) {
    printf("%s: result1: %i, result2: %i, result3: %i\n", result->name, result->result1, result->result2, result->result3);
}