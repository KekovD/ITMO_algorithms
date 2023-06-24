#include <stdio.h>

int main() {
    int n, number, key, j, count;

    scanf("%d", &n);

    int array[n];

    for(int i = 0; i  < n; i++) {
        scanf("%d", &number);
        array[i] = number;
    }

    for (int i = 1; i < n; i ++) {
        key = array[i];
        count = 0;

        for(j = i - 1; j >= 0 && array[j] > key; j--) {
            array[j + 1] = array[j];
            count = 1;
        }

        array[j + 1] = key;

        if (count) {

            for(int k = 0; k < n; k++) {
                printf("%d ", array[k]);

                if (k == n - 1) {
                    printf("\n");
                }
            }
        }
    }

    return 0;
}
