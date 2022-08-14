/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-08-11 20:01:29
 * @Description: 顺序查找
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int ElemType;
typedef struct {
    ElemType* elem;  //整形指针
    int TableLen;    //动态数组中的元素个数
} SSTable;
//一般线性表的顺序查找
int Search_Seq(SSTable ST, ElemType key) {
    ST.elem[0] = key;  //哨兵
    int i;
    for (i = ST.TableLen - 1; ST.elem[i] != key; --i)
        ;  //等于key时跳出
    return i;
}

//随机数生成
void ST_Init(SSTable& ST, int len) {
    ST.TableLen = len + 1;
    ST.elem = (ElemType*)malloc(sizeof(ElemType) * ST.TableLen);

    int i;
    srand(time(NULL));

    for (int i = 0; i < ST.TableLen; i++)
        ST.elem[i] = rand() % 100;
}

void ST_print(SSTable ST) {
    for (int i = 0; i < ST.TableLen; i++)
        printf("%3d", ST.elem[i]);
    printf("\n");
}

int main() {
    SSTable ST;
    ST_Init(ST, 10);
    ST_print(ST);

    ElemType key;
    printf("请输入要查找的key值：\n");
    scanf("%d", &key);

    int pos = Search_Seq(ST, key);

    if (pos)
        printf("查找成功，位置为：%d\n", pos);
    else
        printf("查找失败\n");

    printf("\n/////////折半查找，又称二分查找//////////////\n");
    printf("\n对随机数组进行快速排序后的结果：\n");
    qsort(ST.elem, ST.TableLen, sizeof(ElemType), compare);

}
