#include<stdio.h>

// Function to perform selection sort
void selectionSort(int arr[], int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {22, 11, 66, 77, 55}; // Array to be sorted
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate array size

    printf("*Selection Sort*\n");
    printf("Before sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    // Call the selectionSort function
    selectionSort(arr, size);

    printf("\nAfter sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}