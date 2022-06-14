#include <stdio.h>
#include <stdlib.h>

struct student {
    int num;
    char name[20];
    char sex[20];
}SqList;

int main() {
    struct student s;
    scanf("%d %s %s", &s.num, s.name, s.sex);
    printf("%d %s %s", s.num, s.name, s.sex);
}
