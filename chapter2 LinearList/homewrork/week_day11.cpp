/*
 * @Author: AnQi1997 2361067080@qq.com
 * @Date: 2022-06-22 12:41:29
 * @LastEditors: AnQi1997 2361067080@qq.com
 * @LastEditTime: 2022-06-22 12:50:58
 * @FilePath: \DataStructure_Cpp\chapter2 LinearList\homewrork\week_day11.cpp
 * @Description:

输入一个整型数，然后申请对应大小空间内存，然后读取一个字符串，
字符串的输入长度小于最初输入的整型数大小，最后输出输入的字符串即可
（无需考虑输入的字符串过长，超过了内存大小）；

注意下面问题：

char *p;

scanf("%d",&n);

p=malloc(n);

scanf("%c",&c);//注意在scanf和gets中间使用scanf("%c",&c),去除换行

gets(p);

 *
 * Copyright (c) 2022 by AnQi1997 2361067080@qq.com, All Rights Reserved.
 */
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num;
    scanf("%d", &num);

    char* p = (char*)malloc(num);
    char c;
    scanf("%c", &c);  //去除换行符

    // gets(p);
    fgets(p, num, stdin);

    puts(p);
}
