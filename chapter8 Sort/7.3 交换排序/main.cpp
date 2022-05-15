#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef int ElemType;
typedef struct{
	ElemType *elem;//�洢Ԫ�ص���ʼ��ַ
	int TableLen;//Ԫ�ظ���
}SSTable;

void ST_Init(SSTable &ST,int len)
{
	ST.TableLen=len;
	ST.elem=(ElemType *)malloc(sizeof(ElemType)*ST.TableLen);
	int i;
	srand(time(NULL));//��������ɣ�ÿһ��ִ�д���ͻ�õ������10��Ԫ��
	for(i=0;i<ST.TableLen;i++)
	{
		ST.elem[i]=rand()%100;//���ɵ���0-99֮��
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
void swap(ElemType &a,ElemType &b)
{
	ElemType tmp;
	tmp=a;
	a=b;
	b=tmp;
}
// 64 94 95 79 69 84 18 22 12 78
// 12 64 94 95 79 69 84 18 22 78
void BubbleSort(ElemType A[],int n)
{
	int i,j;
	bool flag;
	for(i=0;i<n-1;i++)//i�����ʵ�8
	{
		flag=false;
		for(j=n-1;j>i;j--)//����Сֵ�ͷ�����ǰ��
		{
			if(A[j-1]>A[j])
			{
				swap(A[j-1],A[j]);
				flag=true;
			}
		}
		if(false==flag)
			return;
	}
}

void BubbleSort1(ElemType A[], int n)
{
	int i, j,flag;
	for (i=0;i<n-1;i++)//i�ǿ����ж��ٸ�������
	{
		flag = 0;
		for (j = n-1; j>i;j--)//�ڲ���ƱȽϣ�����
		{
			if (A[j - 1] > A[j])
			{
				swap(A[j - 1], A[j]);
				flag = 1;
			}
		}
		if (0 == flag)
		{
			break;
		}
	}
}
// 64 94 95 79 69 84 18 22 12 78
//��64С�ķ�����ߣ���64��ķ����ұ�
// �ڿӷ�����������ʹ�õķ������������Ϊ�ָ�ֵ
int Partition(ElemType A[],int low,int high)
{
	ElemType pivot=A[low];//������ߵ�ֵ�ݴ�����
	while(low<high)
	{
		while(low<high&&A[high]>=pivot)//��high�����ұ��ң��ҵ��ȷָ�ֵС��ѭ������
			--high;
		A[low]=A[high];
		while(low<high&&A[low]<=pivot)//��low������߿�ʼ�ң��ҵ��ȷָ�ֵ�󣬾ͽ���
			++low;
		A[high]=A[low];
	}
	A[low]=pivot;
	return low;
}
//������
int Partition1(int* arr, int left, int right)
{
	int k, i;//k��¼Ҫ����ȷָ�ֵС�����ݵ�λ��
	for (i = left, k = left; i < right; i++)
	{
		if (arr[i] < arr[right])
		{
			swap(arr[k], arr[i]);
			k++;
		}
	}
	swap(arr[k], arr[right]);
	return k;
}
//������
int Partition2(int* arr, int left, int right)
{
	int k, i;
	for (k = i = left;i<right;i++)
	{
		if (arr[i] < arr[right])
		{
			swap(arr[i], arr[k]);
			k++;
		}
	}
	swap(arr[k], arr[right]);
	return k;
}
//�ݹ�ʵ��
void QuickSort(ElemType A[],int low,int high)
{
	if(low<high)
	{
		int pivotpos=Partition(A,low,high);//�ָ����ߵ�Ԫ�ض��ȷָ��ҪС���ұߵıȷָ���
		QuickSort(A,low,pivotpos-1);
		QuickSort(A,pivotpos+1,high);
	}
}
//������C��ѧӪ���γ�
//ð���������������
int main()
{
	SSTable ST;
	ElemType A[10]={ 64, 94, 95, 79, 69, 84, 18, 22, 12 ,78};
	ST_Init(ST,10);//��ʼ��
	memcpy(ST.elem,A,sizeof(A));//�ڴ�copy�ӿڣ�����copy�������飬���߸�����ʱ��Ҫ��memcpy
	ST_print(ST);
	//BubbleSort1(ST.elem,10);//ð������
	QuickSort(ST.elem,0,9);
	ST_print(ST);
	system("pause");
}