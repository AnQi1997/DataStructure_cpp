#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50

typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];
    int length;
} SqList;

// 1. ɾ��������Сֵ��Ԫ�أ�����Ψһ�������ɺ������ر�ɾԪ�ص�ֵ���ճ���λ�������һ��Ԫ���
//��˳���Ϊ�գ�����ʾ������Ϣ���˳�����
bool deleteMin(SqList& L) {
    if (L.length == 0)
        return false;

    ElemType value = L.data[0];
    int pos = 0;

    for (int i = 0; i < L.length; i++) {
        if (L.data[i] < value) {
            value = L.data[i];
            pos = i;
        }
    }
    L.data[pos] = L.data[L.length - 1];
    L.length--;
    return true;
}

// 2.����һ��Ч�㷨����˳���L������Ԫ�����ã�Ҫ���㷨�Ŀռ临�Ӷ�ΪO(1)
void ReverseList(SqList& L) {
    for (int i = 0; i < L.length / 2; i++) {
        ElemType temp = L.data[i];
        // 0 L.length - 1
        // 1 L.length - 2
        L.data[i] = L.data[L.length - i - 1];
        L.data[L.length - i - 1] = temp;
    }
    // return L;
}

// 3.�Գ���Ϊn��˳���L����дһ��ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)���㷨
//���㷨ɾ�����Ա�������ֵΪx������Ԫ��
// 3.1 ��k��¼˳����в�����x��Ԫ�ظ�����ͳ�Ƹ���k����������x��ǰ�ƶ�k��λ�ã�����޸ĳ���
void del_x_1(SqList& L, ElemType x) {
    int k = 0;
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] != x) {
            L.data[k] = L.data[i];  //ǰ��
            k++;
        }
    }
    L.length = k;
}
// 3.2 ��k��¼˳���L�е���x��Ԫ�ظ�������ɨ���ͳ��k����������x��ǰ��
void del_x_2(SqList& L, ElemType x) {
    int k = 0, i = 0;  // k��¼ֵ����x�ĸ���
    while (i < L.length) {
        if (L.data[i] == x) {
            k++;
        } else {
            L.data[i - k] = L.data[i];
        }
        i++;
    }
    L.length = L.length - k;
}

// 4 ������˳�����ɾ����ֵ�ڸ���ֵs��t֮�䣨Ҫ��s<t��������Ԫ�أ�
//��s��t�������˳���Ϊ�գ�����ʾ������Ϣ���˳�����
bool del_s_2_t(SqList& L, ElemType s, ElemType t) {
    int i, j;
    if (s >= t || L.length == 0)
        return false;
    //Ѱ�ҵ�һ������s��Ԫ��
    for (i = 0; i < L.length && L.data[i] < s; i++)
        ;
    //����ֵ��С��s������false
    if (i >= L.length)
        return false;
    for (j = i; j < L.length && L.data[j] <= t; j++)
        ;
    //ǰ�ƣ����ɾԪ��λ��
    for (; j < L.length; i++, j++) {
        L.data[i] = L.data[j];
    }
    L.length = i;
    return true;
}

// 5. ��˳�����ɾ����ֵ�ڸ���ֵs��t֮�䣨����s��t,Ҫ��s<t��������Ԫ�أ�
//��s��t�������˳���Ϊ�գ�����ʾ������Ϣ���˳�����
bool del_s_2_t_2(SqList& L, ElemType s, ElemType t) {
    if (s >= t || L.length == 0)
        return false;
    int count = 0;
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] >= s && L.data[i] <= t) {//����ɾ����Χ
            count++;
        }else{
            L.data[i - count] = L.data[i];
        }
    }
    L.length = L.length - count;
    return true;
}

void printfList(SqList& L) {
    for (int i = 0; i < L.length; i++) {
        printf("%3d", L.data[i]);
    }
    printf("\n");
}

int main() {
    SqList L;
    L.data[0] = 6;
    L.data[1] = 7;
    L.data[2] = 8;
    L.length = 3;
    printfList(L);

    // 1.ɾ��
    //  bool ret = deleteMin(L);
    //  printfList(L);

    // 2.����
    //  ReverseList(L);
    //  printfList(L);

    // 3.1
    //  del_x_1(L, 8);
    //  printfList(L);
    // 3.2
    //  del_x_2(L, 8);
    //  printfList(L);

    // 4. del_s_2_t
    // del_s_2_t(L, 7, 8);
    // printfList(L);

    //5.
    // del_s_2_t_2(L, 7, 9);
    // printfList(L);
}
