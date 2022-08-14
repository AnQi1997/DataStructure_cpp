/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-08-10 20:10:17
 * @Description:
 */
#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
typedef struct BSTNode {
    KeyType key;
    struct BSTNode *lchild, *rchild;
} BSTNode, *BiTree;

int BST_Insert(BiTree& T, KeyType k) {
    if (NULL == T) {
        T = (BiTree)malloc(sizeof(BSTNode));
        T->key = k;
        T->lchild = T->rchild = NULL;
        return 1;  //代表插入成功
    } else if (k == T->key)
        return 0;
    else if (k < T->key)
        return BST_Insert(T->lchild, k);
    else
        return BST_Insert(T->rchild, k);
}

//创建二叉树
void Creat_BST(BiTree& T, KeyType str[], int n) {
    T = NULL;
    int i = 0;
    while (i < n) {
        BST_Insert(T, str[i]);
        i++;
    }
}

BSTNode* BSTSearch(BiTree T, KeyType key) {
    while (T && key != T->key) {
        if (key < T->key)
            T = T->lchild;
        else
            T = T->rchild;
    }
    return T;
}

void InOrder(BiTree T) {
    if (T) {
        InOrder(T->lchild);
        printf("%5d", T->key);
        InOrder(T->rchild);
    }
}

int main() {
    BiTree T;
    KeyType str[] = {30, 11, 23, 22, 35, 24};
    Creat_BST(T, str, 6);
    InOrder(T);

}
