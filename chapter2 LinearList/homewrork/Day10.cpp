#include <stdio.h>
#include <stdlib.h>

int change(int* p) {
    return *p = *p / 2;
}

int main() {
    int num;
    scanf("%d", &num);
    change(&num);
    printf("%d\n", num);
}
