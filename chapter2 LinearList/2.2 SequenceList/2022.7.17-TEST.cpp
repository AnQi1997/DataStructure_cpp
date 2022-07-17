/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-07-17 19:37:30
 * @Description: ˳���
 */
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50

typedef int ElemType;

//��̬����
typedef struct {
    ElemType data[MaxSize];
    int length;
} SqList;

//��̬����
#define InitSize 100
typedef struct {
    ElemType* data;
    int capacity;
    int length;
} SeqList;

void PrintList(SqList L) {
    for (int i = 0; i < L.length; i++) {
        printf("%3d");
    }
    printf("\n");
}

//��˳���L�ĵ�i��λ�ò�����Ԫ��e����i�����벻�Ϸ���
// �򷵻�false����ʾ����ʧ�ܡ�
//���򣬽���i��Ԫ�ؼ���������Ԫ�����������ƶ�һ��λ�ã�
// �ڳ�һ����λ�ò�����Ԫ��e
//˳���������1������ɹ�������true��
bool ListInsert(SqList& L, int i, ElemType e) {
    if (i < 1 || i > L.length + 1)
        return false;
    if (L.length >= MaxSize)  //�������޶��ռ�
        return false;
    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;  
}

//ɾ��˳���L�е�i��1 <= i <= L.length����λ�õ�Ԫ��
//�����ñ���e���ء���i�����벻�Ϸ����򷵻�false������
//����ɾ��Ԫ�ظ�ֵ�����ñ���e��
//����i+1��Ԫ�ؼ���֮�������Ԫ��������ǰ�ƶ�һ��λ�ã�
// ����true


int main() {
}
