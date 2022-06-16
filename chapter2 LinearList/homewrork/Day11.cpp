#include <stdio.h>
#include <stdlib.h>

int main() {
    char* p;
    int n;
    char c;
    scanf("%d", &n);
    p = (char*)malloc(n);
    scanf("%c", &c);
    // gets(p);
    fgets(p, n, stdin);
    puts(p);



}
