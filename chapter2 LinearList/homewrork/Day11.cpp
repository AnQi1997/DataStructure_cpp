/*
 * @Author: AnQi1997 2361067080@qq.com
 * @Date: 2022-06-15 19:05:46
 * @LastEditors: AnQi1997 2361067080@qq.com
 * @LastEditTime: 2022-06-22 12:49:26
 * @FilePath: \DataStructure_Cpp\chapter2 LinearList\homewrork\Day11.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by AnQi1997 2361067080@qq.com, All Rights Reserved. 
 */
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
