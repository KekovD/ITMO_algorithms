#include <stdio.h>

int main() {
    int n, m, j, sum, weight, key;
    int it1 = 0, it2 = 0, index = 0;

    scanf("%d %d", &n, &m);

    int raft[n * m];

    for(int i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &raft[index]);
            index++;
        }
    }

    scanf("%d", &sum);

    int mesklin[sum];

    for(int i = 0; i < sum; i++) {
        scanf("%d", &weight);
        mesklin[i] = weight;
    }

    for(int i = 1; i < n * m; i++) {
        key = raft[i];
        for(j = i - 1; j >= 0 && raft[j] > key; j--)
            raft[j + 1] = raft[j];
        raft[j + 1] = key;
    }

    for(int i = 1; i < sum; i++) {
        key = mesklin[i];
        for(j = i - 1; j >= 0 && mesklin[j] > key; j--)
            mesklin[j + 1] = mesklin[j];
        mesklin[j + 1] = key;
    }

    while (it1 < m * n && it2 < sum) {
        if (raft[it1] >= mesklin[it2]) {
            it2++;
            it1++;
        } else {
            it1++;
        }
    }

    printf("%d", it2);

    return 0;
}
