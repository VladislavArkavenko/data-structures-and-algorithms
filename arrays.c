#include <stdio.h>
#include <stdlib.h>

// This modifies initial array!
void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}
int LinearSearch(int *arr, int arrLength, int key) {
    for (int i = 0; i < arrLength; i++) {
        if (key == arr[i]) {
            // Transposition
            // swap(&arr[i], &arr[i-1]);
            // Move to head
            // swap(&arr[i], &arr[0]);
            return i;
        }
    }
    return -1;
}

int BinarySearch(int *arr, int arrLength, int key) {
    int startIndex, midIndex, endIndex;
    startIndex = 0;
    endIndex = arrLength - 1;

    while (startIndex < endIndex) {
        midIndex = (startIndex + endIndex) / 2;
        if (key == arr[midIndex])
            return midIndex;
        else if (key < arr[midIndex])
            endIndex = midIndex - 1;
        else
            startIndex = midIndex + 1;
    }
    return -1;
}

int main() {
    // Array created in stack
    int A[5];

    // C language
    // Array created in heap
    int *P;
    P = (int *)malloc(5 * sizeof(int));
    // To clear from heap when no need
    // free(P);
    // To access array
    // P[0] = 5;

    // C++ language
    // Array created in heap
    // P = new int[5];
    // To clear from heap when no need
    // delete []P;
    // To access array
    // P[0] = 5;

    // To resize array
    // 1. Create new bigger array in heap
    int *Q;
    Q = (int *)malloc(10 * sizeof(int));
    // 2. Copy values
    for (int i = 0; i < 5; i++) {
        Q[i] = P[i];
    }
    // 3. Delete old array from heap
    free(P);
    // 3. Update pointer with new array address
    P = Q;
    // 4. Delete initial pointer for new array
    Q = NULL;

    // 2d array in stack
    int B[3][5];
    // 2d array in heap
    int **C;
    C = (int **)malloc(3 * sizeof(int *));
    C[0] = (int *)malloc(5 * sizeof(int));
    C[1] = (int *)malloc(5 * sizeof(int));
    C[2] = (int *)malloc(5 * sizeof(int));

    // Array search algorithms
    int *arr;
    int arrLength = 10; // can be calculated as sizeof(arr) / sizeof(arr[0])
    arr = (int *)malloc(arrLength * sizeof(int));
    for (int i = 0; i < arrLength; i++) {
        arr[i] = i*2;
    }
//    printf("Index: %d\n", LinearSearch(arr, arrLength, 8));
    printf("Index: %d\n", BinarySearch(arr, arrLength, 7));
    printf("Array: ");
    for (int i = 0; i < arrLength; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}