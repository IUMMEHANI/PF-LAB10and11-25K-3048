#include <stdio.h>
int main() {
    FILE *file1, *file2, *file3;
    char ch;
    file1 = fopen("file.txt", "r");
    if (file1 == NULL) {
        printf("Error opening file.txt\n");
        return 1;
    }
    file2 = fopen("log.txt", "r");
    if (file2 == NULL) {
        printf("Error opening log.txt\n");
        fclose(file1);
        return 1;
    }
    file3 = fopen("combine.txt", "w");
    if (file3 == NULL) {
        printf("Error creating combine.txt\n");
        fclose(file1);
        fclose(file2);
        return 1;
    }
    while ((ch = fgetc(file1)) != EOF) {
        fputc(ch, file3);
    }
    fputc('\n', file3);
    while ((ch = fgetc(file2)) != EOF) {
        fputc(ch, file3);
    }
    fclose(file1);
    fclose(file2);
    fclose(file3);
    file3 = fopen("combine.txt", "r");
    if (file3 == NULL) {
        printf("Error opening combine.txt\n");
        return 1;
    }
    printf("Contents of combine.txt:\n\n");
    while ((ch = fgetc(file3)) != EOF) {
        putchar(ch);
    }
    fclose(file3);
    return 0;
}

