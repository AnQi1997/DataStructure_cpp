#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef int KeyType;
typedef struct BSTNode {
	KeyType key;
	struct BSTNode* lchild, * rchild;
}BSTNode, * BiTree;
//54,20,66,40,28,79,58
int BST_Insert(BiTree& T, KeyType k)
{
	if (NULL == T)
	{	//为新节点申请空间，第一个结点作为树根
		T = (BiTree)malloc(sizeof(BSTNode));
		T->key = k;
		T->lchild = T->rchild = NULL;
		return 1;//代表插入成功
	}
	else if (k == T->key)
		return 0;//发现相同元素，就不插入
	else if (k < T->key)//如果要插入的结点，小于当前结点
		return BST_Insert(T->lchild, k);//函数调用结束后，左孩子和原来的父亲会关联起来
	else
		return BST_Insert(T->rchild, k);
}
//创建二叉排序树
void Creat_BST(BiTree& T, KeyType str[], int n)
{
	T = NULL;
	int i = 0;
	while (i < n)
	{
		BST_Insert(T, str[i]);//把某一个结点放入二叉查找树
		i++;
	}
}


//pos代表存入到第几个位置
void InOrder(BiTree T, KeyType str[],int &pos)
{
	if (T != NULL)
	{
		InOrder(T->lchild,str,pos);
		printf("%3d", T->key);
		str[pos++] = T->key;//输出的同时存入到数组
		InOrder(T->rchild,str,pos);
	}
}

typedef int ElemType;
typedef struct {
	ElemType* elem;//整型指针
	int TableLen;//存储动态数组里边元素的个数
}SSTable;
int Binary_Search(SSTable L, ElemType key)
{
	int low = 0, high = L.TableLen - 1, mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (L.elem[mid] == key)
			return mid;//等于就找到了
		else if (L.elem[mid] > key)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}
//《王道C督学营》课程
//二叉排序树的创建，中序遍历，查找，删除
int main()
{
	BiTree T = NULL;//树根
	BiTree parent;//存储父亲结点的地址值
	BiTree search;
	KeyType str[10];//将要进入二叉排序树的元素值
	int i;
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &str[i]);
	}
	Creat_BST(T, str, 10);
	int pos=0;
	InOrder(T,str,pos);//中序遍历把有序的结果存入str数组中
	printf("\n");
	SSTable L;
	L.elem = str;//让顺序表指针指向数组
	L.TableLen = 10;
	pos=Binary_Search(L, 21);
	printf("%d\n", pos);
	return 0;
}