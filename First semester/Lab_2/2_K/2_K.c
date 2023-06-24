#include <stdio.h>
#include <malloc.h>

int k;

void  swap(int *a, int *b) {
    int key = *a;
    *a = *b;
    *b = key;
}

int selection(int *mass, int low, int hi) {
    int i = low, j = hi;
    int pivot = mass[(low + hi) / 2];

    do {
        while (mass[i] < pivot) {
            i++;
        }
        while (mass[j] > pivot) {
            j--;
        }
        if (i <= j)
            swap(&mass[i++], &mass[j--]);
    } while (i <= j);

    if (low <= k && k <= j) {
        selection(mass, low, j);
    } else if (i <= k && k <= hi){
        selection(mass, i, hi);
    }

    return mass[k];
}

int main() {
    int n, result;
    int a, b, c;

    scanf("%d %d", &n, &k);
    k--;

    int *array = (int*) malloc (n * sizeof(int));

    scanf("%d %d %d %d %d", &a, &b, &c, &array[0], &array[1]);

    for(int i = 2; i < n; i++) {
        array[i] = a * array[i - 2] + b * array[i - 1] + c;
    }

    result = selection(array, 0, n - 1);

    printf("%d", result);

    return 0;
}
