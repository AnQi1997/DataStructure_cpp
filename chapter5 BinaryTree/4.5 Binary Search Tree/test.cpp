/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-08-07 17:33:59
 * @Description: 二叉排序树
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
        return 1;  //插入成功
    } else if (k == T->key)
        return 0;
    else if (k < T->key)
        return BST_Insert(T->lchild, k);
    else
        return BST_Insert(T->rchild, k);
}

//创建二叉树
void Creat_BST(BiTree& T, KeyType str[], int n){
    T = NULL;
    int i = 0;
    while(i < n){
        BST_Insert(T, str[i]);
        i++;
    }
}

//查找结点
BSTNode* BST_Search(BiTree T, KeyType key, BiTree& p){
    p = NULL;
    while(T && key != T->key){
        p = T;
        if(key < T->key)
            T = T->lchild;
        else 
            T = T->rchild;
    }
    return T;
}

void InOrder(BiTree T){
    if(T){
        //递归不用while
        InOrder(T->lchild);
        printf("%3d", T->key);
        InOrder(T->rchild);
    }
}

//二叉树创建、遍历、查找、删除
int main() {
    BiTree T = NULL;
    BiTree parent;
    BiTree search;
    KeyType str[7] = {54, 20, 66, 40, 28, 79, 58};  //将要进入二叉排序树的元素值
    Creat_BST(T, str, 7);
    InOrder(T);
}
