#include<stdio.h>
#include<stdlib.h>

#define MaxSize 50

typedef int ElemType;

typedef struct{
    ElemType data[MaxSize];
    int length;
}SqList;

//i代表插入位置，从1开始，e要插入的元素
bool ListInsert(SqList &L, int i, ElemType &e){
    if(i < 1 || i > L.length + 1)
}

