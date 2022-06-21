#include <stdio.h>
#include <stdlib.h>
// TODO �����ĳ�������
// TODO �����ĳ�������
// TODO �����ĳ�������
// TODO �����ĳ�������
// TODO �����ĳ�������
// TODO �����ĳ�������
// TODO �����ĳ�������
// TODO �����ĳ�������

typedef int ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode* next;
} LNode, *LinkList;

// LNode �� *LinkList �ǲ�ͬ���ֵ�ͬһָ������
//������ͬ��Ϊ�˸����ϸ�����ȷ
//*LinkList���͵�ָ�������ʾ����һ��������  �ṹ��ָ�����������
// LNode���͵�ָ�������ʾ����ָ��ĳһ����ָ��  ���ṹ�����������
//ָ���ü�ͷ���ʳ�Ա   ���ʽṹ������õ�  ���ʣ��ʾ��ǹ涨����ס��������
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

        s->next = L->next;
        L->next = s;

        scanf("%d", &x);
    }
    return L;
}

/**
 * @brief ͷ�巨
 *
 * @param L
 * @return LinkList
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

LinkList List_RearInsert(LinkList& L) {
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s, *r = L;
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

// ����Ų���
// �ӵ�һ����������ֱ���ҵ���i�����Ϊֹ��
// ���򷵻����һ�����ָ����NULL
LNode* GetElem(LinkList L, int i) {
    int j = 1;           //������
    LNode* p = L->next;  //ָ���׽ڵ�

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
 * �ӵ������һ����㿪ʼ��
 * ��ǰ�������αȽϸ�����������ֵ��
 * �����ڸ���ֵe���򷵻ظý���ָ��
 * ������������û�������Ľ�㣬�򷵻�NULL
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
    LinkList p = GetElem(L, i - 1);
    if (NULL == p)  
    //�ŵ����λ�ò����� Ҳ���ǲ���λ����ͷ���֮ǰ��ʱ��
    //Ҳ���ǲ���λ�ò��Ϸ���i=0ʱ�������λ����ͷ��㣬����false
        return false;
    //��ʱ�ҵ�����λ��

    //Ϊ����Ԫ������ռ�
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

int main() {
    LinkList L;

    // CreatList1(L);
    // printList(L);

    // CreatList2(L);
    // printList(L);

    // List_HeadInsert(L);
    // printList(L);

    //����Ų���
    // GetElem(L, 1);
    // printf("%d", GetElem(L, 1)->data);

    //��ֵ����
    // LNode* p = LocateElem(L, 2);
    // printf("%d", p->data);

    List_RearInsert(L);
    printList(L);

    bool flag = ListFrontInsert(L, 0, 100);
    if (flag) {
        printList(L);
    } else {
        printf("����ʧ�ܣ�");
    }

    // ListDelete(L, 1);
    // printList(L);
}