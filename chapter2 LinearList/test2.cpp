#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50

typedef int ElemType;
/**
 * @brief 静态存储
 *
 */
typedef struct {
    ElemType data[MaxSize];
    int length;
} SqList;

//插入
/**
 * @brief 在顺序表第i个位置上插入元素
 *
 * @param L
 * @param i
 * @return true
 * @return false
 */
bool ListInsert(SqList& L, int i, ElemType e) {
    if (i < 1 || i > L.length + 1)
        return false;
    if (L.length >= MaxSize)
        return false;
    for (int j = L.length; j >= i; j--) {
        //元素后移
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}

/**
 * @brief 删除第i个位置上的元素，用e返回
 *
 * @param L
 * @param i
 * @param e
 * @return true
 * @return false
 */
bool ListDelete(SqList& L, int i, ElemType e) {
    if (i < 1 || i > L.length) {
        return false;
    }
    e = L.data[i];
    //元素后移
    for (int j = i; j < L.length; j++) {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
}

/**
 * @brief 按值查找
 *
 * @param L
 * @param e
 * @return int
 */
int locateElem(SqList L, ElemType e) {
    int i;
    for (i = 0; i < L.length; i++) {
        if (L.data[i] == e) {
            return i + 1;
        }
    }
    return 0;
}

void printList(SqList L) {
    for (int i = 0; i < L.length; i++) {
        printf("%4d", L.data[i]);
    }
    printf("\n");
}

int main() {
    SqList LA = {1, 2, 6, 10, 12};
    LA.length = 10;
    printList(LA);

    // ListInsert(LA, 6, 100);
    // printList(LA);

    // ElemType delReturn;
    // ListDelete(LA, 2, delReturn);
    // printList(LA);

    // int flag = locateElem(LA, 10);
    // if(flag){
    //     printf("查找成功，下标为：%d", flag);
    // }else{
    //     printf("查找失败");
    // }

    





}
