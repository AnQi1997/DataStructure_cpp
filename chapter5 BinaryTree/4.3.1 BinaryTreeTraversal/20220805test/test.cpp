#include "function.h"

void PreOrder(BTree T) {
    if (T) {
        putchar(T->c);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

void InOrder(BTree T) {
    if (T) {
        InOrder(T->lchild);
        putchar(T->c);
        InOrder(T->rchild);
    }
}

void PostOrder(BTree T) {
    if (T) {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        putchar(T->c);
    }
}

//��������ǵݹ�
// void InOrder2(BTree T) {
//     SqStack S;
//     InitStack(S);
//     BTree p = T;
//     while (p || !StackEmpty(S)) {
//         if (p) {
//             Push(S, p);
//             p = p->lchild;
//         } else {
//             Pop(S, p);
//             putchar(p->c);
//             p = p->rchild;
//         }
//     }
// }

// void InOrder2(BTree T){
//     SqStack S;
//     InitStack(S);
//     BTree p = T;
//     while(p || !StackEmpty(S)){
//         if(p){
//             Push(S, p);
//             p = p->lchild;
//         }else{
//             Pop(S, p);
//             putchar(p->c);
//             p = p->rchild;
//         }
//     }
// }

void InOrder2(BTree T) {
    //ջ
    SqStack S;
    InitStack(S);

    BTree p = T;

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

// void LevelOrder(BTree T) {
//     LinkQueue Q;
//     InitQueue(Q);
//     BTree p;
//     EnQueue(Q, T);
//     while (!QueueEmpty(Q)) {
//         DeQueue(Q, p);
//         putchar(p->c);
//         if (p->lchild)
//             EnQueue(Q, p->lchild);
//         if (p->rchild)
//             EnQueue(Q, p->rchild);
//     }
// }

// void LevelOrder(BTree T) {
//     LinkQueue Q;
//     InitQueue(Q);
//     BTree p;
//     EnQueue(Q, T);
//     while (!QueueEmpty(Q)) {
//         DeQueue(Q, p);
//         putchar(p->c);
//         if (p->lchild)
//             EnQueue(Q, p->lchild);
//         if (p->rchild)
//             EnQueue(Q, p->rchild);
//     }
// }

void LevelOrder(BTree T) {
    LinkQueue Q;
    InitQueue(Q);

    BTree p;

    EnQueue(Q, T);

    while (!QueueEmpty(Q)) {
        DeQueue(Q, p);
        putchar(p->c);
        if (p->lchild) {
            // p = p->lchild;
            // EnQueue(Q, p);
            EnQueue(Q, p->lchild);
        }
        if (p->rchild) {
            // EnQueue(Q, p);
            // p = p->rchild;
            EnQueue(Q, p->rchild);
        }
    }
}

int main() {
    BTree pnew;
    BTree T = NULL;
    ptag_t phead = NULL, ptail = NULL, pcur = NULL, listpnew = NULL;

    BiElemType c;

    //����
    while (scanf("%c", &c) != EOF) {
        if (c == '\n')
            break;

        //���������
        pnew = (BTree)calloc(1, sizeof(BNode));
        pnew->c = c;

        //�������У�������Ϊ���������
        listpnew = (ptag_t)calloc(1, sizeof(tag_t));
        listpnew->p = pnew;

        if (NULL == T) {
            //�޸�ʱ�������
            T = pnew;

            phead = listpnew;
            ptail = listpnew;
            pcur = listpnew;

            continue;
            //��������ϣ�������ǰѭ��
            //��Ӻ�n-1�����
        } else {
            //�ȼ��븨������
            ptail->pnext = listpnew;
            //
            ptail = listpnew;
        }

        if (NULL == pcur->p->lchild)
            pcur->p->lchild = pnew;
        else if (NULL == pcur->p->rchild) {
            pcur->p->rchild = pnew;
            pcur = pcur->pnext;
        }
    }

    printf("\n--------ǰ�����----------\n");
    PreOrder(T);
    printf("\n--------�������----------\n");
    InOrder(T);
    printf("\n--------�������----------\n");
    PostOrder(T);
    printf("\n--------��������ǵݹ�----------\n");
    InOrder2(T);
    printf("\n--------��α���----------\n");
    LevelOrder(T);
}
