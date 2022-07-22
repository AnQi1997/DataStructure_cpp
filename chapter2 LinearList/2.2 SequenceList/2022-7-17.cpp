/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-07-17 19:37:30
 * @Description: 顺序表
 */
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50

typedef int ElemType;

//静态分配
typedef struct {
    ElemType data[MaxSize];
    int length;
} SqList;

//动态分配
#define InitSize 100
typedef struct {
    ElemType* data;
    int capacity;
    int length;
} SeqList;

void PrintList(SqList L) {
    for (int i = 0; i < L.length; i++) {
        printf("%3d", L.data[i]);
    }
    printf("\n");
}

//在顺序表L的第i个位置插入新元素e。若i的输入不合法，
// 则返回false，表示插入失败。
//否则，将第i个元素及其后的所有元素依次往后移动一个位置，
// 腾出一个空位置插入新元素e
//顺序表长度增加1，插入成功，返回true。
bool ListInsert(SqList& L, int i, ElemType e) {
    if (i < 1 || i > L.length + 1)
        return false;
    if (L.length >= MaxSize)  //表长超出限定空间
        return false;
    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}

//删除顺序表L中第i（1 <= i <= L.length）个位置的元素
//用引用变量e返回。若i的输入不合法，则返回false；否则
//将被删除元素赋值给引用变量e，
//并将i+1个元素及其之后的所有元素依次往前移动一个位置，
// 返回t
bool ListDelete(SqList& L, int i, ElemType& e) {
    if (i < 1 || i > L.length)
        return false;
    e = L.data[i - 1];
    for (int j = i; j < L.length; j++) {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
}

//查找元素
//按值查找，在顺序表L中查找第一个元素等于e的元素，并返回其位序
// bool LocateElem(SqList L, ElemType e) {
//     // if (L.length == 0)
//     //     return false;
//     int i;
//     for (i = 0; i < L.length; i++) {
//         if (L.data[i] == e)
//             printf("位序：%d\n", i);
//         return true;
//     }
// }

int LocateElem(SqList L, ElemType e) {
    int i;
    for (i = 0; i < L.length; i++) {
        if (L.data[i] == e)
            return i + 1;
    }
    return 0;
}

int main() {
    SqList L = {1, 2, 3, 4, 5};
    L.length = 5;
    PrintList(L);

    //插入操作
    ListInsert(L, 1, 10);
    PrintList(L);

    //删除操作
    ElemType e;
    ListDelete(L, 1, e);
    printf("%d\n", e);

    //查找操作
    PrintList(L);
    int num = LocateElem(L, 5);
    printf("%d\n", num);
}
