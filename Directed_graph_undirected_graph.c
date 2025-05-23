#include <stdio.h>
int main()
{
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[n][n];
    int i, j, flag = 0;

    // Input adjacency matrix
    printf("Enter the adjacency matrix (0 or 1 values):\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("adj[%d][%d]: ", i, j);
            scanf("%d", &graph[i][j]);
        }
    }
    // Checking for symmetry
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (graph[i][j] != graph[j][i])
            {
                flag = 1; // Non-symmetric found
                break;
            }
        }
        if (flag)
        {
            break;
        }
    }

    // Output result
    if (flag == 0)
        printf("\nThe graph is Undirected.\n");
    else
        printf("\nThe graph is Directed.\n");

    return 0;
}