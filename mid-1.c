/*A left rotation operation on an array of size  shifts each of the array's elements  unit to the left. Given an integer, , rotate the array that many steps left and return the result.
Example
After  rotations, .
Returns
int[n]: the rotated array
Input Format
The first line contains two space-separated integers that denote , the number of integers, and , the number of left rotations to perform.
The second line contains  space-separated integers that describe .
Constraints
Sample Input
5 4
1 2 3 4 5
Sample Output
5 1 2 3 4
Explanation




# include <stdio.h>
# include <stdlib.h>
int main(void) {
    int n, d;
    scanf("%d %d", &n, &d);
    int * arr = (int *)malloc(n * sizeof(int));
    for(int i=0; i<n; i++)
      scanf("%d", &arr[i]);
    for (int i=0; i<d; i++) {
        int temp = arr[0];
        for (int j=1; j<n; j++)
          arr[j-1] = arr[j];
        arr[n-1] = temp;
    }
    for(int i=0; i<n; i++)
      printf("%d ", arr[i]);
}


*/


#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, d;
    if (scanf("%d %d", &n, &d) != 2) {
        printf("Invalid input\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input\n");
            free(arr);
            return 1;
        }
    }

    d %= n;  // Reduce the number of rotations
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[(i + d) % n]);
    }
    printf("\n");

    free(arr);
    return 0;
}


/*

Observations:

Problem Description: The code solves the problem of rotating an array to the left by a specified number of steps.

Input Format:

The first line contains two space-separated integers, n and d, denoting the number of integers in the array and the number of left rotations to perform, respectively.
The second line contains n space-separated integers representing the elements of the array.
Constraints:

The constraints specify the limits on the size of the array and the number of rotations.
Implementation:

The code reads the input integers n and d.
It dynamically allocates memory for the array of size n.
It then reads n integers and stores them in the array.
To perform left rotations, it iterates over the array d times:
It stores the first element of the array (arr[0]) in a temporary variable.
It shifts all elements of the array one position to the left.
It assigns the value of the temporary variable to the last element of the array.
Finally, it prints the rotated array.
Optimization:

The code reduces the number of rotations d by taking the modulo of d with n. This optimization helps to reduce the number of unnecessary rotations, as rotating an array by its size n returns the array to its original position.
Instead of physically rotating the array, the code accesses the elements of the array based on their new positions after rotation using the formula (i + d) % n, where i is the current index and n is the size of the array.
Error Handling:

The code checks for invalid input while reading integers from stdin. If any invalid input is detected, it prints an error message and exits the program.
It also checks for memory allocation failure and handles it by printing an error message and freeing the allocated memory before exiting.
*/
