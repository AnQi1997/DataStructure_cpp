#include <stdio.h>
#include <stdlib.h>

//¥���м����߷�
int step(int n) {
    if (n == 1 || n == 2) {
        return n;
    } else {
        //������������һ��
        return step(n - 2) + step(n - 1);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", step(n));
}
