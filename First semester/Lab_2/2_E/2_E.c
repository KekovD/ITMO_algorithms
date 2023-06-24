#include <stdio.h>

int main() {
    int n, id, score, k, key[2];

    scanf("%d", &n);

    int array[n][2];

    for(int i = 0; i < n; i++) {
        scanf("%d %d", &id, &score);
        array[i][0] = id;
        array[i][1] = score;
    }

    for (int i = 0; i < n; i++) {
        key[0] = array[i][0];
        key[1] = array[i][1];

        for (k = i - 1; k >= 0 && array[k][0] > key[0]; k--) {
            array[k + 1][1] = array[k][1];
            array[k + 1][0] = array[k][0];
        }
        array[k + 1][1] = key[1];
        array[k + 1][0] = key[0];
    }

    for(int i = 1; i < n; i++) {
        key[0] = array[i][0];
        key[1] = array[i][1];

        for (k = i - 1; k >= 0 && array[k][1] < key[1]; k--) {
            array[k + 1][1] = array[k][1];
            array[k + 1][0] = array[k][0];
        }
        array[k + 1][1] = key[1];
        array[k + 1][0] = key[0];
    }

    for(int i = 0; i < n; i++) {
        printf("%d %d\n", array[i][0], array[i][1]);
    }

    return 0;
}
