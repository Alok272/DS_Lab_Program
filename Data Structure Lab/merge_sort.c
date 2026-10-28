#include <stdio.h>

int main() {
    int a[100], b[100], n, i, size, left;
    int mid, right, x, y, k;

    printf("Enter n: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (size = 1; size < n; size *= 2) {
        for (left = 0; left < n - size; left += 2 * size) {
            mid = left + size - 1;
            right = left + 2 * size - 1;

            if (right >= n)
                right = n - 1;

            x = left;
            y = mid + 1;
            k = left;

            while (x <= mid && y <= right) {
                if (a[x] <= a[y])
                    b[k++] = a[x++];
                else
                    b[k++] = a[y++];
            }

            while (x <= mid)
                b[k++] = a[x++];

            while (y <= right)
                b[k++] = a[y++];

            for (i = left; i <= right; i++)
                a[i] = b[i];
        }
    }

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
    printf("%d ", a[i]);
    printf("\nAlok Pandey 2501920100076");

    return 0;
}