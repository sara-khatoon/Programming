#include <stdio.h>

void optimalPageReplacement(int pages[], int n, int capacity) {
    int frames[capacity];
    int pageFaults = 0;

    // Initialize frames to -1 (indicating empty)
    for (int i = 0; i < capacity; i++) {
        frames[i] = -1;
    }

    printf("Page Reference\tFrames\n");

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int found = 0;

        // Check if the page is already in the frame
        for (int j = 0; j < capacity; j++) {
            if (frames[j] == page) {
                found = 1;
                break;
            }
        }

        if (!found) {
            // Page fault occurs
            int replaceIndex = -1, farthest = i + 1;

            // Find the page to replace
            for (int j = 0; j < capacity; j++) {
                int k;
                for (k = i + 1; k < n; k++) {
                    if (frames[j] == pages[k]) {
                        if (k > farthest) {
                            farthest = k;
                            replaceIndex = j;
                        }
                        break;
                    }
                }
                if (k == n) { // If the page is not used in the future
                    replaceIndex = j;
                    break;
                }
            }

            if (replaceIndex == -1) {
                replaceIndex = 0; // Default to the first frame if no replacement is found
            }

            frames[replaceIndex] = page;
            pageFaults++;
        }

        // Print the current state of frames
        printf("%d\t\t", page);
        for (int j = 0; j < capacity; j++) {
            if (frames[j] != -1) {
                printf("%d ", frames[j]);
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
}

int main() {
    int n, capacity;

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    int pages[n];
    printf("Enter the page reference string:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &capacity);

    optimalPageReplacement(pages, n, capacity);

    return 0;
}