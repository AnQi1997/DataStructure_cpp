#include <stdio.h>
#include <stdlib.h>

#define MaxSize 5
typedef int ElemType;
typedef struct {
	ElemType data[MaxSize];//����,�洢MaxSize-1��Ԫ��
	int front, rear;//����ͷ ����β
}SqQueue;

void InitQueue(SqQueue& Q)
{
	Q.front = Q.rear = 0;
}

bool isEmpty(SqQueue Q)
{
	if (Q.front == Q.rear)
	{
		return true;
	}
	return false;
}

bool EnQueue(SqQueue& Q,ElemType x)
{
	if ((Q.rear + 1) % MaxSize == Q.front)
	{
		return false;//��������
	}
	Q.data[Q.rear] = x;
	Q.rear = (Q.rear + 1) % MaxSize;//����ƶ�һ��
	return true;
}

bool DeQueue(SqQueue &Q, ElemType &x)
{
	if (Q.front == Q.rear)//����Ϊ��
	{
		return false;
	}
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MaxSize;
	return true;
}
int main()
{
	SqQueue Q;
	bool ret;//�洢����ֵ
	ElemType element;//�洢����Ԫ��
	InitQueue(Q);//��ʼ��ѭ������
	ret = isEmpty(Q);
	if (ret)
	{
		printf("����Ϊ��\n");
	}
	else {
		printf("���в�Ϊ��\n");
	}
	EnQueue(Q, 3);
	EnQueue(Q, 4);
	EnQueue(Q, 5);
	ret = EnQueue(Q, 6);
	ret = EnQueue(Q, 7);
	if (ret)
	{
		printf("��ӳɹ�\n");
	}
	else {
		printf("���ʧ��\n");
	}
	ret = DeQueue(Q, element);
	if (ret)
	{
		printf("���ӳɹ�,Ԫ��ֵΪ %d\n", element);
	}
	else {
		printf("����ʧ��\n");
	}
	ret = DeQueue(Q, element);
	if (ret)
	{
		printf("���ӳɹ�,Ԫ��ֵΪ %d\n", element);
	}
	else {
		printf("����ʧ��\n");
	}
	return 0;
}