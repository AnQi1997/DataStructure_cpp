#include <stdio.h>
#include <stdlib.h>
//习题1.9
//线性表(a1, a2, ... , an)中的元素递增有序且按顺序存储于计算机内.
//要求设计一个算法,完成用最少时间在表中查找数值为x的元素,
//若找到,则将其与后继元素位置相交换
//若找不到,则将其插入表中并使表中元素增递增有序

//算法思想:顺序存储的线性表递增有序,可顺序查找,也可折半查找
//要求最短时间查找表中数值为x的元素,应该使用折半查找法

typedef int ElemType;
/**
 * @brief
 *
 * @param A 数组
 * @param x 要查找的值
 * @param n 数组长度
 */
void SearchExchangeInsert(ElemType A[], ElemType x, int n) {
    // int n = sizeof(A) / sizeof(A[0]);  //数组长度
    int low = 0, high = n - 1, mid;

    //折半查找
    while (low < high) {
        mid = (low + high) / 2;
        if (A[mid] == x)
            break;
        else if (A[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }

    //找到值为x的元素,将其与后继元素交换
    if (A[mid] == x && mid != n - 1) {
        ElemType temp = A[mid];
        A[mid] = A[mid + 1];
        A[mid + 1] = temp;
    }
    //没找到值为x的元素,插入表中,使表递增有序
    //下标high之后全部大于x,查找的值大于high（也就是mid）
    if (low > high) {
        int i;  //下标
        // i取值范围：n-1 ~ high+1
        for (i = n - 1; i > high; i--)
            //元素后移
            A[i + 1] = A[i];
        //最后 i = high
        //插入待插入位置
        A[i + 1] = x;
    }
}

int main() {
    ElemType A[] = {1, 2, 3, 4, 5};
    int n = sizeof(A) / sizeof(A[0]);  //数组长度

    SearchExchangeInsert(A, 6, n);
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++) {
        printf("%4d", A[i]);
    }
}
