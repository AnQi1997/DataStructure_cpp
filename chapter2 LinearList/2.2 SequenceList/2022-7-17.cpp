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
        printf("%3d", L.data[i]);
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
// ����t
bool ListDelete(SqList& L, int i, ElemType& e) {
    if (i < 1 || i > L.length)
        return false;
    e = L.data[i - 1];
    for (int j = i; j < L.length; j++) {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
}

//����Ԫ��
//��ֵ���ң���˳���L�в��ҵ�һ��Ԫ�ص���e��Ԫ�أ���������λ��
// bool LocateElem(SqList L, ElemType e) {
//     // if (L.length == 0)
//     //     return false;
//     int i;
//     for (i = 0; i < L.length; i++) {
//         if (L.data[i] == e)
//             printf("λ��%d\n", i);
//         return true;
//     }
// }

int LocateElem(SqList L, ElemType e) {
    int i;
    for (i = 0; i < L.length; i++) {
        if (L.data[i] == e)
            return i + 1;
    }
    return 0;
}

int main() {
    SqList L = {1, 2, 3, 4, 5};
    L.length = 5;
    PrintList(L);

    //�������
    ListInsert(L, 1, 10);
    PrintList(L);

    //ɾ������
    ElemType e;
    ListDelete(L, 1, e);
    printf("%d\n", e);

    //���Ҳ���
    PrintList(L);
    int num = LocateElem(L, 5);
    printf("%d\n", num);
}
