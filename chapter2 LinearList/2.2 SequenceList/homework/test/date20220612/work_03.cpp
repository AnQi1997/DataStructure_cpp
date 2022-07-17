#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50

typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];
    int length;
} SqList;

//删除值时是x的数据元素
//目的：找到不是k的元素后，前移

//法一：用k计数 ！= x的元素个数，L.data[k++] = L.data[i++] 表长是k+1
void del_x_1(SqList& L, ElemType x) {
    int k = 0;
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] != x)
            L.data[k++] = L.data[i];  // 1）
    }
    L.length = k;  // 1）式中已经自加了
}

//法二：用k计数 == x的元素个数，元素前移L.data[i-k] = L.data[i];
void del_x_2(SqList& L, ElemType x) {
    int k = 0;
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == x)
            k++;
        else
            L.data[i - k] = L.data[i];
    }
    L.length = L.length - k;
}

void printList(SqList L) {
    for (int i = 0; i < L.length; i++) {
        printf("%4d", L.data[i]);
    }
    printf("\n");
}

int main() {
    SqList L = {1, 2, 2, 3, 3, 5};
    L.length = 6;
    // printList(L);
    // del_x_1(L, 2);
    // printList(L);
    // printList(L);
    // del_x_2(L, 2);
    // printList(L);

    return 0;
}
