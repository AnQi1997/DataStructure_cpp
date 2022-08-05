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
        // p不空或者栈不空时执行此循环
        //! StackEmpty(S)
        //栈不空时，返回false，取反为true
        //栈空时，返回true，取反为false，不执行
        if (p) {
            //往左走一直压栈
            Push(S, p);
            p = p->lchild;
        } else {
            //至最左后，弹栈
            Pop(S, p);
            // putchar(p->c);
            putchar(p->c);
            //访问p结点的右子树1
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
        //队空，返回true，取反位false，不执行此循环
        //队中有元素，返回false，取反为true，执行此循环
        DeQueue(Q, p);
        putchar(p->c);
        //边出边进p结点的左右孩子
        if (p->lchild != NULL)
            EnQueue(Q, p->lchild);
        if (p->rchild != NULL)
            EnQueue(Q, p->rchild);
    }
}

int main() {
    //层次建树
    BiTree tree = NULL;
    BiTree pnew;  //待插入的新结点
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

            continue;  //结束这一层循环
            // break；结束整个循环
        } else {
            //树如果不空，放入辅助队列
            ptail->pnext = listpnew;
            ptail = listpnew;
        }

        //建树
        if (NULL == pcur->p->lchild)
            pcur->p->lchild = pnew;
        else if (NULL == pcur->p->rchild) {
            pcur->p->rchild = pnew;
            pcur = pcur->pnext;
        }
    }

    printf("\n--------先序遍历----------\n");  //也叫先序遍历，先打印当前结点，打印左孩子，打印右孩子
    PreOrder(tree);

    printf("\n--------中序遍历----------\n");
    InOrder(tree);

    printf("\n--------后序遍历----------\n");
    PostOrder(tree);

    printf("\n--------中序遍历非递归----------\n");
    InOrder2(tree);

    printf("\n--------层次遍历----------\n");
    LevelOrder(tree);
}
