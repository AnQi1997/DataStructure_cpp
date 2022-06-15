#include <stdio.h>
#include <stdlib.h>

//ǰp�� ��n-p��

/**
 * @brief
 *
 * @param R ������
 * @param left
 * @param rigth
 * @param n ��n��Ԫ��
 */
void reverse(int R[], int left, int right) {
    for (int i = 0; i < (right - left + 1) / 2; i++) {
        int temp = R[left + i];
        R[left + i] = R[right - i];
        R[right - i] = temp;
    }
}

/**
 * @brief
 *
 * @param R
 * @param p �ֽ���
 * @param n
 */
void converse(int R[], int p, int n) {
    reverse(R, 0, p - 1);
    reverse(R, p, n - 1);
    reverse(R, 0, n - 1);
}

int main() {
    int R[] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < 6; i++) {
        printf("%4d", R[i]);
    }
    printf("\n");

    converse(R, 2, 6);

    for (int i = 0; i < 6; i++) {
        printf("%4d", R[i]);
    }
}
