#include <stdio.h>
#include <malloc.h>

void merge(int *mass, int left, int mid, int right){
    int it1 = 0, it2 = 0;

    int *tmp = (int*) malloc((right - left) * sizeof(int));

    while ((left + it1 < mid) && (mid + it2 < right)) {
        if (mass[left + it1] < mass[mid + it2]) {
            tmp[it1 + it2] = mass[left + it1];
            it1++;
        } else {
            tmp[it1 + it2] = mass[mid + it2];
            it2++;
        }
    }

    while (left + it1 < mid) {
        tmp[it1 + it2] = mass[left + it1];
        it1++;
    }

    while (mid + it2 < right) {
        tmp[it1 + it2] = mass[mid + it2];
        it2++;
    }

    for(int i = 0; i < it1 + it2; i++) {
        mass[left + i] = tmp[i];
    }

    free(tmp);
}

void mergeSortRecursive(int *mass, int left, int right) {
    if (left + 1 >= right) return;

    int mid = (left + right) / 2;

    mergeSortRecursive(mass, left, mid);
    mergeSortRecursive(mass, mid, right);
    merge(mass, left, mid, right);
}

int main() {
    int n, number;

    scanf("%d", &n);

    int *array = (int*) malloc(n * sizeof(int));

    for(int i = 0; i < n; i++) {
        scanf("%d", &number);
        array[i] = number;
    }

    mergeSortRecursive(array, 0, n);

    for(int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }

    free(array);

    return 0;
}
