#include <stdio.h>
#include <stdlib.h>
int sum(int n){
	if (n == 0){
		return 0;
	}
	else {
	    return n % 10 + sum(n/10);
    }
}
int main () {
	int num;
	printf("Enter a number: ");
	scanf("%d" , &num);
	int c = sum(num);
	printf("Sum of each digit of a number is: %d" , c);
	return 0;
}
