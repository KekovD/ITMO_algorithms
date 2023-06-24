#include <stdio.h>

int main() {
    int sum = 0, number, n, mass[100];
    scanf("%d", &n);
    if(n >= 1 && n <= 100) {
        for(int i = 0; i < n; i++) {
            scanf("%d", &number);
            mass[i] = number;
        }
        for(int i = 1; i < n - 1; i++){
            if (mass[i] > mass[i - 1] && mass[i] > mass[i + 1]) { sum++; }
        }
        printf("%d", sum);
    }
    return 0;
}
