/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-08-03 18:57:47
 * @Description: 二叉树的遍历
 */
#include "function.h"

//先序
void PreOrder(BiTree T) {
    if (T) {
        putchar(T->c);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}
//中序
void InOrder(BiTree T) {
    if (T) {
        InOrder(T->lchild);
        putchar(T->c);
        InOrder(T->rchild);
    }
}
//后序
void PostOrder(BiTree T) {
    if (T) {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        putchar(T->c);
    }
}

//中序遍历非递归  借助栈
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

//层次遍历
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
    // 层次建树
    BiTree tree = NULL;
    ptag_t phead = NULL, ptail = NULL, listpnew = NULL, pcur = NULL;
    BiTree pnew;

    char c;
    while (scanf("%c", &c) != EOF) {
        //输入时结束的标志
        if (c == '\n')
            break;
        //二叉树结点
        pnew = (BiTree)calloc(1, sizeof(BiTNode));
        pnew->c = c;

        //辅助队列结点
        listpnew = (ptag_t)calloc(1, sizeof(tag_t));
        listpnew->p = pnew;

        //建立辅助队列
        if (NULL == tree) {
            tree = pnew;
            phead = listpnew;
            ptail = listpnew;
            pcur = listpnew;
            continue;
        } else {
            //如果树不空，用尾插法先放入辅助队列，对
            ptail->pnext = listpnew;
            ptail = listpnew;
        }

        //建立二叉树
        if (NULL == pcur->p->lchild)
            //新结点赋给左结点
            pcur->p->lchild = pnew;
        else if (NULL == pcur->p->rchild) {
            //新结点赋给右节点
            pcur->p->rchild = pnew;
            pcur = pcur->pnext;
        }
    }

    printf("\n------先序遍历------\n");
    PreOrder(tree);
    printf("\n------中序遍历------\n");
    InOrder(tree);
    printf("\n------后序遍历------\n");
    PostOrder(tree);
    printf("\n------中序遍历非递归------\n");
    InOrder2(tree);
    printf("\n------层次遍历------\n");
    LevelOrder(tree);
    printf("\n");
}
