#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef int ElemType;
typedef struct {
	ElemType data[MaxSize];//����
	int top;
}SqStack;

void InitStack(SqStack &S)
{
	S.top = -1;//����ջΪ��
}

bool StackEmpty(SqStack S)
{
	if (-1 == S.top)
	{
		return true;
	}
	return false;
}
bool Push(SqStack& S, ElemType x)
{
	if (S.top == MaxSize - 1)
	{
		return false;//ջ����
	}
	S.data[++S.top] = x;
	return true;//����true������ջ�ɹ�
}
//��ȡջ��Ԫ��
bool GetTop(SqStack S, ElemType &x)
{
	if (StackEmpty(S))//ջΪ��
	{
		return false;
	}
	x = S.data[S.top];
	return true;
}
bool Pop(SqStack& S, ElemType& x)
{
	if (StackEmpty(S))//ջΪ��
	{
		return false;
	}
	x = S.data[S.top--];//�ȼ���x = S.data[S.top]������	S.top--;
	return true;
}
int main()
{
	SqStack S;
	bool flag;
	ElemType m;//�洢�ó�����ջ��Ԫ�ص�
	InitStack(S);//��ʼ��
	flag = StackEmpty(S);
	if (flag)
	{
		printf("ջ�ǿյ�\n");
	}
	Push(S, 3);//��ջԪ��3
	Push(S, 4);//��ջԪ��4
	Push(S, 5);
	flag = GetTop(S, m);//��ȡջ��Ԫ��,����S.topֵ����
	if (flag)
	{
		printf("��ȡջ��Ԫ��Ϊ %d\n", m);
	}
	flag = Pop(S, m);//����ջ��Ԫ��
	if (flag)
	{
		printf("����Ԫ��Ϊ %d\n", m);
	}
	return 0;
}