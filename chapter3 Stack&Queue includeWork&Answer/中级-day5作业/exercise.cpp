/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-06-27 18:23:14
 * @Description: �м�-day5
 * ����3 4 5 6 7 9999һ��������9999���������ͨ��β�巨�½�����
 * ���ҵڶ���λ�õ�ֵ�������
 * ��2��λ�ò���99�����Ϊ  3 99  4  5  6  7��
 * ɾ����4��λ�õ�ֵ����ӡ���Ϊ  3 99  4  5  6  7��
 */
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode* next;
} LNode, *LinkList;

void PrintList(LinkList L) {
    L = L->next;
    while (L) {
        printf("%3d", L->data);
        L = L->next;
    }
    printf("\n");
}

//β�巨����������
LinkList List_Tail_Insert(LinkList& L) {
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;

    LNode *s, *r = L;

    ElemType x;
    scanf("%d", &x);

    while (x != 9999) {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;

        r->next = s;
        r = s;

        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}

//���ҵ�i��λ��
LNode* GetElem(LinkList L, int i) {
    if (0 == i)
        return L;
    if (i < 1)
        return NULL;
    LNode* p = L->next;
    int j = 1;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

//�ڵ�i��λ�ò���һ��ֵ
bool List_Insert_i_x(LinkList L, ElemType& x, int i) {
    //���i-1��λ��
    LNode* p = GetElem(L, i);
    if(NULL == p)
        return false;

    LNode* s = (LNode*)malloc(sizeof(LNode));
    s->data = x;

    s->next = p->next;
    p->next = s;

    return true;
}

//ɾ����i��λ�õ�Ԫ��
bool ListDelete(LinkList L, int i){

}

int main() {
    LinkList L;
    List_Tail_Insert(L);
    PrintList(L);

    LNode* p = GetElem(L, 2);
    printf("%d\n", p->data);
}
