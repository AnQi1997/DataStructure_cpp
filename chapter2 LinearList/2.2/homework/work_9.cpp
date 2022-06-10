#include <stdio.h>
#include <stdlib.h>
//ϰ��1.9
//���Ա�(a1, a2, ... , an)�е�Ԫ�ص��������Ұ�˳��洢�ڼ������.
//Ҫ�����һ���㷨,���������ʱ���ڱ��в�����ֵΪx��Ԫ��,
//���ҵ�,��������Ԫ��λ���ཻ��
//���Ҳ���,���������в�ʹ����Ԫ������������

//�㷨˼��:˳��洢�����Ա��������,��˳�����,Ҳ���۰����
//Ҫ�����ʱ����ұ�����ֵΪx��Ԫ��,Ӧ��ʹ���۰���ҷ�

typedef int ElemType;
/**
 * @brief
 *
 * @param A ����
 * @param x Ҫ���ҵ�ֵ
 * @param n ���鳤��
 */
void SearchExchangeInsert(ElemType A[], ElemType x, int n) {
    // int n = sizeof(A) / sizeof(A[0]);  //���鳤��
    int low = 0, high = n - 1, mid;

    //�۰����
    while (low < high) {
        mid = (low + high) / 2;
        if (A[mid] == x)
            break;
        else if (A[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }

    //�ҵ�ֵΪx��Ԫ��,��������Ԫ�ؽ���
    if (A[mid] == x && mid != n - 1) {
        ElemType temp = A[mid];
        A[mid] = A[mid + 1];
        A[mid + 1] = temp;
    }
    //û�ҵ�ֵΪx��Ԫ��,�������,ʹ���������
    //�±�high֮��ȫ������x,���ҵ�ֵ����high��Ҳ����mid��
    if (low > high) {
        int i;  //�±�
        // iȡֵ��Χ��n-1 ~ high+1
        for (i = n - 1; i > high; i--)
            //Ԫ�غ���
            A[i + 1] = A[i];
        //��� i = high
        //���������λ��
        A[i + 1] = x;
    }
}

int main() {
    ElemType A[] = {1, 2, 3, 4, 5};
    int n = sizeof(A) / sizeof(A[0]);  //���鳤��

    SearchExchangeInsert(A, 6, n);
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++) {
        printf("%4d", A[i]);
    }
}
