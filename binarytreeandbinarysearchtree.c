#include <stdio.h>
// Function to check if the array represents a Binary Tree
int BinaryTree(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int left = 2 * i + 1;                  // Left child index
        int right = 2 * i + 2;                 // Right child index
        // if (left < size && arr[left] < arr[i]) // Check left child
        //     return 0;
        // if (right < size && arr[right] < arr[i]) // Check right child
        //     return 0;
    }
    return 1;
}
int BST(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1]) // Check if the array is sorted
            return 0;            // Return 0 for false
    }
    return 1; // Return 1 for true
}
int main()
{
    int arr[7] = {1,2,3,4,5,6,7}; // Example array
    int size = 7;
BinaryTree(arr, size);
    // if (BinaryTree(arr, size))
    //     printf("The given array represents a Binary Tree.\n");
    // else
    //     printf("The given array does NOT represent a Binary Tree.\n");
    if (BST(arr, size))
        printf("The given array represents a Binary Search Tree (BST).\n");
    else
        printf("The given array does NOT represent a Binary Search Tree (BST).\n");
    return 0;
}