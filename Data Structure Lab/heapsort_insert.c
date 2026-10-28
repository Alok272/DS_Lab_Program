#include <stdio.h>

void insert(int heap[], int *n, int item)
{
    int ptr, par;

    *n = *n + 1;
    ptr = *n;

    while (ptr > 1)
    {
        par = ptr / 2;

        if (item >= heap[par])
            break;

        heap[ptr] = heap[par];
        ptr = par;
    }

    heap[ptr] = item;
}

int main()
{
    int heap[100];
    int n = 0;
    int item;

    printf("Enter elements: ");

    while (1)
    {
        scanf("%d", &item);

        if (item == -1)
            break;

        insert(heap, &n, item);
    }

    printf("Min Heap: ");
    for (int i = 1; i <= n; i++)
        printf("%d ", heap[i]);

    return 0;
}