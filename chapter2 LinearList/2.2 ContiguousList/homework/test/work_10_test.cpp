#include <stdio.h>
#include <stdlib.h>

void Reverse(int R[], int from, int to) {
    for (int i = 0; i < (to - from + 1) / 2; i++) {
        int temp = R[from + i];
        R[from + i] = R[to - i];
        R[to - i] = temp;
    }
}

void Converse(int R[], int n, int p) {
    Reverse(R, 0, p - 1);  // 0  2
    Reverse(R, p, n - 1);  // 3  4
    Reverse(R, 0, n - 1);  // 0  4
}

int main() {
    int R[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        printf("%4d", R[i]);
    }
    printf("\n");
    // 1, 2, 3, 4, 5
    // n = 5 p = 3 Ñ­»·×óÒÆ3Î»
    // 3, 2, 1, 5, 4
    // 4, 5, 1, 2, 3
    Converse(R, 5, 3);
    for (int i = 0; i < 5; i++) {
        printf("%4d", R[i]);
    }
}
