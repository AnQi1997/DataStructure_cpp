/*
 * @Author: AnQi1997 2361067080@qq.com
 * @Date: 2022-06-22 12:34:08
 * @LastEditors: AnQi1997 2361067080@qq.com
 * @LastEditTime: 2022-06-22 12:40:22
 * @FilePath: \DataStructure_Cpp\chapter2 LinearList\homewrork\week4_Day10.cpp
 * @Description:
 * ����һ�����������������i��ͨ���Ӻ���change���������ı���i��2��Ȼ���ӡi��
 * ������������Ϊ10����ӡ��5����������Ϊ7����ӡ��3
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