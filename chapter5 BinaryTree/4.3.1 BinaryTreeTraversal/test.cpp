/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-09-27 21:35:07
 * @Description: 
 */
#include "function.h"

/*�ݹ�ʵ��*/
//�������
void PreOrder(BiTree p) {
    if (p) {
        putchar(p->c);
        PreOrder(p->lchild);
        PreOrder(p->rchild);
    }
}

//�������
void InOrder(BiTree p) {
    if (p) {
        InOrder(p->lchild);
        putchar(p->c);
        InOrder(p->rchild);
    }
}

//�������
void PostOrder(BiTree p) {
    if (p) {
        PostOrder(p->lchild);
        PostOrder(p->rchild);
        putchar(p->c);
    }
}

//��������ǵݹ�
void InOrder2(BiTree T) {
    SqStack S;
    InitStack(S);

    BiTree p = T;  //����ָ��

    //�������Ҹ���ջ����
    while (p || !StackEmpty(S)) {
        //���pָ��Ľ�㲻��
        if (p) {
            Push(S, p);
            //ָ������
            p = p->lchild;  //��
        } else {
            //���pָ��NULL����ջ����ɱ����ý��
            Pop(S, p);
            putchar(p->c);  //��
            p = p->rchild;  //��
        }
    }
}

//��α��� ������� ������ȱ���
void levelOrder(BiTree T) {
    LinkQueue Q;   //��������
    InitQueue(Q);  //��ʼ������

    BiTree p;  //����ָ�룬���ճ��ӽ��

    EnQueue(Q, T);  //�������

    while (!IsEmpty(Q)) {
        //���в����н��ʱ�����ӽ��
        DeQueue(Q, p);
        //���ʽ�㣬��ĳ���������
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
    BiTree pnew;  //���������

    while (scanf("%c", &c) != EOF) {
        //ɶҲ������
        if (c == '\n')
            break;
        //���������o
        pnew = (BiTree)calloc(1, sizeof(BiTNode));
        pnew->c = c;
        //�������н��
        listpnew = (ptag_t)calloc(1, sizeof(tag_t));
        listpnew->p = pnew;

        if (NULL == tree) {
            //��Ϊ��
            tree = pnew;       //�����¶����������Ϊ��
            phead = listpnew;  //������ͷ
            ptail = listpnew;  //������β
            pcur = listpnew;
            //ָ��ǰҪ�����ĸ�������Ԫ��
            //��Ԫ�ذ�������������������ĵĵ�ַ
            continue;
        } else {
            //��������գ�β�巨�������븨������
            ptail->pnext = listpnew;
            ptail = listpnew;
        }

        //��β��������
        if (NULL == pcur->p->lchild)
            pcur->p->lchild = pnew;
        else if (NULL == pcur->p->rchild) {
            pcur->p->rchild = pnew;
            pcur = pcur->pnext;
        }
    }

    printf("\n--------ǰ�����------------\n");
    PreOrder(tree);

    printf("\n--------�������------------\n");
    InOrder(tree);

    printf("\n--------�������------------\n");
    PostOrder(tree);

    printf("\n--------��������ǵݹ�------------\n");
    InOrder2(tree);

    printf("\n--------�������------------\n");
    levelOrder(tree);
}