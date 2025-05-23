#include<stdio.h>
int main(){
    int arr[7];// = {11,34,22,32,45,41,55}; // Example array
    
    int size = 7;
    int i;
    for(i = 0; i < size; i++){
        printf("Enter the element %d\n",i+1);
        scanf("%d",&arr[i]); // Input elements into the array
    }
    printf("Enter the number to search\n");
    int choice;
    scanf("%d",&choice);
    for(i = 0; i < size; i++)
    {
        if (arr[i] == choice) // Check if the element is found
        {
            printf("Element found at index %d\n", i);
            break;
        }
    }
    if (i == size) // If the loop completes without finding the element
    {
        printf("Element not found\n");
    }

    return 0;
}