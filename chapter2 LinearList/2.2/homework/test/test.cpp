#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50

typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];
    int length;
} SqList;

void search_x(SqList& L, ElemType x) {
    int low = 0, high = L.length - 1;
    int mid;

    //二分查找
    while (low <= high) {
        mid = low + ((high - low) >> 1);
        if (L.data[mid] == x)
            break;
        else if (L.data[mid] < x)
            low = mid + 1;
        else if (L.data[mid] > x)
            high = mid - 1;
    }

    //找到
    if (low <= high && L.data[mid] == x && mid != L.length - 1) {
        ElemType temp = L.data[mid];
        L.data[mid] = L.data[mid + 1];
        L.data[mid + 1] = temp;
    }

    if (low > high) {
        int i;
        for (i = L.length - 1; i > high; i--) {
            L.data[i + 1] = L.data[i];
        }
        L.data[high + 1] = x;
        L.length += 1;
    }
}

int main() {
    SqList L = {1, 2, 4, 5, 6, 7};
    L.length = 6;

    for (int i = 0; i < L.length; i++) {
        printf("%4d", L.data[i]);
    }
    printf("\n");

    search_x(L, 8);

    for (int i = 0; i < L.length; i++) {
        printf("%4d", L.data[i]);
    }
}