#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50

typedef int ElemType;
/**
 * @brief ��̬�洢
 *
 */
typedef struct {
    ElemType data[MaxSize];
    int length;
} SqList;

//ϰ��1.1
bool delMin(SqList& L) {
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

//ϰ�� 1.2
void reverseList(SqList& L) {
    ElemType temp;
    for (int i = 0; i < L.length / 2; i++) {
        temp = L.data[i];
        L.data[i] = L.data[L.length - 1 - i];
        L.data[L.length - 1 - i] = temp;
    }
}

//ϰ��1.3
void delete_x_1(SqList& L, ElemType x) {
    // 1 ���㲻Ϊx�ĸ������ŵ�ͷ
    int count = 0;
    for (int i = 0, j = 0; i < L.length; i++, j++) {
        if (L.data[i] != x) {
            L.data[count] = L.data[i];
            count++;
        }
    }
    L.length = count;
}

// ϰ�� 1.3
// 2.��x
void delete_x_2(SqList& L, ElemType x) {
    int k = 0;
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == x) {
            k++;
        } else {
            //���L.data[i]����x ��ôǰ��k����λ��
            L.data[i - k] = L.data[i];
        }
    }

    // int k = 0, i = 0;
    // while (i < L.length) {
    //     if (L.data[i] == x) {
    //         k++;
    //     } else {
    //         L.data[i - k] = L.data[i];
    //     }
    //     i++;
    // }
    L.length = L.length - k;
}

//ϰ�� 1.4 Ҫ��:s<t
void del_s_t_1(SqList& L, ElemType s, ElemType t) {
    if (s >= t || L.length == 0)
        return false;
    //����˳���
    //�ҵ���һ������s����
    for (int i = 0; i < L.length && L.data[i] < s; i++)
        ;
    // TODO i���ֵ��L.length ΪɶҪд i >= L.length
    if (i >= L.length)
        return false;
    //�ҵ���һ������t����
    for (int j = i; j < L.length && L.data[j] < t; j++)
        ;
    
}

//����
/**
 * @brief ��˳����i��λ���ϲ���Ԫ��
 *
 * @param L
 * @param i
 * @return true
 * @return false
 */
bool ListInsert(SqList& L, int i, ElemType e) {
    if (i < 1 || i > L.length + 1)
        return false;
    if (L.length >= MaxSize)
        return false;
    for (int j = L.length; j >= i; j--) {
        //Ԫ�غ���
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}

//ɾ��
/**
 * @brief ɾ����i��λ���ϵ�Ԫ�أ���e����
 *
 * @param L
 * @param i
 * @param e
 * @return true
 * @return false
 */
bool ListDelete(SqList& L, int i, ElemType e) {
    if (i < 1 || i > L.length) {
        return false;
    }
    e = L.data[i];
    //Ԫ�غ���
    for (int j = i; j < L.length; j++) {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
}

//����
/**
 * @brief ��ֵ����
 *
 * @param L
 * @param e
 * @return int
 */
int locateElem(SqList L, ElemType e) {
    int i;
    for (i = 0; i < L.length; i++) {
        if (L.data[i] == e) {
            return i + 1;
        }
    }
    return 0;
}

void printList(SqList L) {
    for (int i = 0; i < L.length; i++) {
        printf("%4d", L.data[i]);
    }
    printf("\n");
}

int main() {
    SqList LA = {1, 2, 6, 6, 10, 12};
    LA.length = 6;
    printList(LA);

    // ListInsert(LA, 6, 100);
    // printList(LA);

    // ElemType delReturn;
    // ListDelete(LA, 2, delReturn);
    // printList(LA);

    // int flag = locateElem(LA, 10);
    // if(flag){
    //     printf("���ҳɹ����±�Ϊ��%d", flag);
    // }else{
    //     printf("����ʧ��");
    // }

    //ϰ��1.1
    // delMin(LA);
    // printList(LA);

    //ϰ�� 1.2
    // reverseList(LA);
    // printList(LA);

    //ϰ��1.3.1
    // delete_x_1(LA, 6);
    // printList(LA);

    //ϰ��1.3.2
    delete_x_2(LA, 6);
    printList(LA);
}
