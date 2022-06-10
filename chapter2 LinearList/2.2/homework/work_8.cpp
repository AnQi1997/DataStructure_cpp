#include <stdio.h>
#include <stdlib.h>
//ϰ��1.8 ��֪��һά����A[m+n]�����δ���������Ա�(a1, a2, a3, ... , am)��(b1, b2, b3, ... , bn).
//�Ա�дһ������,������������˳����λ�û���,
//����(b1, b2, b3, ... , bn)����(a1, a2, a3, ... , am)ǰ��

typedef int DataType;

void Reverse(DataType A[], int left, int right, int arraySize) {
    //�жϷ�Χ�Ϸ�
    if (left >= right || right >= arraySize)
        return;
    //�м�λ��
    int mid = (left + right) / 2;

    // 1 3 5
    // 0 1 2
    // left = 0 right = 2
    // mid = (0 + 2) / 2 = 1
    // mid - left = 1 - 0 = 1

    // i = 0:
    // temp = A[0 + 0]
    // A[0 + 0] = A[2 - 0]
    // A[2 - 0] = temp
    // A[0] �� A[2]����

    // i = 1;
    // temp = A[0 + 1];
    // A[0 + 1] = A[2 - 1];
    // A[2 - 1] = A[0 + 1];
    // A[1]����
    // ---------------------------------------------------------
    // �±�:3 4 5 6 7
    // Ԫ��:2 4 6 8 10

    // left = 3
    // right = 7
    // mid = (3 + 7) / 2 = 5;
    // mid - left = 5 - 3 = 2;

    // i = 0;
    // temp = A[3 + 0]
    // A[3 + 0] = A[7 - 0]
    // A[7 - 0] = A[3 - 0]

    for (int i = 0; i <= mid - left; i++) {
        DataType temp = A[left + i];
        A[left + i] = A[right - i];
        A[right - i] = temp;
    }
}

/**
 * @brief
 *
 * @param A ������
 * @param m ǰ����m��
 * @param n ������n��
 * @param arraySize
 */
void Exchange(DataType A[], int m, int n, int arraySize) {
    //����A[m+n]��,
    // ��0��m-1���˳���(a1, a2, a3, ... , am),
    //��m��m+n-1���˳���(b1, b2, b3, ... , bn)
    Reverse(A, 0, m + n - 1, arraySize);  //����������ǰn����bn,...,b2,b1 ������:am,...,a2,a1
    Reverse(A, 0, n - 1, arraySize);      //��ת bn,...,b2,b1, ���b1, b2, ... , bn
    Reverse(A, n, m + n - 1, arraySize);  //��ת am,...,a2,a1, ���a1, a2, ... , am
}

int main() {
    int m = 3;
    int n = 5;
    DataType A[] = {1, 3, 5, 2, 4, 6, 8, 10};
    Exchange(A, 3, 5, 8);
    for (int i = 0; i < 8; i++) {
        printf("%4d", A[i]);
    }
}