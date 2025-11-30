#include <stdio.h>
#include <string.h>
int function( int arr[] , int n , int tar , int start){
	if (start > n-1) {
		return -1;
	}
	else if (arr[start] == tar) {
	return start;
    }
	else {
	function(arr , n , tar , start + 1);
    }
}
int main () {
	int array[5];
	int i,target;
	printf("Enter array elemnts:\n");
	for (i=0 ; i<5 ; i++){
		printf("Enter element %d: " , i+1);
		scanf("%d", &array[i]);
	}
	printf("Entered array is: \n");
	for (i=0 ; i<5 ; i++){
		printf(" %d " , array[i]);
	}
    printf("\nEnter element to search: \n");
    scanf("%d" , &target);
    int c = function(array , 5 , target, 0);
    if (c<0) {
    	printf("Number %d not found.\n",target);
	}
	else {
		printf("Number %d found at index %d of array.\n",target,c);
	}
	return 0;
}
