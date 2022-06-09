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

//习题1.1
bool delMin(SqList& L) {
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

//习题 1.2
void reverseList(SqList& L) {
    ElemType temp;
    for (int i = 0; i < L.length / 2; i++) {
        temp = L.data[i];
        L.data[i] = L.data[L.length - 1 - i];
        L.data[L.length - 1 - i] = temp;
    }
}

//习题1.3
void delete_x_1(SqList& L, ElemType x) {
    // 1 计算不为x的个数，放到头
    int count = 0;
    for (int i = 0, j = 0; i < L.length; i++, j++) {
        if (L.data[i] != x) {
            L.data[count] = L.data[i];
            count++;
        }
    }
    L.length = count;
}

// 习题 1.3
// 2.是x
void delete_x_2(SqList& L, ElemType x) {
    int k = 0;
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == x) {
            k++;
        } else {
            //如果L.data[i]不是x 那么前移k个额位置
            L.data[i - k] = L.data[i];
        }
    }

    // int k = 0, i = 0;
    // while (i < L.length) {
    //     if (L.data[i] == x) {
    //         k++;
    //     } else {
    //         L.data[i - k] = L.data[i];
    //     }
    //     i++;
    // }
    L.length = L.length - k;
}

//习题 1.4 要求:s<t
void del_s_t_1(SqList& L, ElemType s, ElemType t) {
    if (s >= t || L.length == 0)
        return false;
    //有序顺序表
    //找到第一个大于s的数
    for (int i = 0; i < L.length && L.data[i] < s; i++)
        ;
    // TODO i最大值是L.length 为啥要写 i >= L.length
    if (i >= L.length)
        return false;
    //找到第一个大于t的数
    for (int j = i; j < L.length && L.data[j] < t; j++)
        ;
    
}

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

//删除
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

//查找
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
    SqList LA = {1, 2, 6, 6, 10, 12};
    LA.length = 6;
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

    //习题1.1
    // delMin(LA);
    // printList(LA);

    //习题 1.2
    // reverseList(LA);
    // printList(LA);

    //习题1.3.1
    // delete_x_1(LA, 6);
    // printList(LA);

    //习题1.3.2
    delete_x_2(LA, 6);
    printList(LA);
}
