#include <stdio.h>

int main() {
    int a[100], n, key, i;

    printf("Enter n: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter key: ");
    scanf("%d", &key);

    for (i = 0; i < n; i++) {
        if (a[i] == key) {
            printf("Found at position %d\n", i + 1);
            printf("Alok Pandey 2501920100076");
            return 0;
        }
    }

    printf("Not Found\n");
    printf("Alok Pandey 2501920100076");

    return 0;
}