#include <stdio.h>
#include <stdlib.h>
// TODO ү�Լ�д�Σ��Լ���д
// TODO ү�Լ�д�Σ��Լ���д
// TODO ү�Լ�д�Σ��Լ���д
// TODO ү�Լ�д�Σ��Լ���д
// TODO ү�Լ�д�Σ��Լ���д
// TODO ү�Լ�д�Σ��Լ���д
// TODO ү�Լ�д�Σ��Լ���д
// TODO ү�Լ�д�Σ��Լ���д

typedef int ElemType;  //�����

typedef struct LNode {
    ElemType data;
    struct LNode* next;
} LNode, *LinkList;

void PrintList(LinkList L) {
    //��ͷ��㣬ͷ�����ɶҲû�У�����һ��
    L = L->next;
    while (L != NULL) {
        printf("%6d", L->data);
        L = L->next;
    }
    printf("\n");
}

/**
 * @brief ͷ�巨
 *
 */
LinkList List_HeadInsert(LinkList& L) {
    LNode* s;
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;

    scanf("%d", &x);

    while (x != 9999) {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;

        s->next = L->next;
        L->next = s;

        scanf("%d", &x);
    }
    return L;
}

/**
 * @brief β�巨
 * ��Ҫһ��βָ��
 */
LinkList List_TailInsert(LinkList& L) {
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;

    LNode *s, *r = L;

    int x;
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

/**
 * @brief
 * ����Ų���
 * �ӵ�һ����������ֱ���ҵ���i�����Ϊֹ��
 * ���򷵻����һ�����ָ����NULL
 */
LNode* GetElem(LinkList L, int i) {
    int j = 1;
    //������Ѱָ��
    LNode* p = L->next;
    if (i == 0)
        return L;
    if (i < 0)
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
 */
LNode* LocateElem(LinkList L, ElemType e) {
    LNode* p = L->next;
    while (p && p->data != e)
        p = p->next;
    return p;
}

/**
 * @brief �½������i��λ��
 * ��ֵΪx���½����뵽�������i��λ���ϣ�
 * �ȼ�����λ�õĺϷ��ԣ�
 * Ȼ���ҵ�����λ�õ�ǰ����㣬����i-1����㣬���������½��
 */
bool ListFrontInsert(LinkList L, int i, ElemType e) {
    //���ҵ���i-1��λ��
    LNode* p = GetElem(L, i - 1);
    // p�ǵ�i-1�����
    //�����½��s
    LNode* s = (LNode*)malloc(sizeof(LNode));
    s->data = e;

    s->next = p->next;
    p->next = s;

    return true;
}

//ɾ����i�����
bool ListDelete(LinkList L, int i) {
    LNode* p = GetElem(L, i - 1);
    LNode* q = p->next;
    p->next = q->next;
    free(q);
    return true;
}

/**
 * @brief
 *
 * @return int
 */
int main() {
    LinkList L;

    //ͷ�巨���������
    List_HeadInsert(L);
    PrintList(L);

    // bool flag = ListFrontInsert(L, 2, 100);
    // if (flag) {
    //     PrintList(L);
    // } else {
    //     printf("����ʧ��");
    // }
    //β�巨��˳����� ����˳��ǰ��˳��
    // List_TailInsert(L);
    // PrintList(L);
    //����Ų���
    // printf("%d\n", GetElem(L, 2)->data);
    // ��ֵ����
    // printf("%d\n", LocateElem(L, 2)->data);

    ListDelete(L, 2);
    PrintList(L);

    return 0;
}
