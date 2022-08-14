/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-08-11 20:01:29
 * @Description: ˳�����
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int ElemType;
typedef struct {
    ElemType* elem;  //����ָ��
    int TableLen;    //��̬�����е�Ԫ�ظ���
} SSTable;
//һ�����Ա��˳�����
int Search_Seq(SSTable ST, ElemType key) {
    ST.elem[0] = key;  //�ڱ�
    int i;
    for (i = ST.TableLen - 1; ST.elem[i] != key; --i)
        ;  //����keyʱ����
    return i;
}

//���������
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
    printf("������Ҫ���ҵ�keyֵ��\n");
    scanf("%d", &key);

    int pos = Search_Seq(ST, key);

    if (pos)
        printf("���ҳɹ���λ��Ϊ��%d\n", pos);
    else
        printf("����ʧ��\n");

    printf("\n/////////�۰���ң��ֳƶ��ֲ���//////////////\n");
    printf("\n�����������п��������Ľ����\n");
    qsort(ST.elem, ST.TableLen, sizeof(ElemType), compare);

}
