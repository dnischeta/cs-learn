#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void lol() {
    printf("End\n");
}

int main() {
    atexit(&lol);
    return 1;
    FILE *fp;
    int cmd;
    char diary_entry[1024];

    fp = fopen("diary.txt", "a+");

    while (1) {
        printf("1 - add an entry, 2 - read entries, 0 - quit\n");
        printf("Function: ");
        cmd = getchar();

        switch (cmd) {
            case '1':
                printf("Diary entry: ");
                if (fgets(diary_entry, 1024, stdin)) {
                    diary_entry[strlen(diary_entry) - 1] = 0;
                    fputs(diary_entry, fp);
                    printf("\nDiary saved\n");
                    break;
                } else {
                    goto exit;
                }
            case '2':
                break;
            case '0':
                goto exit;
        }

    }

    exit:
        fclose(fp);
        printf("Bye now!\n");
}