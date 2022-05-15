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
	{	//Ϊ�½ڵ�����ռ䣬��һ�������Ϊ����
		T = (BiTree)malloc(sizeof(BSTNode));
		T->key = k;
		T->lchild = T->rchild = NULL;
		return 1;//�������ɹ�
	}
	else if (k == T->key)
		return 0;//������ͬԪ�أ��Ͳ�����
	else if (k < T->key)//���Ҫ����Ľ�㣬С�ڵ�ǰ���
		return BST_Insert(T->lchild, k);//�������ý��������Ӻ�ԭ���ĸ��׻��������
	else
		return BST_Insert(T->rchild, k);
}
//��������������
void Creat_BST(BiTree& T, KeyType str[], int n)
{
	T = NULL;
	int i = 0;
	while (i < n)
	{
		BST_Insert(T, str[i]);//��ĳһ����������������
		i++;
	}
}


//pos������뵽�ڼ���λ��
void InOrder(BiTree T, KeyType str[],int &pos)
{
	if (T != NULL)
	{
		InOrder(T->lchild,str,pos);
		printf("%3d", T->key);
		str[pos++] = T->key;//�����ͬʱ���뵽����
		InOrder(T->rchild,str,pos);
	}
}

typedef int ElemType;
typedef struct {
	ElemType* elem;//����ָ��
	int TableLen;//�洢��̬�������Ԫ�صĸ���
}SSTable;
int Binary_Search(SSTable L, ElemType key)
{
	int low = 0, high = L.TableLen - 1, mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (L.elem[mid] == key)
			return mid;//���ھ��ҵ���
		else if (L.elem[mid] > key)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}
//������C��ѧӪ���γ�
//�����������Ĵ�����������������ң�ɾ��
int main()
{
	BiTree T = NULL;//����
	BiTree parent;//�洢���׽��ĵ�ֵַ
	BiTree search;
	KeyType str[10];//��Ҫ���������������Ԫ��ֵ
	int i;
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &str[i]);
	}
	Creat_BST(T, str, 10);
	int pos=0;
	InOrder(T,str,pos);//�������������Ľ������str������
	printf("\n");
	SSTable L;
	L.elem = str;//��˳���ָ��ָ������
	L.TableLen = 10;
	pos=Binary_Search(L, 21);
	printf("%d\n", pos);
	return 0;
}