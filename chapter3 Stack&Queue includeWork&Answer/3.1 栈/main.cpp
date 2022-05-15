#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef int ElemType;
typedef struct{
	ElemType data[MaxSize];//����
	int top;
}SqStack;
void InitStack(SqStack &S)
{
	S.top=-1;//����ջΪ��
}

bool StackEmpty(SqStack &S)
{
	if(S.top==-1)
		return true;
	else
		return false;
}
//��ջ
bool Push(SqStack &S,ElemType x)
{
	if(S.top==MaxSize-1)//����Ĵ�С���ܸı䣬�������Խ��
	{
		return false;
	}
	S.data[++S.top]=x;
	return true;
}
//��ջ
bool Pop(SqStack &S,ElemType &x)
{
	if(-1==S.top)
		return false;
	x=S.data[S.top--];//�������x=S.data[S.top];S.top=S.top-1;
	return true;
}
//��ȡջ��Ԫ��
bool GetTop(SqStack &S,ElemType &x)
{
	if(-1==S.top)//˵��ջΪ��
		return false;
	x=S.data[S.top];
	return true;
}
//������C��ѧӪ���γ�
//�������ݽṹ 3.1 ջ
//ʵ��ջ ���������飬Ҳ������������������ʹ������
int main()
{
	SqStack S;//�Ƚ���� FILO  LIFO
	bool flag;
	ElemType m;//��������ó���Ԫ��
	InitStack(S);//��ʼ��
	flag=StackEmpty(S);
	if(flag)
	{
		printf("ջ�ǿյ�\n");
	}
	Push(S,3);//��ջԪ��3
	Push(S,4);//��ջԪ��4
	Push(S,5);
	flag=GetTop(S,m);//��ȡջ��Ԫ��
	if(flag)
	{
		printf("��ȡջ��Ԫ��Ϊ %d\n",m);
	}
	flag=Pop(S,m);//����ջ��Ԫ��
	if(flag)
	{
		printf("����Ԫ��Ϊ %d\n",m);
	}
	system("pause");
}