#include <stdio.h>

int main() {
    int num;
    int fac = 1;

    while (1) {
        fac = 1;
        printf("Please type in a number: ");
        scanf("%i", &num);

        if (num <= 0) {
            break;
        }

        for (int n = num; n >= 1; n--) {
            fac *= n;
        }

        printf("The factorial of the number %i is %i\n", num, fac);
    }
    
    


    
    return 0;
}