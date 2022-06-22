/*
 * @Author: AnQi1997 2361067080@qq.com
 * @Date: 2022-06-22 12:34:08
 * @LastEditors: AnQi1997 2361067080@qq.com
 * @LastEditTime: 2022-06-22 12:40:22
 * @FilePath: \DataStructure_Cpp\chapter2 LinearList\homewrork\week4_Day10.cpp
 * @Description:
 * 输入一个整型数，存入变量i，通过子函数change把主函数的变量i除2，然后打印i，
 * 例如如果输入的为10，打印出5，如果输入的为7，打印出3
 *
 * Copyright (c) 2022 by AnQi1997 2361067080@qq.com, All Rights Reserved.
 */
#include <stdio.h>
#include <stdlib.h>

// int change(int* p) {
//     return *p = *p / 2;
// }

// int main() {
//     int num;
//     scanf("%d", &num);
//     change(&num);
//     printf("%d", num);
// }

int change(int* p) {
    return *p = *p / 2;
}

int main() {
    int num;
    scanf("%d", &num);
    change(&num);
    printf("%d", num);
}