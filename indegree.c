include <stdio.h>

int main() {
    int V;
    printf("Enter the size of square matrix: ");
    scanf("%d", &V);

    int matrix[V][V], transpose[V][V];

    printf("Enter elements of matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Transposing the matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }

    // Printing the transpose
    printf("\nTranspose of the matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}
