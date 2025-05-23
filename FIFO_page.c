#include <stdio.h>

void fifoPageReplacement(int pages[], int n, int capacity) {
    int frames[capacity];
    int front = 0, count = 0, pageFaults = 0;

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
            frames[front] = page;
            front = (front + 1) % capacity; // Move to the next frame in FIFO order
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

    fifoPageReplacement(pages, n, capacity);

    return 0;
}