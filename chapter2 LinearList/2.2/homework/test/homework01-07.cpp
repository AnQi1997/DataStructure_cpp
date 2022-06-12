#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50

typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];
    int length;
} SqList;

// 1
bool del_min(SqList& L) {
    if (L.length == 0)
        return false;
    ElemType min = L.data[0];
    int pos = 0;
    for (int i = 1; i < L.length; i++) {
        if (min > L.data[i]) {
            min = L.data[i];
            pos = i;
        }
    }
    L.data[pos] = L.data[L.length - 1];
    L.length--;
    return true;
}

// 2
void reverseList(SqList& L) {
    for (int i = 0; i < L.length / 2; i++) {
        int temp = L.data[i];
        L.data[i] = L.data[L.length - 1 - i];
        L.data[L.length - 1 - i] = temp;
    }
}

// 3
// 3.1 用k记录等于x的个数 前移顶头，L.length - k就是表长
void del_x_1(SqList& L, ElemType x) {
    int k;
    // k删除所有值为x的数据
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] != x) {
            //不等于的应该留下
            L.data[i - k] = L.data[i];
        } else {
            k++;
        }
    }
    L.length = L.length - k;
}

// 3.2 用k记录不等于x的个数 直接拿前边来
void del_x_2(SqList& L, ElemType x) {
    int k = 0;
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] != x) {
            L.data[k] = L.data[i];
            k++;
        }
    }
    L.length = k;
}

// 4.
bool del_s_t_1(SqList& L, ElemType s, ElemType t) {
    if (s >= t || L.length == 0)
        return false;
    //找到第一个大于s的元素
    int i, j;
    for (i = 0; i < L.length && L.data[i] < s; i++)
        ;
    //找到第一个大于t的元素
    if (i >= L.length)
        return false;
    for (j = i; j < L.length && L.data[j] <= t; j++)
        ;
    for (; j < L.length; i++, j++) {
        L.data[i] = L.data[j];
    }
    L.length = i;
    return true;
}

// 5.
bool del_s_t_2(SqList& L, ElemType s, ElemType t) {
    if (s >= t || L.length == 0)
        return false;
    int k;
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] >= s && L.data[i] <= t) {
            k++;
        } else {
            //不在删除范围 当前下标减去删除的个数是新位置
            L.data[i - k] = L.data[i];
        }
    }
    L.length = L.length - k;
    return true;
}

// 6.
bool delSame(SqList& L) {
    if (L.length == 0)
        return false;
    int i, j;
    for (i = 0, j = 1; i < L.length; j++) {  // && j < L.length
        if (L.data[i] != L.data[j]) {
            L.data[++i] = L.data[j];
        }
    }
    L.length = i + 1;
    return true;
}

// 7.
bool mergeList(SqList& A, SqList& B, SqList& C) {
    if (A.length + B.length > MaxSize)
        return false;
    int i = 0, j = 0, k = 0;
    while (i < A.length && j < B.length) {
        if (A.data[i] > B.data[j]) {
            C.data[k++] = B.data[j++];
        } else {
            C.data[k++] = A.data[i++];
        }
    }
    while (i < A.length) {
        C.data[k++] = A.data[i++];
    }
    while (j < B.length) {
        C.data[k++] = B.data[j++];
    }
    C.length = k;  // ！= k + 1
    // k不再加1是因为A或B最后一个元素赋值给C后，k的值自增了1
    //此时，k的值就是表长
    //因为k是使用后自增
    return true;
}

// 8.
void reverse(int A[], int left, int right, int arraySize) {
    if (left >= right || right >= arraySize)
        return;
}

void printfList(SqList L) {
    for (int i = 0; i < L.length; i++) {
        printf("%4d", L.data[i]);
    }
    printf("\n");
}

int main() {
    // SqList L = {1, 2, 3, 3, 5};
    // L.length = 5;

    // 1
    // printfList(L);
    // del_min(L);
    // printfList(L);

    // 2
    // printfList(L);
    // reverseList(L);
    // printfList(L);

    // 3.1
    // printfList(L);
    // del_x_1(L, 3);
    // printfList(L);
    // 3.2
    // printfList(L);
    // del_x_2(L, 3);
    // printfList(L);

    // 4.
    // printfList(L);
    // del_s_t_1(L, 2, 3);
    // printfList(L);

    // 5.
    // printfList(L);
    // del_s_t_2(L, 2, 3);
    // printfList(L);

    // 6.
    // printfList(L);
    // delSame(L);
    // printfList(L);

    // 7.
    //     SqList A = {1, 2, 3};
    //     A.length = 3;
    // // C[0] A[0]
    // // C[1] A[1]
    // // C[2] A[2]
    // // C[3] B[0]
    // // C[4] B[1]
    // // C[5] B[2]
    // // C[6] B[3]
    //  k = 7
    //     SqList B = {4, 5, 6, 8};
    //     B.length = 4;
    //     SqList C;
    //     C.length = 0;
    //     mergeList(A, B, C);
    //     printfList(C);
}