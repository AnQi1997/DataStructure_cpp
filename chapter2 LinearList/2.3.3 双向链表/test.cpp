#include <stdio.h>
#include <stdlib.h>
// TODO ү���ģ�
typedef int ElemType;

//��ȵ�����������һ��ָ��ǰ����priorָ�룬���
//��ֵ���ҺͰ�λ���ҵĲ����뵥������ͬ��
//��ΪҪ��priorָ�������޸ģ��ؼ��Ǳ�֤�޸Ĺ����в�����
//��˫������Ժܷ�����ҵ���ǰ����㣬���
//���� ɾ������ʱ�临�ӶȽ�ΪO(1)
typedef struct DNode {
    ElemType data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

void PrintDList(DLinkList DL) {
    // DNode* p = DL->next;
    // while(p){
    //     printf("%6d", p->data);
    //     p = p->next;
    // }
    DL = DL->next;
    while (DL) {
        printf("%6d", DL->data);
        DL = DL->next;
    }
    printf("\n");
}

//˫�������ͷ�巨
DLinkList DList_Head_Insert(DLinkList& DL) {
    DL = (DNode*)malloc(sizeof(DNode));
    DL->next = NULL;
    DL->prior = NULL;

    DNode* s;
    int x;
    scanf("%d", &x);
    while (x != 9999) {
        s = (DNode*)malloc(sizeof(DNode));
        s->data = x;

        s->next = DL->next;
        //�����һ�����ʱ������Ҫ��һ������
        if (DL->next) {
            DL->next->prior = s;
        }
        s->prior = DL;
        DL->next = s;

        scanf("%d", &x);
    }
    return DL;
}

//˫������β�巨
DLinkList DList_Tail_Insert(DLinkList& DL) {
    DL = (DLinkList)malloc(sizeof(DNode));
    DL->prior = NULL;

    DNode *s, *r = DL;

    int x;
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

//����Ų��ҽ��ֵ �� ���ҵ�i��
DNode* GetElem(DLinkList DL, int i) {
    int j = 1;
    if (i == 0)
        return DL;  //����ͷ��㣬ͷ���ɶҲ����
    if (i < 1)      // i<0ʱ����Ч
        return NULL;
    DNode* p = DL->next;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

//���½����뵽��i��λ��
bool DListInsert(DLinkList& DL, ElemType e, int i) {
    // �ҵ�ǰһ�����
    DNode* p = GetElem(DL, i - 1);

    if (p == NULL)
        return false;

    DNode* s = (DNode*)malloc(sizeof(DNode));
    s->data = e;

    s->next = p->next;
    p->next->prior = s;
    s->prior = p;
    p->next = s;

    return true;
}

//ɾ����i�����
bool ListDelete(DLinkList& DL, int i) {
    //�ҵ���i-1�����
    DNode* p = GetElem(DL, i - 1);
    if (p == NULL)  // TODO ��ɶ��˼
        return false;

    DNode* q = p->next;

    if (q == NULL)
        return false;  // TODO

    p->next = q->next;  //����  prior��û��

    if (q->next != NULL)
        // q->next != NULL �������һ�����
        // �ϵ�ǰ��
        //
        // q->next == NULLʱɾ����q�����һ�����
        // ���������if��ֱ���ͷŽ��
        q->next->prior = p;
    free(q);
    return true;
}

int main() {
    DLinkList DL;

    // DList_Head_Insert(DL);
    // PrintDList(DL);

    DList_Tail_Insert(DL);
    PrintDList(DL);

    //����Ų���
    DNode* p = GetElem(DL, 2);
    printf("%d", p->data);
}
