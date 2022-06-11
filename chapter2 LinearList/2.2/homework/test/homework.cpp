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
// TODO
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

// TODO
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
    
    return true;
}

void printfList(SqList L) {
    for (int i = 0; i < L.length; i++) {
        printf("%4d", L.data[i]);
    }
    printf("\n");
}

int main() {
    SqList L = {1, -1, 3, 3, 5};
    L.length = 5;

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
}