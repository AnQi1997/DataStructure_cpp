#include <stdio.h>
#include <stdlib.h>

//ϰ��1.10
//�轫n��n>1����������ŵ�һά����R�С����һ����ʱ��Ϳռ������涼�����ܸ�Ч�ĵ��㷨��
// ��R���������ѭ������p��λ�ã�0<p<n��,
// ��R�е�������
//��X0, X1, ... , Xn-1���任Ϊ
//��Xp, Xp+1, ... , Xn-1, X0, X1, ... , Xp-1��
// Ҫ��
// 1�������㷨��ƵĻ������˼��
// 2��ʹ��C/C++/Java�����㷨���ؼ�֮������ע��
// 3��˵������㷨��ʱ�临�ӶȺͿռ临�Ӷ�

// 1���㷨��ƻ���˼�룺
// ������abת��������ba��a��������ǰp��Ԫ�أ�b�����������µ�n-p��Ԫ��
// �Ƚ�a���õõ�a�棬�ٽ�b���õõ�b�棬�ԣ�a�� b�棩�������õõ�ba
// Reverse(0, p-1);
// Reverse(p, n);
// Reverse(0, n-1);

// 2��ʹ��C���Խ�������
/**
 * @brief
 *
 * @param R
 * @param from ��ͷ�±�
 * @param to ĩβ�±�
 * ��to - from + 1)�Ǳ���Ԫ�ظ���
 * ��to - from + 1)/2 ��ʾ��ֻ�����ǰ�벿��
 */
void Reverse(int R[], int from, int to) {
    for (int i = 0; i < (to - from + 1) / 2; i++) {
        // from + i ��
        // to - i ��
        int temp = R[from + i];
        R[from + i] = R[to - i];
        R[to - i] = temp;
    }
}

/**
 * @brief
 *
 * @param R ������
 * @param n ������Ԫ�ظ���
 * @param p ��Ϊǰ p ������ n-p ��
 */
void Converse(int R[], int n, int p) {
    Reverse(R, 0, p - 1);
    Reverse(R, p, n - 1);
    Reverse(R, 0, n - 1);
}

int main() {
    int R[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(R) / sizeof(R[0]);
    for (int i = 0; i < n; i++) {
        printf("%4d", R[i]);
    }
    printf("\n");
    Converse(R, n, 3);
    for (int i = 0; i < n; i++) {
        printf("%4d", R[i]);
    }
}

// 3)

//ʱ�临�Ӷȷ�����
// Reverse(R, 0, p - 1); O(p/2)
// Reverse(R, p, n - 1); O((n-p)/2)
// Reverse(R, 0, n - 1); O(n/2)

//�ռ临�Ӷȷ�����O(1)