#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//作者 王道训练营 龙哥
typedef char BiElemType;
typedef struct BiTNode {
	BiElemType c;//c就是书籍上的data
	struct BiTNode* lchild;
	struct BiTNode* rchild;
}BiTNode, * BiTree;

typedef struct tag {
	BiTree p;//树的某一个结点的地址值
	struct tag* pnext;
}tag_t, * ptag_t;

void preOrder(BiTree p)
{
	if (p != NULL)
	{
		putchar(p->c);//等价于visit函数
		preOrder(p->lchild);
		preOrder(p->rchild);
	}
}
int main()
{
	BiTree pnew;
	int i, j, pos;
	char c;
	BiTree tree = NULL;//树根
	ptag_t phead = NULL, ptail = NULL, listpnew = NULL, pcur = NULL;//phead就是队列头，ptail就是队列尾
	//abcdefghij
	while (scanf("%c", &c) != EOF)
	{
		if (c == '\n')
		{
			break;
		}
		pnew = (BiTree)calloc(1, sizeof(BiTNode));//calloc申请空间并对空间进行初始化，赋值为0
		pnew->c = c;//数据放进去
		listpnew = (ptag_t)calloc(1, sizeof(tag_t));//给队列结点申请空间
		listpnew->p = pnew;
		if (NULL == tree)
		{
			tree = pnew;//树的根
			phead = listpnew;//队列头
			ptail = listpnew;//队列尾
			pcur = listpnew;
			continue;
		}
		else {
			ptail->pnext = listpnew;//新结点放入链表，通过尾插法
			ptail = listpnew;//ptail指向队列尾部
		}//pcur始终指向要插入的结点的位置
		if (NULL == pcur->p->lchild)//如何把新结点放入树
		{
			pcur->p->lchild = pnew;//把新结点放到要插入结点的左边
		}
		else if (NULL == pcur->p->rchild)
		{
			pcur->p->rchild = pnew;//把新结点放到要插入结点的右边
			pcur = pcur->pnext;//左右都放了结点后，pcur指向队列的下一个
		}
	}
	preOrder(tree);
	return 0;
}