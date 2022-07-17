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
        printf("%3d");
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
// 返回true


int main() {
}
