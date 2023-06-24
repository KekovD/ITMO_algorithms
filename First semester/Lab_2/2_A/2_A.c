#include <stdio.h>

int main() {
    int n, number, insert, index, mass[1000];

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &number);
        mass[i] = number;
    }

    scanf("%d %d",&insert, &index);

    for(int i = n + 1; i > index - 1; i--) {
        mass[i] = mass[i - 1];
    }

    mass[index - 1] = insert;

    for(int i = 0; i < n + 1; i++) {
        printf("%d ", mass[i]);
    }

    return 0;
}
