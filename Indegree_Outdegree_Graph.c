#include <stdio.h>
void degree(int graph[][10], int n, int indegree, int outdegree)
{
    printf("\nVertex\tIndegree\tOutdegree\n");
    for (int i = 0; i < n; i++)
    {

        // Outdegree
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == 1)
            {
                outdegree++;
            }
        }

        // Indegree
        for (int j = 0; j < n; j++)
        {
            if (graph[j][i] == 1)
            {
                indegree++;
            }
        }

        printf("%d\t%d\t%d\n", i, indegree, outdegree);
    }
}
int main()
{
    int n;
    int indegree = 0, outdegree = 0;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[n][n];
    int i, j;

    printf("Enter the adjacency matrix (0 or 1 values):\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("adj[%d][%d]: ", i, j);
            scanf("%d", &graph[i][j]);
        }
    }
    degree(graph, n, 0, 0); // Call the degree function
    return 0;
}