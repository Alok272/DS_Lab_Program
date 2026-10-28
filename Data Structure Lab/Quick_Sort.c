#include <stdio.h>

void quickSort(int A[], int N)
{
    int LOWER[100], UPPER[100];
    int TOP = 0;
    int BEG, END, LOC;
    int I, J, TEMP;

    if (N > 1)
    {
        LOWER[TOP] = 0;
        UPPER[TOP] = N - 1;

        while (TOP >= 0)
        {
            BEG = LOWER[TOP];
            END = UPPER[TOP];
            TOP--;

            LOC = BEG;
            I = BEG;
            J = END;

            while (I < J)
            {
                while (A[J] >= A[LOC] && LOC < J)
                    J--;

                if (LOC != J)
                {
                    TEMP = A[LOC];
                    A[LOC] = A[J];
                    A[J] = TEMP;

                    LOC = J;
                }

                while (A[I] <= A[LOC] && I < LOC)
                    I++;

                if (LOC != I)
                {
                    TEMP = A[LOC];
                    A[LOC] = A[I];
                    A[I] = TEMP;

                    LOC = I;
                }
            }
            if (BEG < LOC - 1)
            {
                TOP++;
                LOWER[TOP] = BEG;
                UPPER[TOP] = LOC - 1;
            }

            if (LOC + 1 < END)
            {
                TOP++;
                LOWER[TOP] = LOC + 1;
                UPPER[TOP] = END;
            }
        }
    }
}

int main()
{
    int A[100], N, i;

    printf("Enter number of elements: ");
    scanf("%d", &N);

    printf("Enter elements:\n");
    for (i = 0; i < N; i++)
        scanf("%d", &A[i]);

    quickSort(A, N);

    printf("Sorted array:\n");
    for (i = 0; i < N; i++)
        printf("%d ", A[i]);

    return 0;
}