#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct DNode {
    ElemType data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

void PrintList(DLinkList DL) {
    DL = DL->next;
    while (DL) {
        printf("%6d", DL->data);
        DL = DL->next;
    }
    printf("\n");
}

//ͷ�巨����˫������
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

        s->next = DL->next;
        if (DL->next) {
            //����ֻ��ͷ���ʱ
            DL->next->prior = s;
        }
        s->prior = DL;
        DL->next = s;

        scanf("%d", &x);
    }
    return DL;
}

//β�巨����������
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
    }
    r->next = NULL;
    return DL;
}

// DLinkList DList_Tail_Insert(DLinkList& DL) {
//     DL = (DLinkList)malloc(sizeof(DNode));
//     // DL->next = NULL;
//     //��󸳸�NULL����Ϊ��β�壬
//     // ������ȷ�����һ��Ԫ��
//     DL->prior = NULL;

//     DNode *s, *r = DL;

//     ElemType x;
//     scanf("%d", &x);

//     while (x != 9999) {
//         s = (DNode*)malloc(sizeof(DNode));
//         s->data = x;

//         r->next = s;
//         s->prior = r;
//         r = s;

//         scanf("%d", &x);
//     }
//     r->next = NULL;
//     return DL;
// }

//����Ų��ҵ�i�����
DNode* GetElem(DLinkList DL, int i) {
    int j = 1;
    if (0 == i)  //����ͷ���
                 // 0 == i ����д��ǰ�棬��֤�����ͨ
        // 0 = i ʱ�� �������ᱨ����֤�����ͨ
        return DL;
    if (i < 1)  //��ֵ��ɶҲ����
        return NULL;
    DNode* p = DL->next;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

//��ֵΪe���½����뵽��i��λ��
bool DList_Insert(DLinkList DL, int i, ElemType e) {
    //����λ�õ�ǰһ��
    DNode* p = GetElem(DL, i - 1);
    if (p == NULL)
        return false;

    //��������
    DNode* s = (DNode*)malloc(sizeof(DNode));
    s->data = e;

    s->next = p->next;
    s->next->prior = s;
    s->prior = p;
    p->next = s;

    return true;
}

//ɾ����i�����
bool DList_Delete(DLinkList DL, int i) {
    //DLinkList& DL����Ҫ���ã���Ϊ���ı�ͷ��
    DNode* p = GetElem(DL, i - 1);
    if (p == NULL)
        return false;

    DNode* q = p->next;
    
    if (q == NULL)
        return false;

    p->next = q->next;
    if (q->next != NULL) {
        q->next->prior = p;
    }
    free(q);
    return true;
}

int main() {
    DLinkList DL;

    // DList_Head_Insert(DL);
    // PrintList(DL);

    DList_Tail_Insert(DL);
    PrintList(DL);

    // DNode* p = GetElem(DL, 2);
    // printf("%d\n", p->data);

    // DList_Delete(DL, 2);
    // PrintList(DL);
}
