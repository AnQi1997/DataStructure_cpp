//ʹ��C++�����ã�ע���ύʱ�Ѵ���ѡΪC++��
// �������������ַ�ָ�� char *p,
// Ȼ�����Ӻ�����malloc����ռ䣬ͨ��fgets��ȡ�ַ�����
// Ȼ�����������н��������Ҫ���Ӻ���ʹ��C++�����ã�
// ע����C++�дӱ�׼�����ȡ�ַ�������Ҫʹ��fgets(p,100,stdin)

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












































