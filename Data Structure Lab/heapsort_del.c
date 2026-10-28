#include <stdio.h>

int deleteMin(int heap[], int *n)
{
    int item, last;
    int ptr = 1;
    int left, right, child;

    item = heap[1];    
    last = heap[*n];     
    *n = *n - 1;

    while (2 * ptr <= *n)
    {
        left = 2 * ptr;
        right = left + 1;

        if (right <= *n && heap[right] < heap[left])
            child = right;
        else
            child = left;

        if (last <= heap[child])
            break;

        heap[ptr] = heap[child];
        ptr = child;
    }

    heap[ptr] = last;

    return item;
}

int main()
{
    int heap[100] = {0, 10, 20, 40, 30, 50, 60};
    int n = 6;

    printf("Before deletion: ");
    for (int i = 1; i <= n; i++)
        printf("%d ", heap[i]);

    int deleted = deleteMin(heap, &n);

    printf("\nDeleted element = %d", deleted);

    printf("\nAfter deletion: ");
    for (int i = 1; i <= n; i++)
        printf("%d ", heap[i]);

    return 0;
}