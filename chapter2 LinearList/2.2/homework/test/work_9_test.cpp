#include <stdio.h>
#include <stdlib.h>
// TODO
void search_X(int A[], int x, int n) {
    int left = 0;
    int right = n - 1;
    int mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (A[mid] == x)
            break;
        else if (A[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    //�ҵ�������Ԫ�ؽ���
    if (A[mid] == x && mid != n - 1) {
        int temp = A[mid];
        A[mid] = A[mid + 1];
        A[mid + 1] = temp;
    }

    // left > rightʱ�Ҳ�������ʱ left = right + 1; right��left�����
    // x > A[right]
    //���������Ԫ�ص�������
    if (left > right) {
        int i;
        for (i = n - 1; i > right; i--) {
            //Ԫ�غ���
            A[i + 1] = A[i];
        }
        A[i] = x;
    }
}

int main() {
    int A[] = {1, 2, 3, 4, 5, 10, 12};
    int n = sizeof(A) / sizeof(A[0]);
    for (int i = 0; i < 7; i++) {
        printf("%4d", A[i]);
    }
    printf("\n");

    search_X(A, 13, n);  // TODO

    for (int i = 0; i < 7; i++) {
        printf("%4d", A[i]);
    }
}
