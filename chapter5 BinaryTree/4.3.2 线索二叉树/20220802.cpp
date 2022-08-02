/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-08-02 19:56:20
 * @Description: 二叉树层次建树-抄写
 */
#include <stdio.h>
#include <stdlib.h>

typedef char BiElemType;
//二叉树结点的结构
typedef struct BiTNode {
    BiElemType c;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

//建树辅助队列的结构 tag：标签/紧随
typedef struct tag {
    BiTree p;           //某个二叉树结点的地址
    struct tag* pnext;  //存当前节点的下一个结点
} tag_t, *ptag_t;

void preOrder(BiTree p) {
    if(p != NULL){
        putchar(p->c);//等价于visit函数
        

    }
}

int main() {
    int i, j, pos;
    BiTree tree = NULL;  //树的根节点
    BiTree pTreeNew;     //要插入的树结点
    ptag_t pHead = NULL, pTail = NULL, listPNew = NULL, pCur = NULL;
    // phead：队列头结点
    // ptail：队列尾结点
    // listnew：队列未插入的新结点
    // pcur：要插入结点的父结点
    char c;  //要插入结点的数据域
    while (scanf("%d", &c) != EOF) {
        if (c == '\n')
            break;
        //申请空间
        pTreeNew = (BiTree)calloc(1, sizeof(BiTNode));
        //赋值
        pTreeNew->c = c;

        listPNew = (ptag_t)calloc(1, sizeof(tag_t));
        listPNew->p = pTreeNew;

        if (NULL == tree) {
            //树
            tree = pTreeNew;

            //队列
            pHead = listPNew;
            pTail = listPNew;
            pCur = listPNew;

            continue;
        } else {
            //尾插法插入辅助队列
            pTail->pnext = listPNew;
            pTail = listPNew;
        }

        //将结点插入树
        if (NULL == pCur->p->lchild)
            pCur->p->lchild = pTreeNew;
        else if (NULL == pCur->p->rchild) {
            pCur->p->rchild = pTreeNew;
            //当前结点的左右结点都放完了，指向下一个结点
            pCur = pCur->pnext;
        }
    }
}
