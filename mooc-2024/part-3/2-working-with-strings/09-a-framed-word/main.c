#include <stdio.h>
#include <string.h>

int main() {
    char hor[] = "******************************";
    char word[28];

    printf("Word: ");
    scanf("%s", word);

    int padL = (30 - 2 - strlen(word)) / 2;
    int padR = 30 - 2 - strlen(word) - padL;

    printf("%s\n", hor);
    printf("*");
    while (padL > 0) {
        padL--;
        printf(" ");
    }
    printf("%s", word);
    while (padR > 0) {
        padR--;
        printf(" ");
    }
    printf("*\n");

    printf("%s\n", hor);
    
    return 0;
}