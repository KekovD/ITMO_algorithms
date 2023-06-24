#include <stdio.h>

void  swap(int *a, int *b) {
    int key = *a;
    *a = *b;
    *b = key;
}

int main() {
    int n;

    scanf("%d", &n);

    int array[n - 1];

    int a[0];

    for (int i = 0; i < n; i++) {
        array[i] = i + 1;
    }

    for (int i = 2; i < n; i++) {
        swap(&array[i / 2], &array[i]);
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}
