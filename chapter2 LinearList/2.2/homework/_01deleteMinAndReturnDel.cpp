#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50

typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];
    int length;
} SqList;

//删除具有最小值的元素（假设唯一），并由函数返回被删元素的值，空出的位置由最后一个元素填补
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

void printfList(SqList &L){
    for(int i = 0; i < L.length; i++){
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

    bool ret = deleteMin(L);

    printfList(L);
}
