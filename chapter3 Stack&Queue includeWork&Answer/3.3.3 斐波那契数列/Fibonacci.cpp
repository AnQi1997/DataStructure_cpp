/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-07-29 16:53:31
 * @Description: 斐波那契数列问题练习
 * 爬楼梯
 */
#include <stdio.h>
#include <stdlib.h>

int Fib(int n) {
    if (0 == n)
        return 0;
    else if (1 == n)
        return 1;
    else
        return Fib(n - 1) + Fib(n - 2);
}

int main() {
    int num;
    while(scanf("%d", &num) != EOF){
        printf("Fib(%d) = %d\n", num, Fib(num));
    }
}
