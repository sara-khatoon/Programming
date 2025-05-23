#include<stdio.h>
int main(){
    int arr[] = {22, 11, 66, 77, 55}; // Array to be sorted
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate array size
    int i, j, temp;

    printf("*Insertion Sort*\n");
    printf("Before sorting:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    // Call the insertion sort function
    for (i = 1; i < size; i++) {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }

    printf("\nAfter sorting:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}