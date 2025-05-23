#include <stdio.h>

void lruPageReplacement(int pages[], int n, int capacity) {
    int frames[capacity];
    int time[capacity];
    int pageFaults = 0, currentTime = 0;

    // Initialize frames and time arrays
    for (int i = 0; i < capacity; i++) {
        frames[i] = -1; // Empty frame
        time[i] = 0;    // No usage time
    }

    printf("Page Reference\tFrames\n");

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int found = 0;

        // Check if the page is already in the frame
        for (int j = 0; j < capacity; j++) {
            if (frames[j] == page) {
                found = 1;
                time[j] = currentTime++; // Update the usage time
                break;
            }
        }

        if (!found) {
            // Page fault occurs
            int lruIndex = 0;

            // Find the least recently used page
            for (int j = 1; j < capacity; j++) {
                if (time[j] < time[lruIndex]) {
                    lruIndex = j;
                }
            }

            // Replace the least recently used page
            frames[lruIndex] = page;
            time[lruIndex] = currentTime++;
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

    lruPageReplacement(pages, n, capacity);

    return 0;
}