#include <stdio.h>
#include <stdlib.h>

//习题1.10
//设将n（n>1）个整数存放到一维数组R中。设计一个在时间和空间两方面都尽可能高效的的算法。
// 将R保存的序列循环左移p个位置（0<p<n）,
// 即R中的数据由
//（X0, X1, ... , Xn-1）变换为
//（Xp, Xp+1, ... , Xn-1, X0, X1, ... , Xp-1）
// 要求：
// 1）给出算法设计的基本设计思想
// 2）使用C/C++/Java描述算法，关键之处给出注释
// 3）说明设计算法的时间复杂度和空间复杂度

// 1）算法设计基本思想：
// 把数组ab转换成数组ba，a代表数组前p个元素，b代表数组余下的n-p个元素
// 先将a逆置得到a逆，再将b逆置得到b逆，对（a逆 b逆）进行逆置得到ba
// Reverse(0, p-1);
// Reverse(p, n);
// Reverse(0, n-1);

// 2）使用C语言进行描述
/**
 * @brief
 *
 * @param R
 * @param from 开头下标
 * @param to 末尾下标
 * （to - from + 1)是表中元素个数
 * （to - from + 1)/2 表示：只需遍历前半部分
 */
void Reverse(int R[], int from, int to) {
    for (int i = 0; i < (to - from + 1) / 2; i++) {
        // from + i ：
        // to - i ：
        int temp = R[from + i];
        R[from + i] = R[to - i];
        R[to - i] = temp;
    }
}

/**
 * @brief
 *
 * @param R 数组名
 * @param n 数组内元素个数
 * @param p 分为前 p 个，后 n-p 个
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

//时间复杂度分析：
// Reverse(R, 0, p - 1); O(p/2)
// Reverse(R, p, n - 1); O((n-p)/2)
// Reverse(R, 0, n - 1); O(n/2)

//空间复杂度分析：O(1)