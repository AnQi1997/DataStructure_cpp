/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-05-15 17:43:40
 * @Description:
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int ElemType;
typedef struct {
    ElemType* elem;  //整型指针
    int TableLen;    //存储动态数组里边元素的个数
} SSTable;

int Search_Seq(SSTable ST, ElemType key) {
    ST.elem[0] = key;  //让零号元素作为哨兵
    int i;
    for (i = ST.TableLen - 1; ST.elem[i] != key; --i)
        ;
    return i;
}

// init进行了随机数生成
void ST_Init(SSTable& ST, int len) {
    ST.TableLen = len + 1;
    //多申请了一个位置,为了存哨兵
    ST.elem = (ElemType*)malloc(sizeof(ElemType) * ST.TableLen);
    int i;
    //随机数生成
    //意思是以现在的系统时间作为随机数的种子来产生随机数，

    //在C语言中,rand()函数可以用来产生随机数，但是这不是真正意义上的随机数，
    //是一个伪随机数，它是根据一个数，我们可以称它为种子，为基准以某个递推公式推算出来的一系数，
    //但这不是真正的随机数，当计算机正常开机后，这个种子的值是定了的，除非你破坏了系统，为了改变这个种子的值。
    //因此，C提供了srand()函数，它的原型是 void srand( int a)。用来改变这个种子值。
    // srand( (time(NULL) )中time(NULL)函数是得到一个从1900年1月1日到现在的时间秒数，
    //这样每一次运行程序的时间的不同就可以保证得到不同的随机数了。
    //为了验证排序，保证没有结果那么巧合
    srand(time(NULL));  
    //为啥这里零号位置也随机了数据，为折半查找服务
    for (i = 0; i < ST.TableLen; i++) {
        //下标范围：0——ST.TableLen-1
        ST.elem[i] = rand() % 100;
    }
}

void ST_print(SSTable ST) {
    for (int i = 0; i < ST.TableLen; i++) {
        printf("%3d", ST.elem[i]);
    }
    printf("\n");
    printf("\n");
}

//二分查找
//时间复杂度  logn
int Binary_Search(SSTable L, ElemType key) {
    int low = 0, high = L.TableLen - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (L.elem[mid] == key)
            return mid;  //等于就找到了
        else if (L.elem[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int compare(const void* left, const void* right) {
    // left，right是任意两个元素的地址值
    return *(ElemType*)left - *(ElemType*)right;
    // return *(ElemType*)right - *(ElemType*)left;//从大到小
}

//《王道C督学营》课程
//顺序查找 与  折半查找
int main() {
    SSTable ST;
    ElemType key;
    int pos;          //存储查询元素的位置
    ST_Init(ST, 10);  //利用代码随机存数据
    ST_print(ST);
    printf("请输入要搜索的key值:\n");
    scanf("%d", &key);
    pos = Search_Seq(ST, key);  // key所在数组下标
    if (pos) {                  //如果不是0
        printf("查找成功 位置为 %d\n", pos);
    } else {
        printf("查找失败\n\n");
    }

    printf("快速排序后的结果：\n");
    // qsort实现的是快排
    qsort(ST.elem, ST.TableLen, sizeof(ElemType), compare);
    ST_print(ST);
    printf("二分查找，请输入要搜索的key值:\n");
    scanf("%d", &key);
    //有序数组
    pos = Binary_Search(ST, key);  //二分查找，也叫折半查找
    if (pos != -1) {
        printf("查找成功 位置为 %d\n", pos);
    } else {
        printf("查找失败\n");
    }
    system("pause");
}
