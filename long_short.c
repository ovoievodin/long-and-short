#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if(argc < 4) {
        printf("Invalid input. Must provide at least 3 files.\n");
        printf("Exiting...\n");
        exit(1);
    }

    FILE *srcFile = fopen(argv[1], "r");
    FILE *destFile1 = fopen(argv[2], "w");
    FILE *destFile2 = fopen(argv[3], "w");
    
    if(!srcFile) {
        printf("Can't open a src file.\n");
        printf("Exiting...\n");
        exit(1);
    }
    if(!destFile1) {
        printf("Can't open a first destinaton file.\n");
        printf("Exiting...\n");
        exit(1);
    }
    if(!destFile2) {
        printf("Can't open a second destination file.\n");
        printf("Exiting...\n");
        exit(1);
    }

    char line[1000];
    int count_long = 0;
    int count_short = 0;

    while(fgets(line, 1000, srcFile) != NULL) {
        if(strlen(line) < 20) {
            for(int i = 0; i < strlen(line); i++) {
                line[i] = toupper(line[i]);
            }
            fprintf(destFile1, "%s", line);
            count_short++;
        } else {
            for(int i = 0; i < strlen(line); i++) {
                line[i] = tolower(line[i]);
            }
            fprintf(destFile2, "%s", line);
            count_long++;
        }
    }

    printf("%d lines were written to %s\n", count_short, argv[2]);
    printf("%d lines were written to %s", count_long, argv[3]);

    fclose(srcFile);
    fclose(destFile1);
    fclose(destFile2);
}