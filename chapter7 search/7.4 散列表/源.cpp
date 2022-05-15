#define MaxKey 1000
#include <stdio.h>
//����ǹ�ϣ����
int hash(const char* key)
{
	int h = 0, g;
	while (*key)
	{
		h = (h << 4) + *key++;
		g = h & 0xf0000000;
		if (g)
		{
			h ^= g >> 24;
		}
		h &= ~g;
	}
	return h % MaxKey;//����±�Ҫȡ��
}


int main()
{
	const char* pStr[5] = { "xiongda","lele","hanmeimei","wangdao","fenghua" };
	int i;
	const char* pHash_table[MaxKey] = {NULL};//��ϣ��ɢ�б�
	for (i = 0; i < 5; i++)
	{
		printf("%s is key=%d\n", pStr[i], hash(pStr[i]));//���ϣֵ����ӡ
		pHash_table[hash(pStr[i])] = pStr[i];//�����ϣ��
	}
	return 0;
}