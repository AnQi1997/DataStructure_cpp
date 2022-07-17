#include <stdio.h>
#include <stdlib.h>

//逆转函数
void Reverse(int R[], int from, int to) {
    for (int i = 0; i < (to - from + 1) / 2; i++) {
        int temp = R[from + i];
        R[from + i] = R[to - i];
        R[to - i] = temp;
    }
}
//反转函数
void Converse(int R[], int n, int p) {
    Reverse(R, 0, p - 1);
    Reverse(R, p, n - 1);
    Reverse(R, 0, n - 1);
}

int main() {
    int R[] = {1, 2, 3, 4, 5};
    int n = sizeof(R) / sizeof(R[0]);
    for (int i = 0; i < n; i++) {
        printf("%4d", R[i]);
    }
    printf("\n");
    Converse(R, n, 2);
    for (int i = 0; i < n; i++) {
        printf("%4d", R[i]);
    }
}
