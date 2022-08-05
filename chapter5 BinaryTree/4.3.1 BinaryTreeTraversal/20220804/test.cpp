/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-08-04 18:00:50
 * @Description:
 */
#include "function.h"

void PreOrder(BiTree T) {
    if (T) {
        putchar(T->c);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

void InOrder(BiTree T) {
    if (T) {
        InOrder(T->lchild);
        putchar(T->c);
        InOrder(T->rchild);
    }
}

void PostOrder(BiTree T) {
    if (T) {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        putchar(T->c);
    }
}

void InOrder2(BiTree T) {
    SqStack S;
    InitStack(S);

    BiTree p = T;
    while (p || !StackEmpty(S)) {
        // p���ջ���ջ����ʱִ�д�ѭ��
        //! StackEmpty(S)
        //ջ����ʱ������false��ȡ��Ϊtrue
        //ջ��ʱ������true��ȡ��Ϊfalse����ִ��
        if (p) {
            //������һֱѹջ
            Push(S, p);
            p = p->lchild;
        } else {
            //������󣬵�ջ
            Pop(S, p);
            // putchar(p->c);
            putchar(p->c);
            //����p����������1
            p = p->rchild;
        }
    }
}

void LevelOrder(BiTree T) {
    LinkQueue Q;
    InitQueue(Q);

    BiTree p;
    EnQueue(Q, T);

    while (!QueueEmpty(Q)) {
        //�ӿգ�����true��ȡ��λfalse����ִ�д�ѭ��
        //������Ԫ�أ�����false��ȡ��Ϊtrue��ִ�д�ѭ��
        DeQueue(Q, p);
        putchar(p->c);
        //�߳��߽�p�������Һ���
        if (p->lchild != NULL)
            EnQueue(Q, p->lchild);
        if (p->rchild != NULL)
            EnQueue(Q, p->rchild);
    }
}

int main() {
    //��ν���
    BiTree tree = NULL;
    BiTree pnew;  //��������½��
    ptag_t phead = NULL, ptail = NULL, pcur = NULL, listpnew = NULL;

    BiElemType c;

    while (scanf("%c", &c) != EOF) {
        if (c == '\n')
            break;
        // TODO
        pnew = (BiTree)calloc(1, sizeof(BiTNode));
        pnew->c = c;

        listpnew = (ptag_t)calloc(1, sizeof(tag_t));
        listpnew->p = pnew;

        if (NULL == tree) {
            tree = pnew;

            phead = listpnew;
            ptail = listpnew;
            pcur = listpnew;

            continue;  //������һ��ѭ��
            // break����������ѭ��
        } else {
            //��������գ����븨������
            ptail->pnext = listpnew;
            ptail = listpnew;
        }

        //����
        if (NULL == pcur->p->lchild)
            pcur->p->lchild = pnew;
        else if (NULL == pcur->p->rchild) {
            pcur->p->rchild = pnew;
            pcur = pcur->pnext;
        }
    }

    printf("\n--------�������----------\n");  //Ҳ������������ȴ�ӡ��ǰ��㣬��ӡ���ӣ���ӡ�Һ���
    PreOrder(tree);

    printf("\n--------�������----------\n");
    InOrder(tree);

    printf("\n--------�������----------\n");
    PostOrder(tree);

    printf("\n--------��������ǵݹ�----------\n");
    InOrder2(tree);

    printf("\n--------��α���----------\n");
    LevelOrder(tree);
}
