#include <stdio.h>

int main() {
    int n, number, last, mass[35];
    scanf("%d", &n);
    if(n >= 1 && n <= 35){
        for(int i = 0; i < n; i++){
            scanf("%d", &number);
            mass[i] = number;
            if(i == n - 1) last = mass[i];
        }
        for(int i = n; i > 0; i--)
            mass[i] = mass[i - 1];
        mass[0] = last;
        for(int i = 0; i < n; i++)
            printf("%d ", mass[i]);
    }
    return 0;
}
