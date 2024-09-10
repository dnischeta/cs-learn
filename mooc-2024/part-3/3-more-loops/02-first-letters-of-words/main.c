#include <stdio.h>
#include <string.h>

int main() {
    char line[1000], insideOfAWord = 0;

    printf("Please type in a sentence: ");
    scanf("%s", line);

    for (int idx = 0; idx < strlen(line); idx++) {
        printf("%c\n", line[idx]);
        // if (line[idx] == '\t') {
        //     insideOfAWord = 0;
        // } else {
        //     if (!insideOfAWord) {
        //         printf("%c\n", line[idx]);
        //     }
        //     insideOfAWord = 1;
        // }
    }
    
    return 0;
}