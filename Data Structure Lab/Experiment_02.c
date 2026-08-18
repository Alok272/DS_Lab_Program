#include <stdio.h>

int main()
{
    int a[10][10], b[10][10], c[10][10];
    int r1, c1, r2, c2;
    int i, j, k, choice;
    int sum1, sum2, diff;

    printf("Enter rows and columns of first matrix: ");
    scanf("%d%d", &r1, &c1);

    printf("Enter elements of first matrix:\n");
    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c1; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter rows and columns of second matrix: ");
    scanf("%d%d", &r2, &c2);

    printf("Enter elements of second matrix:\n");
    for(i = 0; i < r2; i++)
    {
        for(j = 0; j < c2; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    printf("\n1. Multiplication of two matrices");
    printf("\n2. Difference of sum of two diagonal elements");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            if(c1 != r2)
            {
                printf("Matrix multiplication is not possible.\n");
            }
            else
            {
                for(i = 0; i < r1; i++)
                {
                    for(j = 0; j < c2; j++)
                    {
                        c[i][j] = 0;

                        for(k = 0; k < c1; k++)
                        {
                            c[i][j] = c[i][j] + a[i][k] * b[k][j];
                        }
                    }
                }

                printf("\nResult of Matrix Multiplication:\n");

                for(i = 0; i < r1; i++)
                {
                    for(j = 0; j < c2; j++)
                    {
                        printf("%d\t", c[i][j]);
                    }
                    printf("\n");
                }
            }
            break;

            case 2:
            if(r1 != c1)
            {
                printf("First matrix must be a square matrix.\n");
            }
            else
            {
                sum1 = 0;
                sum2 = 0;

                for(i = 0; i < r1; i++)
                {
                    sum1 = sum1 + a[i][i];
                    sum2 = sum2 + a[i][r1 - i - 1];
                }

                diff = sum1 - sum2;

                if(diff < 0)
                    diff = -diff;

                printf("\nSum of main diagonal = %d", sum1);
                printf("\nSum of secondary diagonal = %d", sum2);
                printf("\nDifference = %d\n", diff);
            }
            break;

        default:
            printf("Invalid choice!\n");
    }
        printf("Alok Pandey 2501920100076");
    return 0;
}