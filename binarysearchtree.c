#include <stdio.h>

int isBST(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) // Check if the array is sorted
            return 0; // Return 0 for false
    }
    return 1; // Return 1 for true
}

int main() {
    int arr[7] = {9, 25, 45, 62, 82, 98, 102}; // Example input
    int size = 7;

    if (isBST(arr, size))
        printf("The given array represents a Binary Search Tree (BST).\n");
    else
        printf("The given array does NOT represent a Binary Search Tree (BST).\n");

    return 0;
}