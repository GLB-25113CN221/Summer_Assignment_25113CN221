#include <stdio.h>

int main()
{
    int m, n, p; // A = m×n, B = n×p, C = m×p

    printf("Enter rows and columns of first matrix (m n): ");
    scanf("%d%d", &m, &n);

    printf("Enter columns of second matrix (p): ");
    scanf("%d", &p);

    int A[m][n], B[n][p], C[m][p];

    printf("Enter elements of first matrix (%d*%d):\n", m, n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements of second matrix (%d*%d):\n", n, p);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < p; j++)
            scanf("%d", &B[i][j]);

    // Multiplication
    for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }

    printf("Product matrix (%d*%d):\n", m, p);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    return 0;
}