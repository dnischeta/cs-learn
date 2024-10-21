#include <stdio.h>

int main() {
    FILE *fp;
    char name[30];
    char file_name[30];
    char text[1024];

    printf("Whom should I sign this to:");
    scanf("%s", name);
    printf("Where shall I save it:");
    scanf("%s", file_name);

    sprintf(text, "Hi %s, we hope you enjoy learning Python with us! Best, Mooc.fi Team", name);
    fp = fopen(file_name, "w");

    fputs(text, fp);

    fclose(fp);
}