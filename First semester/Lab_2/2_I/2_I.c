#include <stdio.h>

void  swap(int *a, int *b) {
    int key = *a;
    *a = *b;
    *b = key;
}

int partition (int *mass, int low, int hi) {
    int pivot = mass[(low + hi) / 2];

    while (low <= hi) {
        while (mass[low] < pivot) {
            low++;
        }
        while (mass[hi] > pivot) {
            hi--;
        }
        if (low >= hi) break;
        swap(&mass[low++], &mass[hi--]);
    }
    return hi;
}

void quicksort (int *mass, int low, int hi) {
    int mid;

    if (low < hi) {
        mid = partition(mass, low, hi);
        quicksort(mass, low, mid);
        quicksort(mass, mid + 1, hi);
    }
}

int main() {
    int size;

    scanf("%d", &size);

    int mass[size];

    for (int i = 0; i < size; i++) {
        scanf("%d", &mass[i]);
    }

    quicksort(mass, 0, size - 1);

    for (int i = 0; i < size; i++) {
        printf("%d ", mass[i]);
    }

    return 0;
}
