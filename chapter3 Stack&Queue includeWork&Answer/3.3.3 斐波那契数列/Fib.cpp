/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-06-27 15:43:12
 * @Description: 斐波那契额数列问题
 */
#include <stdio.h>
#include <stdlib.h>

// 0 1 1 2 3 5
// f(n) = f(n-1) + f(n-2)
int Fib(int n) {
    if (0 == n)
        return 0;
    else if (1 == n)
        return 1;
    else
        return Fib(n - 2) + Fib(n - 1);
}

int main() {
    int num;
    while(scanf("%d", &num) != EOF){
        printf("Fib(%d) = %d\n", num, Fib(num));
    }
}
