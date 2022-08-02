/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-08-02 19:56:20
 * @Description: ��������ν���-��д
 */
#include <stdio.h>
#include <stdlib.h>

typedef char BiElemType;
//���������Ľṹ
typedef struct BiTNode {
    BiElemType c;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

//�����������еĽṹ tag����ǩ/����
typedef struct tag {
    BiTree p;           //ĳ�����������ĵ�ַ
    struct tag* pnext;  //�浱ǰ�ڵ����һ�����
} tag_t, *ptag_t;

void preOrder(BiTree p) {
    if(p != NULL){
        putchar(p->c);//�ȼ���visit����
        

    }
}

int main() {
    int i, j, pos;
    BiTree tree = NULL;  //���ĸ��ڵ�
    BiTree pTreeNew;     //Ҫ����������
    ptag_t pHead = NULL, pTail = NULL, listPNew = NULL, pCur = NULL;
    // phead������ͷ���
    // ptail������β���
    // listnew������δ������½��
    // pcur��Ҫ������ĸ����
    char c;  //Ҫ�������������
    while (scanf("%d", &c) != EOF) {
        if (c == '\n')
            break;
        //����ռ�
        pTreeNew = (BiTree)calloc(1, sizeof(BiTNode));
        //��ֵ
        pTreeNew->c = c;

        listPNew = (ptag_t)calloc(1, sizeof(tag_t));
        listPNew->p = pTreeNew;

        if (NULL == tree) {
            //��
            tree = pTreeNew;

            //����
            pHead = listPNew;
            pTail = listPNew;
            pCur = listPNew;

            continue;
        } else {
            //β�巨���븨������
            pTail->pnext = listPNew;
            pTail = listPNew;
        }

        //����������
        if (NULL == pCur->p->lchild)
            pCur->p->lchild = pTreeNew;
        else if (NULL == pCur->p->rchild) {
            pCur->p->rchild = pTreeNew;
            //��ǰ�������ҽ�㶼�����ˣ�ָ����һ�����
            pCur = pCur->pnext;
        }
    }
}
