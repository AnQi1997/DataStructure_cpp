/*
 * @Author: AnQi1997 2361067080@qq.com
 * @Date: 2022-06-22 12:41:29
 * @LastEditors: AnQi1997 2361067080@qq.com
 * @LastEditTime: 2022-06-22 12:50:58
 * @FilePath: \DataStructure_Cpp\chapter2 LinearList\homewrork\week_day11.cpp
 * @Description:

����һ����������Ȼ�������Ӧ��С�ռ��ڴ棬Ȼ���ȡһ���ַ�����
�ַ��������볤��С������������������С��������������ַ�������
�����迼��������ַ����������������ڴ��С����

ע���������⣺

char *p;

scanf("%d",&n);

p=malloc(n);

scanf("%c",&c);//ע����scanf��gets�м�ʹ��scanf("%c",&c),ȥ������

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
    scanf("%c", &c);  //ȥ�����з�

    // gets(p);
    fgets(p, num, stdin);

    puts(p);
}
