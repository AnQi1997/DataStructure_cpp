#define MaxKey 1000
#include <stdio.h>
//这就是哈希函数
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
	return h % MaxKey;//算出下标要取余
}


int main()
{
	const char* pStr[5] = { "xiongda","lele","hanmeimei","wangdao","fenghua" };
	int i;
	const char* pHash_table[MaxKey] = {NULL};//哈希表，散列表
	for (i = 0; i < 5; i++)
	{
		printf("%s is key=%d\n", pStr[i], hash(pStr[i]));//算哈希值并打印
		pHash_table[hash(pStr[i])] = pStr[i];//存入哈希表
	}
	return 0;
}