#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode* next;
} LNode, *LinkList;
// LNode �� *LinkList �ǲ�ͬ���ֵ�ͬһָ������
//������ͬ��Ϊ�˸����ϸ�����ȷ
//*LinkList���͵�ָ�������ʾ����һ��������
// LNode���͵�ָ�������ʾ����ָ��ĳһ����ָ��

void printList(LinkList L) {
    L = L->next;
    while (L != NULL) {
        printf("%4d", L->data);
        L = L->next;
    }
    printf("\n");
}

/**
 * @brief ͷ�巨����������
 *  �÷�����һ���ձ�ʼ�������½�㣬������ȡ�������ݴ�ŵ��½�����������
 *  Ȼ���½����뵽��ǰ����ı�ͷ����ͷ�ڵ�֮��
 */
LinkList CreatList1(LinkList& L) {
    LNode* s;  //�½��
    int x;     //�½��������

    L = (LinkList)malloc(sizeof(LNode));  //����ͷ���
    L->next = NULL;

    scanf("%d", &x);
    while (x != 9999) {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;

        s->next = L   456e->next;
        L->next = s;

        scanf("%d", &x);
    }
    return L;
}

/**
 * @brief β�巨����������
 *
 */
LinkList CreatList2(LinkList& L) {
    int x;
    L = (LinkList)malloc(sizeof(LNode));

    LNode *s, *r = L;

    scanf("%d", &x);
    while (x != 9999) {
        s = (LinkList)malloc(sizeof(LinkList));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}

/**
 * @brief Get the Elem object
 *
 * @param L
 * @param i
 * @return LNode*
 */
LNode* GetElem(LinkList L, int i) {
    int j = 1;
    LNode* p = L->next;
    if (i == 0)
        return L;
    if (i < 1)
        return NULL;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

/**
 * @brief ��ֵ����
 *
 * @param L
 * @param e
 * @return LNode*
 */
LNode* LocateElem(LinkList L, ElemType e) {
    LNode* p = L->next;
    while (p && p->data != e)
        p = p->next;
    return p;
}

int main() {
    LinkList L;

    // CreatList1(L);
    // printList(L);

    // CreatList2(L);
    // printList(L);
}