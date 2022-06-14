#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50

typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];
    int length;
} SqList;

/**
 * @brief ��˳���L��i��1 <= i <= L.length����λ�ò�����Ԫ��e
 * ��i���벻�Ϸ����򷵻�false����ʾ����ʧ��
 * ���򣬽���i��Ԫ�ؼ�֮�������Ԫ�����������ƶ�һ��λ�ã�
 * �ڳ�һ����λ�ò�����Ԫ��e��˳���������1������ɹ�������true
 * @param L
 * @param i
 * @param e
 * @return true
 * @return false
 */
// i�������λ�ã���1��ʼ��eҪ�����Ԫ��
bool ListInsert(SqList& L, int i, ElemType e) {
    if (i < 1 || i > L.length + 1)
        return false;
    if (L.length >= MaxSize)
        return false;
    for (int j = L.length; j >= i; j--)
        L.data[j] = L.data[j - 1];
    L.data[i - 1] = e;
    L.length++;
    return true;
}
//���������ڱ�β���룺��i=n+1;ʱ�临�Ӷȣ�O(1)
//�������ڱ�ͷ���룺��i=1;ʱ�临�Ӷȣ�O(n)
//ƽ�������O(n)

/**
 * @brief
 * ɾ��˳���L�е�i(1 <= i <= L.length)��λ�õ�Ԫ�أ������ñ���e���ء�
 * ��i�����벻�Ϸ����򷵻�false��
 * ���򣬽���ɾԪ�ظ������ñ���e��
 * ������i+1��Ԫ�ؼ���������Ԫ��������ǰ�ƶ�һ��λ�ã�����true
 *
 * @param L
 * @param i��λ��
 * @param e
 * @return true
 * @return false
 */
bool ListDelete(SqList& L, int i, ElemType& e) {
    if (i < 1 || i > L.length)
        return false;
    //����ʱ��i�Ϸ��������ñ���e����
    e = L.data[i - 1];
    for (int j = i; j < L.length; j++) {
        //Ԫ��ǰ��
        L.data[j - 1] = L.data[j];
    }
    //����һ
    L.length--;
    return true;
}
//��������ɾ����β����i=n�������ƶ���ʱ�临�Ӷ�O(1)
//������ɾ����ͷ����i=1,���ƶ�����ͷ���������Ԫ�أ�ʱ�临�Ӷ�O(n)
//ƽ�������i=1~n�ۼ� pi * (n-i) = 1/n * (n-i)��ʱ�临�Ӷȣ�O(n)

/**
 * @brief ��˳���L�в��ҵ�һ��Ԫ��ֵ����e��Ԫ�أ���������λ��
 *
 */
int LocateElem(SqList L, ElemType e) {
    int i;
    for (i = 0; i < L.length; i++) {
        if (L.data[i] == e)
            return i + 1;
    }
    return 0;
}
//������������Ԫ���ڱ�ͷ��ʱ�临�Ӷ�O(1)
//����������Ԫ���ڱ�β�����߲����ڣ�����Ҫ�Ƚ�n�Σ�ʱ�临�Ӷ�O(n)
//ƽ�������pi = 1/n; �ۼ�i = 1~n 1/n * i

void PrintList(SqList L) {
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

int main() {
    SqList L;
    L.data[0] = 6;
    L.data[1] = 7;
    L.data[2] = 8;
    L.length = 3;
    PrintList(L);

    printf("--------------\n");
    //����
    bool ret1;
    ret1 = ListInsert(L, 2, 100);
    if (ret1) {
        PrintList(L);
        printf("����ɹ���\n");
    } else {
        printf("����ʧ�ܣ�\n");
    }
    printf("--------------\n");
    //ɾ��
    bool ret2;
    ElemType delE;  //���ر���
    PrintList(L);
    ret2 = ListDelete(L, 2, delE);
    if (ret2) {
        PrintList(L);
        printf("ɾ���ɹ�!\n");
    } else {
        printf("ɾ��ʧ�ܣ�\n");
    }
    printf("--------------\n");

    int ret3 = LocateElem(L, 6);
    printf("Ԫ��λ��%d\n", ret3);
    if(ret3){
        printf("���ҳɹ�!\n");
    }else{
        printf("����ʧ��!\n");
    }
}
