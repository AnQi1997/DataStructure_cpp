/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-08-10 20:29:59
 * @Description: 二叉搜索树（自己写）
 */
#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
typedef struct BSTNode {
    KeyType k;
    struct BSTNode *lchild, *rchild;
} BSTNode, *BiTree;

//插入
int BST_Insert(BiTree& T, KeyType key) {
    if (NULL == T) {
        T = (BiTree)malloc(sizeof(BSTNode));
        T->k = key;
        T->lchild = T->rchild = NULL;
        return 1;
    } else if (key == T->k) {
        return 0;
    } else if (key < T->k)
        return BST_Insert(T->lchild, key);
    else
        return BST_Insert(T->rchild, key);
}

//建树
void Creat_BST(BiTree& T, KeyType str[], int n) {
    T = NULL;
    int i;
    while (i < n) {
        BST_Insert(T, str[i]);
        i++;
    }
}

void InOrder(BiTree T) {
    if (T) {
        InOrder(T->lchild);
        printf("%5d", T->k);
        InOrder(T->rchild);
    }
}

int main() {
    BiTree T;
    KeyType str[] = {30, 11, 23, 24, 35};
    Creat_BST(T, str, 5);
    InOrder(T);
}
