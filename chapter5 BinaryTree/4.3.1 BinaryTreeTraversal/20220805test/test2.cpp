/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-08-05 14:44:46
 * @Description:
 */
#include "stdio.h"
#include "stdlib.h"

typedef struct node {
    int data;
    struct node *rchild, *lchild;
} node, *Node;

int aa(Node T) {
    //����ȥ�ľ���ָ�������ṹ���ָ�� ������->ֱ�ӵ��ó���
    //�������൱�������⺯�������ִ��˽ṹ��ֻ�ǰ����Ǵ���ȥ�����ݽ������滻
    printf("aa data=%d\n", T->data);
    T->data = 456;
    printf("aa�ı�� data=%d\n", T->data);
    Node* p;
    p = (Node*)malloc(sizeof(Node));
    *p = T;
    printf("T��ֵ��%p\n", T);
    printf("T�ĵ�ַ��%p\n", &T);
    printf("p��ֵ��%p\n", p);
    printf("p�ĵ�ַ��%p\n", &p);
    //	printf("aa�ı�� data=%d\n",*(*p)->data);
}

int bb(Node* T) {
    //��ʵ�����Ǹ�����ָ���ַ  Ҫ������*����һ����ܵõ��ṹ��ָ�� 	
    //�����ִ��ṹ��ָ��ĵ�ַ��ȥ�ģ������ִ�����һ������ָ�����洢��
    //����Ľṹ������������������Ǹ��ṹ��
    printf("bb data=%d\n", (*T)->data);
    (*T)->data = 789;  //��ΪT�ǵ�ַ����ָ�룬Ҫ��*�Ž���
    printf("bb�ı�� data=%d\n", (*T)->data);
    printf("T��ֵ��%p\n", T);     //��Ϊ�������ָ��ĵ�ַ������T��ֵ����������T�ĵ�ַ
    printf("T�ĵ�ַ��%p\n", &T);  //�����Ӻ����� ���Ľṹ�����������Ľṹ�岻ͬ�����Ե�ַ��ͬ
    printf("T������ĵ�ַ��%p\n", *T);
}

int main() {
    Node T = NULL;
    T = (Node)malloc(sizeof(node));
    T->data = 123;
    printf("T��ֵ��%p\n", T);
    printf("T�ĵ�ַ��%p\n", &T);
    printf("data=%d\n", T->data);

    printf("---------------------\n");

    aa(T);

    printf("aa�ı����main�� data=%d\n", T->data);

    printf("---------------------\n");

    bb(&T);

    printf("bb�ı����main�� data=%d\n", T->data);

    printf("---------------------\n");

    printf("main�����ս�� data=%d\n", T->data);
}