#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int ElemType;
typedef struct{
	ElemType *elem;//����ָ��
	int TableLen;//�洢��̬�������Ԫ�صĸ���
}SSTable;

int Search_Seq(SSTable ST,ElemType key)
{
	ST.elem[0]=key;//�����Ԫ����Ϊ�ڱ�
	int i;
	for(i=ST.TableLen-1;ST.elem[i]!=key;--i);
	return i;
}
//init���������������
void ST_Init(SSTable &ST,int len)
{
	ST.TableLen=len+1;//��������һ��λ��,Ϊ�˴��ڱ�
	ST.elem=(ElemType *)malloc(sizeof(ElemType)*ST.TableLen);
	int i;
	srand(time(NULL));//���������
	for(i=0;i<ST.TableLen;i++)//Ϊɶ�������λ��Ҳ��������ݣ�Ϊ�۰���ҷ���
	{
		ST.elem[i]=rand()%100;
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
//ʱ�临�Ӷ�  logn
int Binary_Search(SSTable L,ElemType key)
{
	int low=0,high=L.TableLen-1,mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(L.elem[mid]==key)
			return mid;//���ھ��ҵ���
		else if(L.elem[mid]>key)
			high=mid-1;
		else
			low=mid+1;
	}
	return -1;
}
int compare(const void *left,const void *right)//left��right����������Ԫ�صĵ�ֵַ
{
	return *(ElemType*)left-*(ElemType*)right;
	//return *(ElemType*)right - *(ElemType*)left;//�Ӵ�С
}
//������C��ѧӪ���γ�
//˳����� ��  �۰����
int main()
{
	SSTable ST;
	ElemType key;
	int pos;//�洢��ѯԪ�ص�λ��
	ST_Init(ST,10);
	ST_print(ST);
	printf("������Ҫ������keyֵ:\n");
	scanf("%d",&key);
	pos=Search_Seq(ST,key);
	if(pos)
	{
		printf("���ҳɹ� λ��Ϊ %d\n",pos);
	}else{
		printf("����ʧ��\n");
	}
	qsort(ST.elem,ST.TableLen,sizeof(ElemType),compare);//qsortʵ�ֵ��ǿ���
	ST_print(ST);
	printf("���ֲ��ң�������Ҫ������keyֵ:\n");
	scanf("%d",&key);
	//��������
	pos=Binary_Search(ST,key);//���ֲ��ң�Ҳ���۰����
	if(pos!=-1)
	{
		printf("���ҳɹ� λ��Ϊ %d\n",pos);
	}else{
		printf("����ʧ��\n");
	}
	system("pause");
}
