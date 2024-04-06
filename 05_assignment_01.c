#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

int main(void) {
    int *a = malloc((SIZE+1) * sizeof(int));
    if(a == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    int arr[SIZE] = {1,2,3,5,6,7,8,9};
    for (int i=0; i<SIZE; i++) {
        a[i] = arr[i];
        printf("%d \t",a[i]);
    }

    a[SIZE] = 25;
    printf("\nafter inserting...\n");
    for (int i=0; i<SIZE+1; i++) {
        printf("%d \t",a[i]);
    }

    free(a);
    return 0;
}

/*

 observations :

The code dynamically allocates memory for an array a of integers with a size of SIZE + 1.
It checks if the memory allocation was successful and prints a message if it failed.
An array arr with SIZE elements is initialized with some values.
The values from arr are copied to the dynamically allocated array a.
An additional element is inserted into a at index SIZE.
The elements of a, including the newly inserted element, are printed before and after the insertion.
Finally, the dynamically allocated memory is freed to avoid memory leaks.
*/
