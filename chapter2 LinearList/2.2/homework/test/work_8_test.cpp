#include <stdio.h>
#include <stdlib.h>

// 8.
typedef int DataType;

void reverse(DataType A[], int left, int right, int arraySize) {
    if (left >= right || right >= arraySize)
        return;
    for (int i = 0; i < (right - left + 1) / 2; i++) {
        //下标 - 下标 + 1才是个数  ÷2是
        DataType temp = A[left + i];
        A[left + i] = A[right - i];
        A[right - i] = temp;
    }
}

void converse(DataType A[], int m, int n, int arraySize) {
    reverse(A, 0, m + n - 1, arraySize);
    reverse(A, 0, m - 1, arraySize);
    reverse(A, m, m + n - 1, arraySize);
}

int main() {
    DataType A[] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < 6; i++) {
        printf("%4d", A[i]);
    }
    printf("\n");
    converse(A, 2, 4, 6);
    for (int i = 0; i < 6; i++) {
        printf("%4d", A[i]);
    }
}
