#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50

typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];
    int length;
} SqList;

/**
 * @brief 在顺序表L第i（1 <= i <= L.length）个位置插入新元素e
 * 若i输入不合法，则返回false，表示插入失败
 * 否则，将第i个元素及之后的所有元素依次往后移动一个位置，
 * 腾出一个空位置插入新元素e，顺序表长度增加1，插入成功，返回true
 * @param L
 * @param i
 * @param e
 * @return true
 * @return false
 */
// i代表插入位置，从1开始，e要插入的元素
bool ListInsert(SqList& L, int i, ElemType e) {
    if (i < 1 || i > L.length + 1)
        return false;
    if (L.length >= MaxSize)
        return false;
    for (int j = L.length; j >= i; j--)
        L.data[j] = L.data[j - 1];
    L.data[i - 1] = e;
    L.length++;
    return true;
}
//最好情况：在表尾插入：即i=n+1;时间复杂度：O(1)
//最坏情况：在表头插入：即i=1;时间复杂度：O(n)
//平均情况：O(n)

/**
 * @brief
 * 删除顺序表L中第i(1 <= i <= L.length)个位置的元素，可引用变量e返回。
 * 若i的输入不合法，则返回false。
 * 否则，将被删元素赋给引用变量e，
 * 并将第i+1个元素及其后的所有元素依次往前移动一个位置，返回true
 *
 * @param L
 * @param i：位序
 * @param e
 * @return true
 * @return false
 */
bool ListDelete(SqList& L, int i, ElemType& e) {
    if (i < 1 || i > L.length)
        return false;
    //到这时，i合法，用引用变量e返回
    e = L.data[i - 1];
    for (int j = i; j < L.length; j++) {
        //元素前移
        L.data[j - 1] = L.data[j];
    }
    //表长减一
    L.length--;
    return true;
}
//最好情况：删除表尾，即i=n，无需移动，时间复杂度O(1)
//最坏情况：删除表头，即i=1,需移动除表头以外的所有元素，时间复杂度O(n)
//平均情况：i=1~n累加 pi * (n-i) = 1/n * (n-i)。时间复杂度：O(n)

/**
 * @brief 在顺序表L中查找第一个元素值等于e的元素，并返回其位序
 *
 */
int LocateElem(SqList L, ElemType e) {
    int i;
    for (i = 0; i < L.length; i++) {
        if (L.data[i] == e)
            return i + 1;
    }
    return 0;
}
//最好情况：查找元素在表头，时间复杂度O(1)
//最坏情况：查找元素在表尾（或者不存在），需要比较n次，时间复杂度O(n)
//平均情况：pi = 1/n; 累加i = 1~n 1/n * i

void PrintList(SqList L) {
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

int main() {
    SqList L;
    L.data[0] = 6;
    L.data[1] = 7;
    L.data[2] = 8;
    L.length = 3;
    PrintList(L);

    printf("--------------\n");
    //插入
    bool ret1;
    ret1 = ListInsert(L, 2, 100);
    if (ret1) {
        PrintList(L);
        printf("插入成功！\n");
    } else {
        printf("插入失败！\n");
    }
    printf("--------------\n");
    //删除
    bool ret2;
    ElemType delE;  //返回变量
    PrintList(L);
    ret2 = ListDelete(L, 2, delE);
    if (ret2) {
        PrintList(L);
        printf("删除成功!\n");
    } else {
        printf("删除失败！\n");
    }
    printf("--------------\n");

    int ret3 = LocateElem(L, 6);
    printf("元素位序：%d\n", ret3);
    if(ret3){
        printf("查找成功!\n");
    }else{
        printf("查找失败!\n");
    }
}
