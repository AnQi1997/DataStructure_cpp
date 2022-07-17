//使用C++的引用，注意提交时把代码选为C++；
// 在主函数定义字符指针 char *p,
// 然后在子函数内malloc申请空间，通过fgets读取字符串，
// 然后在主函数中进行输出；要求子函数使用C++的引用，
// 注意在C++中从标准输入读取字符串，需要使用fgets(p,100,stdin)

#include<stdio.h>
#include<stdlib.h>

void modify_pointer(char*& p){
    p = (char*)malloc(50);
    fgets(p, 100, stdin);
}


int main(){
    char* p;
    modify_pointer(p);
    puts(p);
    return 0;    
}












































