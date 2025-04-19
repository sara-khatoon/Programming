#include <stdio.h>
int main()
{
    int arr[11] = {11, 22, 32, 34, 41, 45, 55, 60, 65, 70, 75}; // Example sorted array
    int i;
    int size = 11;
    printf("Enter the number to search\n");
    int choice;
    scanf("%d", &choice);
    int low = 0, high = size - 1, mid;
    int flag = 1;
    for (mid = (low + high) / 2; low <= high; mid = (low + high) / 2)
    {
        if (arr[mid] == choice) // Check if the element is found
        {
            printf("Element found at index %d\n", mid);
            break;
            flag = 0;
        }
        else if (arr[mid] < choice) // If the middle element is less than the choice, search in the right half
        {
            low = mid + 1;
        }
        else // If the middle element is greater than the choice, search in the left half
        {
            high = mid - 1;
        }
    }
    if (flag == 1) // If the loop completes without finding the element
    {
        printf("Element not found\n");
    }
    return 0;
}