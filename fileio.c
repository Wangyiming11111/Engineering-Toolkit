#include <stdio.h>
#include "fileio.h"

void save_result(const char *label, const char *data) {
    char ans;

    printf("Save result to results.csv? (y/n): ");
    while (getchar() != '\n');
    ans = getchar();

    if (ans == 'y' || ans == 'Y') {
        FILE *f = fopen("results.csv", "a");
        if (!f) {
            perror("Error opening results.csv");
            return;
        }
        fprintf(f, "%s,%s\n", label, data);
        fclose(f);
        printf("Saved.\n");
    } else {
        printf("Not saved.\n");
    }
}
