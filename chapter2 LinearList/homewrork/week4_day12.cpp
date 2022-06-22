/*
 * @Author: AnQi1997 2361067080@qq.com
 * @Date: 2022-06-22 15:02:55
 * @LastEditors: AnQi1997 2361067080@qq.com
 * @LastEditTime: 2022-06-22 15:18:20
 * @FilePath: \DataStructure_Cpp\chapter2 LinearList\homewrork\week4_day12.cpp
 * @Description:
 * 假如有n个台阶，一次只能上1个台阶或2个台阶，请问走到第n个台阶有几种走法？
 * 
 * 为便于读者理解题意，这里举例说明如下：
 * 假如有3个台阶，那么总计就有3种走法：
 * 第一种为每次上1个台阶，上3次；
 * 第二种为先上2个台阶，再上1个台阶；
 * 第三种为先上1个台阶，再上2个台阶。
 * 输入为n，输出为走到第n个台阶有几种走法
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
