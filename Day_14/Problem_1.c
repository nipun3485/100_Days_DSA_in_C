//program to check identity matrix//
#include <stdio.h>

int main()
{
    int n;
    printf("Enter size of matrix: ");
    scanf("%d", &n);

    int matrix[n][n];
    int isIdentity = 1;   // assume it is identity

    printf("Enter matrix elements:\n");

    // Taking input
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Checking identity condition
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j)
            {
                if(matrix[i][j] != 1)
                {
                    isIdentity = 0;
                }
            }
            else
            {
                if(matrix[i][j] != 0)
                {
                    isIdentity = 0;
                }
            }
        }
    }

    if(isIdentity == 1)
        printf("Identity Matrix");
    else
        printf("Not an Identity Matrix");

    return 0;
}
