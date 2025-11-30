#include <stdio.h>
#include <string.h>
int vowels(char str[], int start, int end) {
    if (start > end) {
        return 0;
    }
    int count = 0;
    if (str[start] == 'a' || str[start] == 'e' || str[start] == 'i' ||
        str[start] == 'o' || str[start] == 'u' ||
        str[start] == 'A' || str[start] == 'E' || str[start] == 'I' ||
        str[start] == 'O' || str[start] == 'U') 
    {
        count = 1;
    }
    return count + vowels(str, start + 1, end); 
}
int main() {
    char string[20];
    printf("Enter a String: ");
    fgets(string, sizeof(string), stdin);
    string[strcspn(string, "\n")] = '\0';
    int len = strlen(string);
    int c = vowels(string, 0, len - 1);
    printf("Total vowels in string are: %d", c);
    return 0;
}

