/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-09-27 21:35:07
 * @Description: 
 */
#include "function.h"

/*递归实现*/
//先序遍历
void PreOrder(BiTree p) {
    if (p) {
        putchar(p->c);
        PreOrder(p->lchild);
        PreOrder(p->rchild);
    }
}

//中序遍历
void InOrder(BiTree p) {
    if (p) {
        InOrder(p->lchild);
        putchar(p->c);
        InOrder(p->rchild);
    }
}

//后序遍历
void PostOrder(BiTree p) {
    if (p) {
        PostOrder(p->lchild);
        PostOrder(p->rchild);
        putchar(p->c);
    }
}

//中序遍历非递归
void InOrder2(BiTree T) {
    SqStack S;
    InitStack(S);

    BiTree p = T;  //工具指针

    //树不空且辅助栈不空
    while (p || !StackEmpty(S)) {
        //如果p指向的结点不空
        if (p) {
            Push(S, p);
            //指向左孩子
            p = p->lchild;  //左
        } else {
            //如果p指向NULL，弹栈，完成遍历该结点
            Pop(S, p);
            putchar(p->c);  //中
            p = p->rchild;  //右
        }
    }
}

//层次遍历 层序遍历 广度优先遍历
void levelOrder(BiTree T) {
    LinkQueue Q;   //辅助队列
    InitQueue(Q);  //初始化队列

    BiTree p;  //工具指针，接收出队结点

    EnQueue(Q, T);  //树根入队

    while (!IsEmpty(Q)) {
        //队列不空有结点时，出队结点
        DeQueue(Q, p);
        //访问结点，即某二叉树结点
        putchar(p->c);

        if (p->lchild != NULL)
            EnQueue(Q, p->lchild);
        if (p->rchild != NULL)
            EnQueue(Q, p->rchild);
    }
}

int main() {
    int i, j, pos;
    char c;

    BiTree tree = NULL;
    ptag_t phead = NULL, ptail = NULL, listpnew = NULL, pcur = NULL;
    BiTree pnew;  //二叉树结点

    while (scanf("%c", &c) != EOF) {
        //啥也不输入
        if (c == '\n')
            break;
        //二叉树结点o
        pnew = (BiTree)calloc(1, sizeof(BiTNode));
        pnew->c = c;
        //辅助队列结点
        listpnew = (ptag_t)calloc(1, sizeof(tag_t));
        listpnew->p = pnew;

        if (NULL == tree) {
            //树为空
            tree = pnew;       //插入新二叉树结点作为根
            phead = listpnew;  //辅助队头
            ptail = listpnew;  //辅助队尾
            pcur = listpnew;
            //指向当前要操作的辅助队列元素
            //该元素包含待插入二叉树父结点的的地址
            continue;
        } else {
            //如果树不空，尾插法将结点放入辅助队列
            ptail->pnext = listpnew;
            ptail = listpnew;
        }

        //如何插入二叉树
        if (NULL == pcur->p->lchild)
            pcur->p->lchild = pnew;
        else if (NULL == pcur->p->rchild) {
            pcur->p->rchild = pnew;
            pcur = pcur->pnext;
        }
    }

    printf("\n--------前序遍历------------\n");
    PreOrder(tree);

    printf("\n--------中序遍历------------\n");
    InOrder(tree);

    printf("\n--------后序遍历------------\n");
    PostOrder(tree);

    printf("\n--------中序遍历非递归------------\n");
    InOrder2(tree);

    printf("\n--------层序遍历------------\n");
    levelOrder(tree);
}