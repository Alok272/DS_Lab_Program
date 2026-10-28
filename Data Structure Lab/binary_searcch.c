#include <stdio.h>

int main() {
    int a[100], n, key, low, high, mid, i;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter elements in sorted order: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter key: ");
    scanf("%d", &key);

    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low + high) / 2;

        if (a[mid] == key) {
            printf("Found at position %d\n", mid + 1);
            printf("Alok Pandey 2501920100076");
            return 0;
        }
        else if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    printf("Not Found\n");
    printf("Alok Pandey 2501920100076");

    return 0;
}