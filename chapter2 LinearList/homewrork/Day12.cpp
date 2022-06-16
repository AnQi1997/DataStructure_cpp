#include <stdio.h>
#include <stdlib.h>

//楼梯有几种走法
int step(int n) {
    if (n == 1 || n == 2) {
        return n;
    } else {
        //走两步或者走一步
        return step(n - 2) + step(n - 1);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", step(n));
}
