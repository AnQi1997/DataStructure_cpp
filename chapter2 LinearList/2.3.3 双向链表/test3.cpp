/*
 * @Author: AnQi1997 2361067080@qq.com
 * @Date: 2022-06-22 10:14:30
 * @LastEditors: AnQi1997 2361067080@qq.com
 * @LastEditTime: 2022-06-22 12:25:24
 * @FilePath: \DataStructure_Cpp\chapter2 LinearList\2.3.3 ˫������\test3.cpp
 * @Description: ˫�����������ϰ
 *
 * Copyright (c) 2022 by AnQi1997 2361067080@qq.com, All Rights Reserved.
 */
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

//�ṹ��
typedef struct DNode {
    ElemType data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

//���������
void PrintList(DLinkList DL) {
    DL = DL->next;
    while (DL) {
        printf("%6d", DL->data);
        DL = DL->next;
    }
    printf("\n");
}

//ͷ�巨����˫����
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

        //����ֻ��һ��ͷ�������
        s->next = DL->next;
        if (DL->next)
            DL->next->prior = s;
        s->prior = DL;
        DL->next = s;

        scanf("%d", &x);
    }
    return DL;
}

//β�巨����˫����
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

//����Ų��ҵ�i�����
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

//��ֵΪe�Ľ����뵽��i��λ��
bool DList_Insert(DLinkList& DL, int i, ElemType e) {
    //�ҵ���i-1��λ��
    DNode* p = GetElem(DL, i - 1);
    if (NULL == p)  //�ж��Ƿ�Ϊͷ���
        return false;

    // ����
    // DNode* q = p->next;  //�жϲ���λ���Ƿ�Ϊ���һ�����
    // if (NULL == q)
    //     return false;

    DNode* s = (DNode*)malloc(sizeof(DNode));
    s->data = e;

    //��ʼ����
    s->next = p->next;
    p->next->prior = s;
    s->prior = p;
    p->next = s;

    return true;
}

//ɾ����i�����
bool DList_Delete(DLinkList& DL, int i) {
    DNode* p = GetElem(DL, i - 1);

    if (NULL == p)  // i = 1��0, -1, -2 ʱ
        return false;

    DNode* q = p->next;  // ��ɾ���������һ�����
    if (NULL == q)
        return false;

    p->next = q->next;
    //���ɾ���Ĳ���β���,�� p->next = NULL
    if(p->next != NULL) {
        // p->next != NULL;//ɾ���Ĳ���β���
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
