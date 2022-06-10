#include <stdio.h>
#include <stdlib.h>
//习题1.8 已知在一维数组A[m+n]中依次存放两个线性表(a1, a2, a3, ... , am)和(b1, b2, b3, ... , bn).
//试编写一个函数,将数组中两个顺序表的位置互换,
//即将(b1, b2, b3, ... , bn)放在(a1, a2, a3, ... , am)前面

typedef int DataType;

void Reverse(DataType A[], int left, int right, int arraySize) {
    //判断范围合法
    if (left >= right || right >= arraySize)
        return;
    //中间位置
    int mid = (left + right) / 2;

    // 1 3 5
    // 0 1 2
    // left = 0 right = 2
    // mid = (0 + 2) / 2 = 1
    // mid - left = 1 - 0 = 1

    // i = 0:
    // temp = A[0 + 0]
    // A[0 + 0] = A[2 - 0]
    // A[2 - 0] = temp
    // A[0] 与 A[2]互换

    // i = 1;
    // temp = A[0 + 1];
    // A[0 + 1] = A[2 - 1];
    // A[2 - 1] = A[0 + 1];
    // A[1]不动
    // ---------------------------------------------------------
    // 下标:3 4 5 6 7
    // 元素:2 4 6 8 10

    // left = 3
    // right = 7
    // mid = (3 + 7) / 2 = 5;
    // mid - left = 5 - 3 = 2;

    // i = 0;
    // temp = A[3 + 0]
    // A[3 + 0] = A[7 - 0]
    // A[7 - 0] = A[3 - 0]

    for (int i = 0; i <= mid - left; i++) {
        DataType temp = A[left + i];
        A[left + i] = A[right - i];
        A[right - i] = temp;
    }
}

/**
 * @brief
 *
 * @param A 数组名
 * @param m 前面有m个
 * @param n 后面有n个
 * @param arraySize
 */
void Exchange(DataType A[], int m, int n, int arraySize) {
    //数组A[m+n]中,
    // 从0到m-1存放顺序表(a1, a2, a3, ... , am),
    //从m到m+n-1存放顺序表(b1, b2, b3, ... , bn)
    Reverse(A, 0, m + n - 1, arraySize);  //逆置整个表：前n个是bn,...,b2,b1 后面是:am,...,a2,a1
    Reverse(A, 0, n - 1, arraySize);      //逆转 bn,...,b2,b1, 变成b1, b2, ... , bn
    Reverse(A, n, m + n - 1, arraySize);  //逆转 am,...,a2,a1, 变成a1, a2, ... , am
}

int main() {
    int m = 3;
    int n = 5;
    DataType A[] = {1, 3, 5, 2, 4, 6, 8, 10};
    Exchange(A, 3, 5, 8);
    for (int i = 0; i < 8; i++) {
        printf("%4d", A[i]);
    }
}