#include <stdio.h>

#define MaxSize 50

typedef struct {
    int data[MaxSize];
    int length;
} SqList;

void printList(SqList L) {
    for (int i = 0; i < L.length; i++) {
        printf("%3d", L.data[i]);
    }
    printf("\n");
}

// i：待插入的位置 下标：i-1
bool ListInsert(SqList& L, int i, int& num) {
    if (i < 0 || i > L.length + 1)
        return false;
    if (L.length > MaxSize)
        return false;
    for (int j = L.length; j > i - 1; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = num;
    L.length++;
    return true;
}

/**
 * @brief
 *
 * @param L
 * @param pos 删除的位置 下标：pos - 1
 * @return true
 * @return false
 */
bool ListDelete(SqList& L, int pos) {
    if (pos < 0 || pos > L.length)
        return false;
    if (L.length > MaxSize)
        return false;
    for (int j = pos - 1; j < L.length; j++) {
        L.data[j] = L.data[j + 1];
    }
    L.length--;
    return true;
}

int main() {
    // SqList L = {1, 2, 3};
    SqList L;
    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 3;
    L.length = 3;
    printList(L);

    int num;  //插入元素的值
    scanf("%d", &num);
    //插入到第二个位置,下标从0开始
    ListInsert(L, 2, num);
    //打印输出顺序表 %3d
    printList(L);

    // scanf读取整型数，该整型数是删除的位置
    int pos;
    scanf("%d", &pos);
    bool flag = ListDelete(L, pos);
    if (flag) {
        printList(L);
    } else {
        printf("fasle");
    }
    //顺序输出顺序6表
}
