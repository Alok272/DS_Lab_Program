#include <stdio.h>

void heapify(int a[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    int temp;

    if (left <= n && a[left] > a[largest])
        largest = left;

    if (right <= n && a[right] > a[largest])
        largest = right;

    if (largest != i)
    {
        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n)
{
    int i, temp;

    // Build Max Heap
    for (i = n / 2; i >= 1; i--)
        heapify(a, n, i);

    // Delete root one by one
    for (i = n; i >= 2; i--)
    {
        // Swap root with last element
        temp = a[1];
        a[1] = a[i];
        a[i] = temp;

        // Restore Max Heap
        heapify(a, i - 1, 1);
    }
}

int main()
{
    int a[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    heapSort(a, n);

    printf("Sorted array: ");
    for (i = 1; i <= n; i++)
    printf("%d ", a[i]);
    printf("\n Alok Pandey 2501920100076");
    return 0;
}