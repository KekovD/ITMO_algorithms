#include <stdio.h>
#include <malloc.h>

void merge(int *mass_first, int *mass_second, int left, int mid, int right) {
    int it1 = 0, it2 = 0;

    int *tmp1 = (int*) malloc((right - left) * sizeof(int));
    int *tmp2 = (int*) malloc((right - left) * sizeof(int));

    while ((left + it1 < mid) && (mid + it2 < right)) {
        if (mass_first[left + it1] < mass_first[mid + it2]) {
            tmp1[it1 + it2] = mass_first[left + it1];
            tmp2[it1 + it2] = mass_second[left + it1];
            it1++;
        } else {
            tmp1[it1 + it2] = mass_first[mid + it2];
            tmp2[it1 + it2] = mass_second[mid + it2];
            it2++;
        }
    }

    while (left + it1 < mid) {
        tmp1[it1 + it2] = mass_first[left + it1];
        tmp2[it1 + it2] = mass_second[left + it1];
        it1++;
    }

    while (mid + it2 < right) {
        tmp1[it1 + it2] = mass_first[mid + it2];
        tmp2[it1 + it2] = mass_second[mid + it2];
        it2++;
    }

    for(int i = 0; i < it1 + it2; i++) {
        mass_first[left + i] = tmp1[i];
        mass_second[left + i] = tmp2[i];
    }

    free(tmp1);
    free(tmp2);
}

void mergeRecursive(int *mass_first, int *mass_second, int left, int right) {
    if(left + 1 >= right) return;

    int mid = (left + right) / 2;

    mergeRecursive(mass_first, mass_second, left, mid);
    mergeRecursive(mass_first, mass_second, mid, right);
    merge(mass_first, mass_second, left, mid, right);
}

void paintBoards(int *mass_first, int *mass_second, int size) {
    int last = mass_second[0];
    int board = mass_second[0] - mass_first[0] + 1;

    for (int i = 0; i < size; i++) {
        if (mass_first[i] > last) {
            board += mass_second[i] - mass_first[i] + 1;
            last= mass_second[i];
        }
        else if (mass_second[i] > last) {
            board += mass_second[i] - last;
            last = mass_second[i];
        }
    }

    printf("%d", board);
}

int main() {
    int friends;

    scanf("%d", &friends);

    int first[friends];
    int second[friends];

    for (int i = 0; i < friends; i++) {
        for (int j = 0; j < 2; j++) {
            if (j == 0) {
                scanf("%d", &first[i]);
            } else {
                scanf("%d", &second[i]);
            }
        }
    }

    mergeRecursive(first, second, 0, friends);

    paintBoards(first, second, friends);

    return 0;
}
