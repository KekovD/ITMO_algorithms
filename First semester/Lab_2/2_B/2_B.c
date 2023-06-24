#include <stdio.h>

int main() {
    int mass[1000], n, number, key, j;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &number);
        mass[i] = number;
    }

    for(int i = 1; i < n; i++) {
        key = mass[i];
        j = i - 1;
        while (j >= 0 && mass[j] > key) {
            mass[j + 1] = mass[j];
            j--;
        }
        mass[j + 1] = key;
    }

    for (int i = 0; i < n; i++)
        printf("%d ", mass[i]);

    return 0;
}
