#include <stdio.h>
#include <stdlib.h>

int main() {
    int number, diff_1, diff_2 = 2000, near = 0, x_num, n, mass[1000];
    
    scanf("%d", &n);
    
    if (n >= 0 && n <= 1000){
        for (int i = 0; i < n; i++){
            scanf("%d", &number);
            if(abs(number) <= 1000) {
                mass[i] = number;
            }
        }
        
        scanf("%d", &x_num);
        
        if (abs(x_num) <= 1000){
            for(int i = 0; i < n; i++) {
                diff_1 = abs(mass[i] - x_num);
                if(diff_1 < diff_2) {
                    diff_2 = diff_1;
                    near = mass[i];
                }
                if (abs(mass[i]) == abs(x_num)){
                    near = mass[i];
                }
            }
        }
        printf("%d", near);
    }
    
    return  0;
}
