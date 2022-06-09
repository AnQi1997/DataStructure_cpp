#include<stdio.h>
#include<stdlib.h>
// TODO
//  8.已知在一维数组A[m+n]中依次存放两个线性表(a1, a2, a3, ... , am)和(b1, b2, b3, ... , bn).
//   试编写一个函数,将数组中两个顺序表的位置互换,
//即将(b1, b2, b3, ... , bn)放在(a1, a2, a3, ... , am)前面
typedef int DataType;
void Reverse(DataType A[], int left, int right, int arraySize) {
    //判断范围合法
    if (left >= right || right >= arraySize)
        return;
    int mid = (left + right) / 2;
    for (int i = 0; i <= mid - left; i++) {
        DataType temp = A[left + i];
        A[left + i] = A[right - i];
        A[right - i] = temp;
    }
}

void Exchange(DataType A[], int m, int n, int arraySize) {
    //数组A[m+n]中,
    // 从0到m-1存放顺序表(a1, a2, a3, ... , am),
    //从m到m+n-1存放顺序表(b1, b2, b3, ... , bn)
    Reverse(A, 0, m + n - 1, arraySize);  //逆置整个表前n个是bn,...,b2,b1 后面是:am,...,a2,a1
    Reverse(A, 0, n - 1, arraySize);      //逆转 逆序的bn,...,b2,b1
    Reverse(A, n, m + n - 1, arraySize);  //逆转a m,...,a2,a1
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