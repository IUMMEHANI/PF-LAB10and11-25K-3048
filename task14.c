#include <stdio.h>
#include <time.h>
int main() {
    FILE *fp;
    time_t now;
    char *timestamp;
    now = time(NULL);           
    timestamp = ctime(&now);      
    fp = fopen("log.txt", "a");   
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fprintf(fp, "%s", timestamp); 
    fclose(fp);
    fp = fopen("log.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    printf("Execution history from log.txt:\n\n");
    char ch;
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);
    return 0;
}

