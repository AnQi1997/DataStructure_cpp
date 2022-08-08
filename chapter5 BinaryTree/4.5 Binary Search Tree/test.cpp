/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-08-07 17:33:59
 * @Description: ����������
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
        return 1;  //����ɹ�
    } else if (k == T->key)
        return 0;
    else if (k < T->key)
        return BST_Insert(T->lchild, k);
    else
        return BST_Insert(T->rchild, k);
}

//����������
void Creat_BST(BiTree& T, KeyType str[], int n){
    T = NULL;
    int i = 0;
    while(i < n){
        BST_Insert(T, str[i]);
        i++;
    }
}

//���ҽ��
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
        //�ݹ鲻��while
        InOrder(T->lchild);
        printf("%3d", T->key);
        InOrder(T->rchild);
    }
}

//���������������������ҡ�ɾ��
int main() {
    BiTree T = NULL;
    BiTree parent;
    BiTree search;
    KeyType str[7] = {54, 20, 66, 40, 28, 79, 58};  //��Ҫ���������������Ԫ��ֵ
    Creat_BST(T, str, 7);
    InOrder(T);
}
