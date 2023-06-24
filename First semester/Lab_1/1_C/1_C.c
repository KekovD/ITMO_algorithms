#include <stdio.h>
#include <limits.h>

int main() {
    int n, pos, mass[1000];
    long int droid_num, min_1, min_2;
    min_1 = INT_MAX;
    min_2 = INT_MAX;
    scanf("%d", &n);
    if (n >= 2 && n <= 1000) {
        for (int i = 0; i < n; i++) {
            scanf("%ld", &droid_num);
            mass[i] = droid_num;
            if (mass[i] < INT_MAX) {
                if (mass[i] < min_1) {
                    min_1 = droid_num;
                    pos = i;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (mass[i] < min_2 && i != pos) min_2 = mass[i];
        }
        if(min_2 == INT_MAX) min_2 = min_1;
        printf("%ld %ld", min_1, min_2);
    }
    return 0;
}

