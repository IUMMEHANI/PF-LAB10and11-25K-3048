#include <stdio.h>
#include <string.h>
void reverse(char words[], int start, int end) {
    if (start >= end){
        return;
	}
    char temp = words[start];
    words[start] = words[end];
    words[end] = temp;
    reverse(words, start + 1, end - 1);
}
int main() {
    int i;
    char array[5][20];
    char copy[5][20];    
    for (i = 0; i < 5; i++) {
        printf("Enter word %d: ", i + 1);
        scanf("%s", array[i]);
    }
    for (i = 0; i < 5; i++) {
        strcpy(copy[i], array[i]);   
    }
    printf("\nEntered words are:\n");
    for (i = 0; i < 5; i++) {
        printf("%s\n", array[i]);
    }
    for (i = 0; i < 5; i++) {
        reverse(copy[i], 0, strlen(copy[i]) - 1);   
        if (strcmp(array[i], copy[i]) == 0) {
            printf("%s is a palindrome\n", array[i]);
        } else {
            printf("%s is NOT a palindrome\n", array[i]);
        }
    }
    return 0;
}

