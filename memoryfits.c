#include <stdio.h>
#define BlockCount 5
#define ProcessCount 4
void firstFit(int blockSize[], int processSize[])
{
    int allocation[ProcessCount];
    for (int i = 0; i < ProcessCount; i++)
    {
        allocation[i] = -1;
    }
    for (int i = 0; i < ProcessCount; i++)
    {
        for (int j = 0; j < BlockCount; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }
    printf("\nFirst Fit Allocation:\n");
    printf("Process No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < ProcessCount; i++)
    {
        printf("%d\t\t\t", i + 1);
        printf("%d\t\t\t", processSize[i]);
        if (allocation[i] != -1)
            printf("%d", allocation[i] + 1);
        else
            printf("Not Allocated");
        printf("\n");
    }
}
void bestFit(int blockSize[], int processSize[])
{
    int allocation[ProcessCount];
    for (int i = 0; i < ProcessCount; i++)
    {
        allocation[i] = -1;
    }
    for (int i = 0; i < ProcessCount; i++)
    {
        int bestIdx = -1;
        for (int j = 0; j < BlockCount; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx])
                {
                    bestIdx = j;
                }
            }
        }
        if (bestIdx != -1)
        {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }
    printf("\nBest Fit Allocation:\n");
    printf("Process No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < ProcessCount; i++)
    {
        printf("%d\t\t\t", i + 1);
 printf("%d\t\t\t", processSize[i]);
    if (allocation[i] != -1)
 printf("%d", allocation[i] + 1); else
 printf("Not Allocated");
 printf("\n");
    }
}
void worstFit(int blockSize[], int processSize[])
{
    int allocation[ProcessCount];
    for (int i = 0; i < ProcessCount; i++)
    {
        allocation[i] = -1;
    }
    for (int i = 0; i < ProcessCount; i++)
    {
        int worstIdx = -1;
        for (int j = 0; j < BlockCount; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx])
                {
                    worstIdx = j;
                }
            }
        }
        if (worstIdx != -1)
        {
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i];
        }
    }
    printf("\nWorst Fit Allocation:\n");
    printf("Process No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < ProcessCount; i++)
    {
        printf("%d\t\t\t", i + 1);
        printf("%d\t\t\t", processSize[i]);
        if (allocation[i] != -1)
            printf("%d", allocation[i] + 1);
        else
            printf("Not Allocated");
        printf("\n");
    }
}
int main()
{
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    int blockSizeForFirstFit[] = {100, 500, 200, 300, 600};
    int blockSizeForBestFit[] = {100, 500, 200, 300, 600};
    int blockSizeForWorstFit[] = {100, 500, 200, 300, 600};
    bestFit(blockSizeForBestFit, processSize);
    firstFit(blockSizeForFirstFit, processSize);
    worstFit(blockSizeForWorstFit, processSize);
    return 0;
}