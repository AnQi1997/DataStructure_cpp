/*
 * @Author: AnQi1997 2361067080@qq.com
 * @Date: 2022-06-22 10:14:30
 * @LastEditors: AnQi1997 2361067080@qq.com
 * @LastEditTime: 2022-06-22 12:25:24
 * @FilePath: \DataStructure_Cpp\chapter2 LinearList\2.3.3 双向链表\test3.cpp
 * @Description: 双链表第三次练习
 *
 * Copyright (c) 2022 by AnQi1997 2361067080@qq.com, All Rights Reserved.
 */
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

//结构体
typedef struct DNode {
    ElemType data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

//输出链表函数
void PrintList(DLinkList DL) {
    DL = DL->next;
    while (DL) {
        printf("%6d", DL->data);
        DL = DL->next;
    }
    printf("\n");
}

//头插法建立双链表
DLinkList DList_Head_Insert(DLinkList& DL) {
    DL = (DLinkList)malloc(sizeof(DNode));
    DL->next = NULL;
    DL->prior = NULL;

    DNode* s;
    ElemType x;
    scanf("%d", &x);

    while (x != 9999) {
        s = (DNode*)malloc(sizeof(DNode));
        s->data = x;

        //考虑只有一个头结点的情况
        s->next = DL->next;
        if (DL->next)
            DL->next->prior = s;
        s->prior = DL;
        DL->next = s;

        scanf("%d", &x);
    }
    return DL;
}

//尾插法建立双链表
DLinkList DList_Tail_Insert(DLinkList& DL) {
    DL = (DLinkList)malloc(sizeof(DNode));
    DL->prior = NULL;

    DNode* r = DL;
    DNode* s;

    ElemType x;
    scanf("%d", &x);

    while (x != 9999) {
        s = (DNode*)malloc(sizeof(DNode));
        s->data = x;

        r->next = s;
        s->prior = r;
        r = s;

        scanf("%d", &x);
    }
    r->next = NULL;
    return DL;
}

//按序号查找第i个结点
DNode* GetElem(DLinkList DL, int i) {
    if (0 == i)
        return DL;
    if (i < 1)
        return NULL;

    int j = 1;
    DNode* p = DL->next;

    while (p && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

//将值为e的结点插入到第i个位置
bool DList_Insert(DLinkList& DL, int i, ElemType e) {
    //找到第i-1个位置
    DNode* p = GetElem(DL, i - 1);
    if (NULL == p)  //判断是否为头结点
        return false;

    // 多余
    // DNode* q = p->next;  //判断插入位置是否为最后一个结点
    // if (NULL == q)
    //     return false;

    DNode* s = (DNode*)malloc(sizeof(DNode));
    s->data = e;

    //开始插入
    s->next = p->next;
    p->next->prior = s;
    s->prior = p;
    p->next = s;

    return true;
}

//删除第i个结点
bool DList_Delete(DLinkList& DL, int i) {
    DNode* p = GetElem(DL, i - 1);

    if (NULL == p)  // i = 1，0, -1, -2 时
        return false;

    DNode* q = p->next;  // 待删除的是最后一个结点
    if (NULL == q)
        return false;

    p->next = q->next;
    //如果删除的不是尾结点,即 p->next = NULL
    if(p->next != NULL) {
        // p->next != NULL;//删除的不是尾结点
        q->next->prior = p;
    }
    free(q);

    return false;
}

int main() {
    DLinkList DL;

    // DList_Head_Insert(DL);
    // PrintList(DL);

    DList_Tail_Insert(DL);
    PrintList(DL);

    // DNode* p = GetElem(DL, 2);
    // printf("%d", p->data);

    // DList_Insert(DL, 3, 100);
    // PrintList(DL);

    DList_Delete(DL, 2);
    PrintList(DL);

}
