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
    //传进去的就是指向整个结构体的指针 可以用->直接调用出来
    //像这种相当于它在这函数里面又创了结构体只是把我们传进去的内容进行了替换
    printf("aa data=%d\n", T->data);
    T->data = 456;
    printf("aa改变后 data=%d\n", T->data);
    Node* p;
    p = (Node*)malloc(sizeof(Node));
    *p = T;
    printf("T的值是%p\n", T);
    printf("T的地址是%p\n", &T);
    printf("p的值是%p\n", p);
    printf("p的地址是%p\n", &p);
    //	printf("aa改变后 data=%d\n",*(*p)->data);
}

int bb(Node* T) {
    //其实定义是个二级指针地址  要把它用*解析一层才能得到结构体指针 	
    //像这种传结构体指针的地址进去的，它是又创建了一个二级指针来存储，
    //里面的结构体就是主函数创建的那个结构体
    printf("bb data=%d\n", (*T)->data);
    (*T)->data = 789;  //因为T是地址不是指针，要用*号解析
    printf("bb改变后 data=%d\n", (*T)->data);
    printf("T的值是%p\n", T);     //因为传入的是指针的地址，所以T的值就是主函数T的地址
    printf("T的地址是%p\n", &T);  //这是子函数里 另创的结构体与主函数的结构体不同，所以地址不同
    printf("T的里面的地址是%p\n", *T);
}

int main() {
    Node T = NULL;
    T = (Node)malloc(sizeof(node));
    T->data = 123;
    printf("T的值是%p\n", T);
    printf("T的地址是%p\n", &T);
    printf("data=%d\n", T->data);

    printf("---------------------\n");

    aa(T);

    printf("aa改变后在main中 data=%d\n", T->data);

    printf("---------------------\n");

    bb(&T);

    printf("bb改变后在main中 data=%d\n", T->data);

    printf("---------------------\n");

    printf("main中最终结果 data=%d\n", T->data);
}