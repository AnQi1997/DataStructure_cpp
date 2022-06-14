#include <stdio.h>
#include <stdlib.h>

void search_x(int A[], int x, int n) {
    int low = 0, high = n - 1;
    int mid;
    //二分查找
    while (low < high) {
        mid = (low + high) / 2;
        if (A[mid] == x)
            break;
        else if (A[mid] < x)  // x在mid左边
            low = mid + 1;
        else
            high = mid - 1;
    }

    // low <= high
    if (A[mid] == x && mid != n - 1) {
        //与后面的交换
        int temp = A[mid];
        A[mid] = A[mid + 1];
        A[mid + 1] = temp;
    }

    if (low > high) {
        //插入表中
        int i;
        for (i = n - 1; i > high; i--) {
            A[i + 1] = A[i];
        }
        A[i + 1] = x;
    }
}

int main() {
    int A[] = {1, 2, 3, 4, 5};
    int n = sizeof(A) / sizeof(A[0]);
    for (int i = 0; i < n; i++) {
        printf("%4d", A[i]);
    }
    printf("\n");

    search_x(A, 2, n);

    for (int i = 0; i < n; i++) {
        printf("%4d", A[i]);
    }
}
