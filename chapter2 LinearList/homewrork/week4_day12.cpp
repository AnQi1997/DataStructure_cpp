/*
 * @Author: AnQi1997 2361067080@qq.com
 * @Date: 2022-06-22 15:02:55
 * @LastEditors: AnQi1997 2361067080@qq.com
 * @LastEditTime: 2022-06-22 15:18:20
 * @FilePath: \DataStructure_Cpp\chapter2 LinearList\homewrork\week4_day12.cpp
 * @Description:
 * ������n��̨�ף�һ��ֻ����1��̨�׻�2��̨�ף������ߵ���n��̨���м����߷���
 * 
 * Ϊ���ڶ���������⣬�������˵�����£�
 * ������3��̨�ף���ô�ܼƾ���3���߷���
 * ��һ��Ϊÿ����1��̨�ף���3�Σ�
 * �ڶ���Ϊ����2��̨�ף�����1��̨�ף�
 * ������Ϊ����1��̨�ף�����2��̨�ס�
 * ����Ϊn�����Ϊ�ߵ���n��̨���м����߷�
 *
 * Copyright (c) 2022 by AnQi1997 2361067080@qq.com, All Rights Reserved.
 */
#include <stdio.h>
#include <stdlib.h>

int ClimbStairs(int n) {
    if (1 == n)
        return 1;
    if (2 == n)
        return 2;
    return ClimbStairs(n - 1) + ClimbStairs(n - 2);
}

int main() {
}
