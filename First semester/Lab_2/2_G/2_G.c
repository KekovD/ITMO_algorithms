#include <stdio.h>
#include <malloc.h>

void merge (int *mass, int left, int mid, int right) {
    int it1 = 0, it2 = 0;

    int *tmp = (int*) malloc ((right - left) * sizeof(int));

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

void mergeRecursive (int *mass, int left, int right) {
    if (left + 1 >= right) return;

    int mid = (left + right) / 2;

    mergeRecursive(mass, left, mid);
    mergeRecursive(mass, mid, right);
    merge(mass, left, mid, right);
}

void multiplicity (int *mass, int size) {
    int it1 = 1, it2 = 1;

    int  *tmp = (int*) malloc(size * sizeof(int));

    tmp[0] = mass[0];

    while ((it1 < size) && (it2 < size)) {
        if (mass[it1] != tmp[it2 - 1]) {
            tmp[it2] = mass[it1];
            it1++;
            it2++;
        } else {
            it1++;
        }
    }

    tmp[it2] = 0;

    for (int i = 0; i < it2; i++) {
        mass[i] = tmp[i];
    }

    free(tmp);
}

void compare (int *mass1, int *mass2, int size1, int size2) {
    int it = 0, count = 1;

    while ((it < size1) && (it < size2)) {
        if (mass1[it] != mass2[it]) {
            count = 0;
        }
        it++;
    }

    if(count) {
        printf("YES");
    } else {
        printf("NO");
    }
}

int main() {
    int n, m, number, it1, it2;
    int *array1, *array2;

    scanf("%d", &n);

    array1 = (int*) malloc (n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &number);
        array1[i] = number;
    }

    mergeRecursive(array1, 0, n);

    scanf("%d", &m);

    array2 = (int*) malloc (m *sizeof(int));

    for (int i = 0; i < m; i++) {
        scanf("%d", &number);
        array2[i] = number;
    }

    mergeRecursive(array2, 0, m);

    multiplicity(array1, n);
    multiplicity(array2, m);

    compare(array1, array2, n, m);

    free(array1);
    free(array2);

    return 0;
}
