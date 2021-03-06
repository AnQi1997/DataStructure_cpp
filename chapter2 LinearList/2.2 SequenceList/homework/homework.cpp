#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50

typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];
    int length;
} SqList;

// 1. 删除具有最小值的元素（假设唯一），并由函数返回被删元素的值，空出的位置由最后一个元素填补
//若顺序表为空，则显示出错信息并退出运行
bool deleteMin(SqList& L) {
    if (L.length == 0)
        return false;
    ElemType value = L.data[0];
    int pos = 0;
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] < value) {
            value = L.data[i];
            pos = i;
        }
    }
    L.data[pos] = L.data[L.length - 1];
    L.length--;
    return true;
}

// 2.设置一高效算法，将顺序表L的所有元素逆置，要求算法的空间复杂度为O(1)
void ReverseList(SqList& L) {
    for (int i = 0; i < L.length / 2; i++) {
        ElemType temp = L.data[i];
        // 0 L.length - 1
        // 1 L.length - 2
        L.data[i] = L.data[L.length - i - 1];
        L.data[L.length - i - 1] = temp;
    }
    // return L;
}

// 3.对长度为n的顺序表L，编写一个时间复杂度为O(n)，空间复杂度为O(1)的算法
//该算法删除线性表中所有值为x的数据元素
// 3.1 用k记录顺序表中不等于x的元素个数，统计个数k，若不等于x向前移动k个位置，最后修改长度
void del_x_1(SqList& L, ElemType x) {
    int k = 0;
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] != x) {
            L.data[k] = L.data[i];  //前移
            k++;
        }
    }
    L.length = k;
}

// 3.2 用k记录顺序表L中等于x的元素个数，边扫描边统计k，若不等于x则前移
void del_x_2(SqList& L, ElemType x) {
    int k = 0, i = 0;  // k记录值等于x的个数
    while (i < L.length) {
        if (L.data[i] == x) {
            k++;
        } else {
            L.data[i - k] = L.data[i];
        }
        i++;
    }
    L.length = L.length - k;
}

// 4 从有序顺序表中删除其值在给定值s与t之间（要求s<t）的所有元素，
//若s或t不合理或顺序表为空，则显示出错信息并退出运行
bool del_s_2_t(SqList& L, ElemType s, ElemType t) {
    int i, j;
    if (s >= t || L.length == 0)
        return false;
    //寻找第一个大于s的元素
    for (i = 0; i < L.length && L.data[i] < s; i++)
        ;
    //所有值都小于s，返回false
    if (i >= L.length)
        return false;
    for (j = i; j < L.length && L.data[j] <= t; j++)
        ;
    //前移，填补被删元素位置
    for (; j < L.length; i++, j++) {
        L.data[i] = L.data[j];
    }
    L.length = i;
    return true;
}

// 5. 从顺序表中删除其值在给定值s与t之间（包含s和t,要求s<t）的所有元素，
//若s或t不合理或顺序表为空，则显示错误信息并退出运行
bool del_s_2_t_2(SqList& L, ElemType s, ElemType t) {
    if (s >= t || L.length == 0)
        return false;
    int count = 0;
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] >= s && L.data[i] <= t) {  //满足删除范围
            count++;
        } else {
            L.data[i - count] = L.data[i];
        }
    }
    L.length = L.length - count;
    return true;
}

// 6. 从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同
//思路：有序顺序表，值相同的元素一定在连续位置上
//类似直接插入排序的思想：
//初始 把第一个元素看作是非重复的有序表，
//之后依次判断后面的元素是否与前面的非重复有序表的最后一个元素相同，
//若相同，则继续向后判断  若不同，则插入前面的非重复有序表的最后，直至判断到表尾为止
bool deleteSame(SqList& L) {
    if (L.length == 0)
        return false;
    int i, j;
    for (i = 0, j = 1; i < L.length; j++) {
        if (L.data[i] != L.data[j])   //相邻的不相等
            L.data[++i] = L.data[j];  //如果不同，插入前面的有序表
        // i = i + 1；
        // L.data[i] = L.data[j];
    }
    L.length = i + 1;
    return true;
}

// 7. 将两个有序顺序表合并为一个新的有序顺序表，并由函数返回结果顺序表
//顺序取下两个顺序表表头较小的结点存入新的顺序表。
// 然后，看哪个表还有剩余，将剩下的部分加到新的顺序表后面
bool mergeList(SqList& A, SqList& B, SqList& C) {
    if (A.length + B.length > MaxSize) {
        return false;
    }
    int i = 0, j = 0, k = 0;
    while (i < A.length && j < B.length) {
        if (A.data[i] <= B.data[j]) {
            C.data[k++] = A.data[i++];
        } else {
            C.data[k++] = B.data[j++];
        }
    }
    while (i < A.length) {  // A还没比完
        C.data[k++] = A.data[i++];
    }
    while (j < B.length) {
        C.data[k++] = B.data[j++];
    }
    C.length = k;
    return true;
}



void printfList(SqList L) {
    for (int i = 0; i < L.length; i++) {
        printf("%3d", L.data[i]);
    }
    printf("\n");
}

int main() {
    SqList L;
    L.data[0] = 6;
    L.data[1] = 7;
    L.data[2] = 8;
    L.length = 3;
    printfList(L);

    // 1.删除
    bool ret = deleteMin(L);
    printfList(L);

    // 2.逆置
    //  ReverseList(L);
    //  printfList(L);

    // 3.1
    //  del_x_1(L, 8);
    //  printfList(L);
    // 3.2
    //  del_x_2(L, 8);
    //  printfList(L);

    // 4. del_s_2_t
    // del_s_2_t(L, 7, 8);
    // printfList(L);

    // 5.
    //  del_s_2_t_2(L, 7, 9);
    //  printfList(L);

    // 6.
    // L = {1, 2, 2, 2, 2, 3, 3, 3, 4, 4, 5};
    // L.length = 11;
    // printfList(L);
    // printf("-----------\n");
    // deleteSame(L);
    // printfList(L);

    // 7.
    // SqList A = {1, 3, 5};
    // A.length = 3;
    // SqList B = {2, 4, 6, 8, 10};
    // B.length = 5;
    // SqList C;
    // C.length = 8;
    // mergeList(A, B, C);
    // printfList(C);
}
