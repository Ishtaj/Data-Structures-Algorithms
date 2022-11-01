// Program to represent Sparse matrix using array

#include <stdio.h>

int main()
{
    int m,n;
    
    printf("Enter the number of rows:\n");
    scanf("%d", &m);
    printf("Enter the number of columns:\n");
    scanf("%d", &n);

    int matrix[m][n];

    printf("Enter the elements of the sparse matrix:\n");
    {
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                scanf("%d", &matrix[i][j]);
            }
        }
    }

    // entered sparse matrix 

    printf("\n\nThe entered sparse matrix is:\n");

    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            printf("%d\t", matrix[i][j]);
        }

        printf("\n");
    }

    // calculating the number of non-zero entries

    int size = 0;

    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (matrix[i][j] != 0)
            {
                size++;
            }
        }
    }

    // making sparse matrix

    int sparseMatrix[size+1][3];

    int k=1;
    sparseMatrix[0][0] = m; // number of rows
    sparseMatrix[0][1] = n; // number of columns
    sparseMatrix[0][2] = size;  // number of non-zero entries

    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (matrix[i][j] != 0)
            {
                sparseMatrix[k][0] = i;
                sparseMatrix[k][1] = j;
                sparseMatrix[k][2] = matrix[i][j];
                k++;
            }
        }
    }
    
    printf("\n\nSparse Matrix Triplet representation:\n\n");
    printf("Row\tColumn\tValue\n---\t------\t-----\n\n");

    for (int i=0; i<size+1; i++)
    {
        for (int j=0; j<3; j++)
        {
            printf("%d\t", sparseMatrix[i][j]);
        }

        printf("\n");
    } 

    return 0;
}
