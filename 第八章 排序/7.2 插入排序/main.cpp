#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef int ElemType;
typedef struct{
	ElemType *elem;//����ָ��
	int TableLen;
}SSTable;

void ST_Init(SSTable &ST,int len)
{
	ST.TableLen=len+1;//ʵ������11��Ԫ�صĿռ�
	ST.elem=(ElemType *)malloc(sizeof(ElemType)*ST.TableLen);
	int i;
	srand(time(NULL));
	for(i=0;i<ST.TableLen;i++)
	{
		ST.elem[i]=rand()%100;//�����11���������ǵ�һ��Ԫ����û���õ���
	}
}
void ST_print(SSTable ST)
{
	for(int i=0;i<ST.TableLen;i++)
	{
		printf("%3d",ST.elem[i]);
	}
	printf("\n");
}
//�������򣬴�С������������
void InsertSort(ElemType A[],int n)
{
	int i,j;
	//24 66 94  2 15 74 28 51 22 18  2
	for(i=2;i<=n;i++)//�����Ԫ�����ڱ����ӵڶ���Ԫ�ؿ�ʼ�ã���ǰ�����
	{
		if(A[i]<A[i-1])
		{
			A[0]=A[i];//�ŵ��ݴ�λ�ã�A[0]�����ݴ棬Ҳ���ڱ�
			for(j=i-1;A[0]<A[j];--j)//�ƶ�Ԫ�أ��ڲ�ѭ���������������е�ÿһ��Ԫ�غ�Ҫ�����Ԫ�رȽ�
				A[j+1]=A[j];
			A[j+1]=A[0];//���ݴ�Ԫ�ز��뵽��Ӧλ��
		}
	}
}
//�۰���� �������򣬿��ĺ���
void MidInsertSort(ElemType A[],int n)
{
	int i,j,low,high,mid;
	for(i=2;i<=n;i++)
	{
		A[0]=A[i];
		low=1;high=i-1;//low�������еĿ�ʼ��high�������е����
		while(low<=high)//��ͨ�����ֲ����ҵ�������λ��
		{
			mid=(low+high)/2;
			if(A[mid]>A[0])
				high=mid-1;
			else
				low=mid+1;
		}
		for(j=i-1;j>=high+1;--j)
			A[j+1]=A[j];
		A[high+1]=A[0];
	}
}
//ϣ������  
//���ֲ������򣬿�����ĸ���Լ�����㣬��Ϊ��д�������ӣ�ͬʱЧ�ʲ�������ţ�����
//С����Ҫ�������ı仯����ε�
void ShellSort(ElemType A[],int n)
{
	int dk,i,j;
	// 73 29 74 51 29 90 37 48 72 54 83
	for(dk=n/2;dk>=1;dk=dk/2)//�����仯�������仯
	{
		for(i=dk+1;i<=n;++i)//��dkΪ�������в�������
		{
			if(A[i]<A[i-dk])
			{
				A[0]=A[i];
				for(j=i-dk;j>0&&A[0]<A[j];j=j-dk)
					A[j+dk]=A[j];
				A[j+dk]=A[0];
			}
		}
	}
}

//������C��ѧӪ��
int main()
{
	SSTable ST;
	ElemType A[10] = { 64, 94, 95, 79, 69, 84, 18, 22, 12 ,78 };
	ST_Init(ST,10);//ʵ��������11��Ԫ�ؿռ�
	memcpy(ST.elem+1, A, sizeof(A));
	ST_print(ST);
	//InsertSort(ST.elem,10);
	//MidInsertSort(ST.elem,10);
	ShellSort(ST.elem,10);
	ST_print(ST);
	system("pause");
}