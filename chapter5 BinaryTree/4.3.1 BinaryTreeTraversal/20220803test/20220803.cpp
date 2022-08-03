/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-08-03 18:57:47
 * @Description: �������ı���
 */
#include "function.h"

//����
void PreOrder(BiTree T) {
    if (T) {
        putchar(T->c);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}
//����
void InOrder(BiTree T) {
    if (T) {
        InOrder(T->lchild);
        putchar(T->c);
        InOrder(T->rchild);
    }
}
//����
void PostOrder(BiTree T) {
    if (T) {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        putchar(T->c);
    }
}

//��������ǵݹ�  ����ջ
void InOrder2(BiTree T) {
    SqStack S;
    InitStack(S);

    BiTree p = T;

    while (p || !StackEmpty(S)) {
        if (p) {
            Push(S, p);
            p = p->lchild;
        } else {
            Pop(S, p);
            putchar(p->c);
            p = p->rchild;
        }
    }
}

//��α���
void LevelOrder(BiTree T) {
    LinkQueue Q;
    InitQueue(Q);
    EnQueue(Q, T);

    BiTree p;

    while (!IsEmpty(Q)) {
        DeQueue(Q, p);
        putchar(p->c);

        if (p->lchild != NULL)
            EnQueue(Q, p->lchild);
        if (p->rchild != NULL)
            EnQueue(Q, p->rchild);
    }
}

int main() {
    // ��ν���
    BiTree tree = NULL;
    ptag_t phead = NULL, ptail = NULL, listpnew = NULL, pcur = NULL;
    BiTree pnew;

    char c;
    while (scanf("%c", &c) != EOF) {
        //����ʱ�����ı�־
        if (c == '\n')
            break;
        //���������
        pnew = (BiTree)calloc(1, sizeof(BiTNode));
        pnew->c = c;

        //�������н��
        listpnew = (ptag_t)calloc(1, sizeof(tag_t));
        listpnew->p = pnew;

        //������������
        if (NULL == tree) {
            tree = pnew;
            phead = listpnew;
            ptail = listpnew;
            pcur = listpnew;
            continue;
        } else {
            //��������գ���β�巨�ȷ��븨�����У���
            ptail->pnext = listpnew;
            ptail = listpnew;
        }

        //����������
        if (NULL == pcur->p->lchild)
            //�½�㸳������
            pcur->p->lchild = pnew;
        else if (NULL == pcur->p->rchild) {
            //�½�㸳���ҽڵ�
            pcur->p->rchild = pnew;
            pcur = pcur->pnext;
        }
    }

    printf("\n------�������------\n");
    PreOrder(tree);
    printf("\n------�������------\n");
    InOrder(tree);
    printf("\n------�������------\n");
    PostOrder(tree);
    printf("\n------��������ǵݹ�------\n");
    InOrder2(tree);
    printf("\n------��α���------\n");
    LevelOrder(tree);
    printf("\n");
}
