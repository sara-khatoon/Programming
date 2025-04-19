#include <stdio.h>
#define NULL_VALUE -1  // NULL nodes ko represent karne ke liye
// Function to find maximum level of binary tree using loop (BFS)
int findMaxLevel(int arr[], int size) {
    if (size == 0 || arr[0] == NULL_VALUE)
        return 0; // Agar tree empty hai to level 0 hoga
    
    int level = 0;  // Track karega ki hum konse level pe hain
    int index = 0;  // Start root node se
    int nodesInLevel = 1;  // Pehle level mein sirf ek node hoti hai

    while (nodesInLevel > 0) { 
        int nextLevelNodes = 0;  // Next level ke nodes count karne ke liye

        // Har node ke liye check karo ki left aur right exist karta hai ya nahi
        for (int i = 0; i < nodesInLevel; i++) {
            if (index >= size) break;  // Agar array ke bahar chale gaye to break karo
            
            // Left child exist karta hai?
            if (2 * index + 1 < size && arr[2 * index + 1] != NULL_VALUE)
                nextLevelNodes++;

            // Right child exist karta hai?
            if (2 * index + 2 < size && arr[2 * index + 2] != NULL_VALUE)
                nextLevelNodes++;
            
            index++;  // Next node pe move karo
        }

        if (nextLevelNodes > 0) level++;  // Ek level complete ho gaya
        nodesInLevel = nextLevelNodes;  // Agle level ke nodes ko update karo
    }

    return level;  // Final maximum level return karo
}

// Main function
int main() {
    // Binary tree ka array representation
    int tree[] = {1, 2, 3, 4, 5, 7, 6};  
    int size = sizeof(tree) / sizeof(tree[0]);

    // Maximum level find karke print karo
    int maxLevel = findMaxLevel(tree, size);
    printf("The maximum level of the binary tree is: %d\n", maxLevel);

    return 0;
}