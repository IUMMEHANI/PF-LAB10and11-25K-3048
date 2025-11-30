#include <stdio.h>
int main() {
    FILE *fp;
    char ch;
    fp = fopen("data.txt", "w");
    if (fp == NULL) {
        printf("Error creating file!\n");
        return 1;
    }
    fprintf(fp, "Hello I am HANI and I am superb.\nWhat about you");
    fclose(fp);
    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    printf("Contents of data.txt before deletion:\n\n");
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);
    fp = fopen("data.txt", "w");
    if (fp == NULL) {
        printf("\nError opening file for deletion!\n");
        return 1;
    }
    fclose(fp); 
    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    printf("\n\nContents of data.txt after deletion:\n\n");
    ch = fgetc(fp);
    if (ch == EOF) {
        printf("File is empty.\n");
    } else {
        do {
            putchar(ch);
        } while ((ch = fgetc(fp)) != EOF);
    }
    fclose(fp);
    return 0;
}

