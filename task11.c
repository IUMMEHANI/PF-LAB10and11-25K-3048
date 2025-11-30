#include <stdio.h>
#include <string.h>
int main() {
	int i;
	int found = 0;
	char words[3][15] = {"Samia" , "Hani" , "Kainat"};
	char word[15];
	printf("Enter a word to search: ");
	scanf("%s" , &word);
	for(i=0;i<3;i++){
		if (strcmp(words[i],word) == 0){
			found = 1;
			break;
		}
		else {
			found = 0;
		}
	}
	if(found == 1){
		printf("Given word %s is present in words array." , word);
	}
	else {
	    printf("Given word %s is not present in words array." , word);	
	}
	return 0;
}
