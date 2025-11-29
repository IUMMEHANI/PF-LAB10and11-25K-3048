#include <stdio.h>
#include <string.h>
void reverse(char string[], int start, int end) {
    if (start >= end)
        return;
    char temp = string[start];
    string[start] = string[end];
    string[end] = temp;
    reverse(string, start + 1, end - 1);
}
int main() {
    int n;
    printf("Enter size of string: ");
    scanf("%d", &n);
    getchar(); 
    char str[n + 1]; 
    printf("Enter string: ");
    fgets(str, n + 1, stdin);
    str[strcspn(str, "\n")] = '\0';
    reverse(str, 0, strlen(str) - 1);
    printf("Reversed string is: %s\n", str);
    return 0;
}

