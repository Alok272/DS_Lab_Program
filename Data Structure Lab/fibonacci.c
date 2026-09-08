#include <stdio.h>

int fibo(int x) {
    if (x<=1) {
        return x;
    } else {
        return fibo(x-1) + fibo(x-2);
    }
}

int main() {
    int i, n;
    printf("Enter the number: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("%d ", fibo(i));
    }

    return 0;
}