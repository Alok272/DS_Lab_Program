#include <stdio.h>

void quickSort(int a[], int n)
{
    int lower[n], upper[n];
    int top = -1;

    if (n > 1)
    {
        top++;
        lower[top] = 0;
        upper[top] = n - 1;
    }

    while (top != -1)
    {
        // Pop sublist
        int beg = lower[top];
        int end = upper[top];
        top--;

        int left = beg;
        int right = end;
        int pivot = a[beg];

        // Partition
        while (left < right)
        {
            while (a[right] >= pivot && left < right)
                right--;

            if (left < right)
            {
                a[left] = a[right];
                left++;
            }

            while (a[left] <= pivot && left < right)
                left++;

            if (left < right)
            {
                a[right] = a[left];
                right--;
            }
        }

        a[left] = pivot;
        int loc = left;

        if (beg < loc - 1)
        {
            top++;
            lower[top] = beg;
            upper[top] = loc - 1;
        }

        if (loc + 1 < end)
        {
            top++;
            lower[top] = loc + 1;
            upper[top] = end;
        }
    }
}

int main()
{
    int a[] = {50, 30, 70, 20, 40, 60, 10};
    int n = sizeof(a) / sizeof(a[0]);

    quickSort(a, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    printf("%d ", a[i]);
    printf("\nAlok Pandey 2501920100076");
    return 0;
}