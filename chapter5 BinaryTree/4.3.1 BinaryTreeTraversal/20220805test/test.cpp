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

//中序遍历非递归
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
    //栈
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

    //建树
    while (scanf("%c", &c) != EOF) {
        if (c == '\n')
            break;

        //二叉树结点
        pnew = (BTree)calloc(1, sizeof(BNode));
        pnew->c = c;

        //辅助队列，数据域为二叉树结点
        listpnew = (ptag_t)calloc(1, sizeof(tag_t));
        listpnew->p = pnew;

        if (NULL == T) {
            //无根时，插入根
            T = pnew;

            phead = listpnew;
            ptail = listpnew;
            pcur = listpnew;

            continue;
            //建树根完毕，结束当前循环
            //添加后n-1个结点
        } else {
            //先加入辅助队列
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

    printf("\n--------前序遍历----------\n");
    PreOrder(T);
    printf("\n--------中序遍历----------\n");
    InOrder(T);
    printf("\n--------后序遍历----------\n");
    PostOrder(T);
    printf("\n--------中序遍历非递归----------\n");
    InOrder2(T);
    printf("\n--------层次遍历----------\n");
    LevelOrder(T);
}
