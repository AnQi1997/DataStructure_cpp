#include <stdio.h>
#include <stdlib.h>
//Fib�ǵݹ麯��
int Fib(int n)
{
	if(n==0)
		return 0;
	else if(n==1)
		return 1;
	else
		return Fib(n-1)+Fib(n-2);
}
//�������ݽṹ 쳲���������
//�ݹ�  ������������
//0  1  1  2  3   5 
//f(n)=f(n-1)+f(n-2)
//���в��Ǻ���Ҫ���˽⼴��

int main()
{
	int num;
	while(scanf("%d",&num)!=EOF)
	{
		printf("Fib(%d) = %d\n",num,Fib(num));
	}
	system("pause");
}
//��Ŀ  n��̨�ף�ÿ��ֻ����1��̨�ף�����2��̨�ף�n��̨�ף��ж������߷�