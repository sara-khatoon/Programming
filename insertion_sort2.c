#include <stdio.h>
void insertionSort(int arr[], int size)
{ int temp,k;
    // Insertion Sort Logic
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[i])
            {
                temp = arr[j];
                arr[j] = arr[i];
                for (k = i; k > j; k--)
                {
                    arr[k] = arr[k - 1];
                }
                arr[k + 1] = temp;
            }
        }
    }
}
int main()
{
    int arr[5] = {22, 11, 66, 77, 55};       // Array to be sorted
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate array size
    int i, j;
    printf("*Insertion Sort*\n");
    printf("Before sorting:\n");
    for (i = 0; i <= 4; i++)
        printf("%d\t ", arr[i]);
    // Call the insertionSort function
    insertionSort(arr, size);
    printf("\nAfter sorting:\n");
    for (i = 0; i <= 4; i++)
        printf("%d\t ", arr[i]);
    return 0;
}