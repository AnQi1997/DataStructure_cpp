#include <stdio.h>
#include <stdlib.h>

void modifyNum(int& b) {
    b = b + 1;
}

void modify_pointer(int*& p) {
    p = (int*)malloc(20);
    p[0] = 5;
}

int main() {
    // int a = 10;
    // modifyNum(a);
    // printf("%d\n", a);

    int* p = NULL;
    modify_pointer(p);
    printf("%d\n", p[0]);
}
