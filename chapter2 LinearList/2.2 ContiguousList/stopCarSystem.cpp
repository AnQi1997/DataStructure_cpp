// 停车场问题.cpp : 定义控制台应用程序的入口点。
//
#include <conio.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define MAXSIZE 5
//定义结构体类型car
struct Car {
    char cph[5];
    int arrivetime;
    int pushtime;
    int leavetime;
    int price;
};
//定义栈
typedef struct {
    Car data[MAXSIZE];
    int top;
} SeqStack;
//初始化栈
SeqStack* Init_SeqStack() {
    SeqStack* s;
    s = (SeqStack*)new (SeqStack);
    s->top = -1;
    return s;
}
//判断栈空
int Empty(SeqStack* s) {
    if (s->top == -1)
        return 1;
    else
        return 0;
}
//判断栈满
int Full(SeqStack* s) {
    if (s->top == MAXSIZE - 1)
        return 1;
    else
        return 0;
}
//入栈
int push(SeqStack* s, Car car) {
    if (s->top == MAXSIZE - 1)
        return 0;
    else {
        s->top++;
        s->data[s->top] = car;
        return 1;
    }
}
//出栈
int pop(SeqStack* s, Car* x) {
    if (Empty(s))
        return 0;
    else {
        *x = s->data[s->top];
        s->top--;
        return 1;
    }
}
//定义链队
typedef struct node {
    Car data;
    struct node* next;
} QNode;
typedef struct
{
    QNode *front, *rear;
} LQueue;
//链队初始化
LQueue* Init_LQueue() {
    LQueue* q;
    QNode* p;
    q = (LQueue*)new (LQueue);
    p = (QNode*)new (QNode);
    p->next = NULL;
    q->front = p;
    q->rear = p;
    return q;
}
//入队
void In_LQueue(LQueue* q, Car car) {
    QNode* p;
    p = (QNode*)new (QNode);
    p->data = car;
    p->next = NULL;
    q->rear->next = p;
    q->rear = p;
}
//判断队空
int Empty_LQueue(LQueue* q) {
    if (q->front == q->rear)
        return 1;
    else
        return 0;
}
//出队
int Out_LQueue(LQueue* q, Car* x) {
    QNode* p;
    if (Empty_LQueue(q)) {
        printf("队空");
        return 0;
    } else {
        p = q->front->next;
        q->front->next = p->next;
        *x = p->data;
        delete (p);
        if (q->front->next == NULL) {
            q->rear = q->front;
            return 1;
        }
    }
}
//判栈中有无信息
int searchCar(SeqStack* s, Car car) {
    SeqStack* p = NULL;
    p = s;
    int temp = p->top;
    while (temp >= 0) {
        if (p->data[temp].cph == car.cph)
            return temp;
        temp--;
    }
    return -1;
}
void show1(SeqStack* s) {
    printf("已停靠车辆：\n");
    printf("车牌号；  到达时间：  停车时间：  \n");
    for (int temp = 0; temp <= s->top; temp++) {
        printf("%p%p%p\n", &s->data[temp].cph, &s->data[temp].arrivetime, &s->data[temp].pushtime);
    }
}
//显示队列中的车辆
void show2(LQueue* l, Car car) {
    QNode* q = l->front->next;
    printf("等待车辆： \n");
    printf("车牌号： 到达时间： \n");
    while (q != NULL) {
        printf("%p%p\n", &q->data.cph, &q->data.arrivetime);
        q = q->next;
    }
}
//输入车辆信息并入栈或入队
int inputcardata(SeqStack* s, LQueue* l) {
    Car car;
    printf("请输入车牌号： ");
    scanf("%s\n", &car.cph, 5);
    if (searchCar(s, car) != -1)  //车牌号重复
    {
        printf("车牌号重复！！\n");
        printf("请重新输入车牌号： ");
        scanf("%s\n", &car.cph, 5);
    }
    printf("请输入到达时间： ");
    scanf("%d\n", &car.arrivetime);
    if (car.arrivetime < 0 || car.arrivetime > 24) {
        printf("时间输入不合理（0—24），请重新输入:");
        scanf("%d", &car.arrivetime);
    }
    car.pushtime = car.arrivetime;
    if (Full(s) == 1)  //停车场已满
    {
        show1(s);
        In_LQueue(l, car);
        show2(l, car);
    } else {
        push(s, car);
        show1(s);
    }
    return 0;
}
//离开停车场
void leavetcc(SeqStack* s, SeqStack* p, LQueue* Q) {
    if (Empty(s) == 1) {
        printf("停车场未停靠车辆。\n");
    }
    int leavetime = 0;
    Car car;
    printf("离开的车车牌号为：\n");
    scanf("%s\n", &car.cph, 5);
    int m = searchCar(s, car);
    while (m == -1) {
        printf("输入错误，请重新输入：\n");
        scanf("%s\n", &car.cph, 5);
        m = searchCar(s, car);
    }
    printf("请输入出栈时间：  每小时停车费： \n");
    scanf("%d%d\n", &car.leavetime, &car.price);
    while (car.leavetime <= s->data[m].arrivetime) {
        printf("离开时间必须大于到达时间，请重新输入：\n");
        scanf("%d\n", &car.leavetime);
    }
    printf("离去车辆信息\n");
    printf("车牌号     离开时间     \n");
    scanf("%p %p", &s->data[m].cph, &s->data[m].leavetime);
    int x = s->data[m].leavetime;
    int y = s->data[m].arrivetime;
    int c = s->data[m].price;
    cout << "收费：" << c * (x - y);
    printf("\n***********************\n");
    //离开的车在栈顶时
    if (m == s->top) {
        Car* b;
        b = (Car*)new (Car);
        pop(s, b);
    }
    //不在栈顶
    else {
        for (int i = s->top; i <= m; i++) {
            Car* b = (Car*)new (Car);
            if (i == m) {
                pop(s, b);
            } else {
                push(p, s->data[i]);
                pop(s, b);
            }
        }
        for (int j = p->top; j >= 0; j--) {
            Car* b = (Car*)new (Car);
            pop(p, b);
            push(s, *b);
        }
    }
    //判断队列是否有等待车辆--有的话对头入栈
    if (Q->rear != Q->front) {
        Car* b = (Car*)new (Car);
        Out_LQueue(Q, b);
        b->pushtime = leavetime;
        push(s, *b);
        show1(s);
        show2(Q, car);
    } else
        show1(s);
}
int main() {
    //车辆栈
    SeqStack* s = (SeqStack*)new (SeqStack);
    Init_SeqStack();
    //车辆在路边停靠的队列
    LQueue* l = (LQueue*)new (LQueue);
    Init_LQueue();
    //辅助栈存储让位的信息
    SeqStack* se = (SeqStack*)new (SeqStack);
    Init_SeqStack();
    while (1) {
        int i;
        cout << "请选择你的方案：";
        cin >> i;
        switch (i) {
            case 1:
                inputcardata(s, l);
                break;
            case 2:
                leavetcc(s, se, l);
                break;
            case 3:
                return 0;
        }
    }
    return 0;
}