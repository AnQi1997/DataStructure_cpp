#include<stdio.h>
#include<stdlib.h>

#define MaxSize 50

typedef int ElemType;

typedef struct{
    ElemType data[MaxSize];
    int length;
}SqList;

//i�������λ�ã���1��ʼ��eҪ�����Ԫ��
bool ListInsert(SqList &L, int i, ElemType &e){
    if(i < 1 || i > L.length + 1)
}

