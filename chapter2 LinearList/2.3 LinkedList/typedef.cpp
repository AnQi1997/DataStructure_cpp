#include <stdio.h>

typedef struct student {
    int num;
    char name[20];
    char sex;
} stu, *pstu;

typedef int INTEGER;

int main() {
    stu s = {30, "curry", 's'};
    pstu p;  // stu *p1; p是一个指针
    INTEGER i = 10;
    p = &s;
    printf("i = %d, p->num = %d", i, p->num);
}
