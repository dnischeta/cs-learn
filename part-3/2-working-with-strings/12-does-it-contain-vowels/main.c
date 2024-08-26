#include <stdio.h>

int main() {
    char word[30];
    char aFound = 0, eFound = 0, oFound = 0;

    printf("Please type in a string: ");
    scanf("%s", word);

    for(int idx = 0; word[idx] != '\0'; idx++) {
        if (word[idx] == 'a') {
            aFound = 1;
        } else if (word[idx] == 'e') {
            eFound = 1;
        } else if (word[idx] == 'o') {
            oFound = 1;
        }
    }

    printf(aFound ? "a found\n" : "a not found\n");
    printf(eFound ? "e found\n" : "e not found\n");
    printf(oFound ? "o found\n" : "o not found\n");
    
    return 0;
}