// ͣ��������.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include <conio.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define MAXSIZE 5
//����ṹ������car
struct Car {
    char cph[5];
    int arrivetime;
    int pushtime;
    int leavetime;
    int price;
};
//����ջ
typedef struct {
    Car data[MAXSIZE];
    int top;
} SeqStack;
//��ʼ��ջ
SeqStack* Init_SeqStack() {
    SeqStack* s;
    s = (SeqStack*)new (SeqStack);
    s->top = -1;
    return s;
}
//�ж�ջ��
int Empty(SeqStack* s) {
    if (s->top == -1)
        return 1;
    else
        return 0;
}
//�ж�ջ��
int Full(SeqStack* s) {
    if (s->top == MAXSIZE - 1)
        return 1;
    else
        return 0;
}
//��ջ
int push(SeqStack* s, Car car) {
    if (s->top == MAXSIZE - 1)
        return 0;
    else {
        s->top++;
        s->data[s->top] = car;
        return 1;
    }
}
//��ջ
int pop(SeqStack* s, Car* x) {
    if (Empty(s))
        return 0;
    else {
        *x = s->data[s->top];
        s->top--;
        return 1;
    }
}
//��������
typedef struct node {
    Car data;
    struct node* next;
} QNode;
typedef struct
{
    QNode *front, *rear;
} LQueue;
//���ӳ�ʼ��
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
//���
void In_LQueue(LQueue* q, Car car) {
    QNode* p;
    p = (QNode*)new (QNode);
    p->data = car;
    p->next = NULL;
    q->rear->next = p;
    q->rear = p;
}
//�ж϶ӿ�
int Empty_LQueue(LQueue* q) {
    if (q->front == q->rear)
        return 1;
    else
        return 0;
}
//����
int Out_LQueue(LQueue* q, Car* x) {
    QNode* p;
    if (Empty_LQueue(q)) {
        printf("�ӿ�");
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
//��ջ��������Ϣ
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
    printf("��ͣ��������\n");
    printf("���ƺţ�  ����ʱ�䣺  ͣ��ʱ�䣺  \n");
    for (int temp = 0; temp <= s->top; temp++) {
        printf("%p%p%p\n", &s->data[temp].cph, &s->data[temp].arrivetime, &s->data[temp].pushtime);
    }
}
//��ʾ�����еĳ���
void show2(LQueue* l, Car car) {
    QNode* q = l->front->next;
    printf("�ȴ������� \n");
    printf("���ƺţ� ����ʱ�䣺 \n");
    while (q != NULL) {
        printf("%p%p\n", &q->data.cph, &q->data.arrivetime);
        q = q->next;
    }
}
//���복����Ϣ����ջ�����
int inputcardata(SeqStack* s, LQueue* l) {
    Car car;
    printf("�����복�ƺţ� ");
    scanf("%s\n", &car.cph, 5);
    if (searchCar(s, car) != -1)  //���ƺ��ظ�
    {
        printf("���ƺ��ظ�����\n");
        printf("���������복�ƺţ� ");
        scanf("%s\n", &car.cph, 5);
    }
    printf("�����뵽��ʱ�䣺 ");
    scanf("%d\n", &car.arrivetime);
    if (car.arrivetime < 0 || car.arrivetime > 24) {
        printf("ʱ�����벻����0��24��������������:");
        scanf("%d", &car.arrivetime);
    }
    car.pushtime = car.arrivetime;
    if (Full(s) == 1)  //ͣ��������
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
//�뿪ͣ����
void leavetcc(SeqStack* s, SeqStack* p, LQueue* Q) {
    if (Empty(s) == 1) {
        printf("ͣ����δͣ��������\n");
    }
    int leavetime = 0;
    Car car;
    printf("�뿪�ĳ����ƺ�Ϊ��\n");
    scanf("%s\n", &car.cph, 5);
    int m = searchCar(s, car);
    while (m == -1) {
        printf("����������������룺\n");
        scanf("%s\n", &car.cph, 5);
        m = searchCar(s, car);
    }
    printf("�������ջʱ�䣺  ÿСʱͣ���ѣ� \n");
    scanf("%d%d\n", &car.leavetime, &car.price);
    while (car.leavetime <= s->data[m].arrivetime) {
        printf("�뿪ʱ�������ڵ���ʱ�䣬���������룺\n");
        scanf("%d\n", &car.leavetime);
    }
    printf("��ȥ������Ϣ\n");
    printf("���ƺ�     �뿪ʱ��     \n");
    scanf("%p %p", &s->data[m].cph, &s->data[m].leavetime);
    int x = s->data[m].leavetime;
    int y = s->data[m].arrivetime;
    int c = s->data[m].price;
    cout << "�շѣ�" << c * (x - y);
    printf("\n***********************\n");
    //�뿪�ĳ���ջ��ʱ
    if (m == s->top) {
        Car* b;
        b = (Car*)new (Car);
        pop(s, b);
    }
    //����ջ��
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
    //�ж϶����Ƿ��еȴ�����--�еĻ���ͷ��ջ
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
    //����ջ
    SeqStack* s = (SeqStack*)new (SeqStack);
    Init_SeqStack();
    //������·��ͣ���Ķ���
    LQueue* l = (LQueue*)new (LQueue);
    Init_LQueue();
    //����ջ�洢��λ����Ϣ
    SeqStack* se = (SeqStack*)new (SeqStack);
    Init_SeqStack();
    while (1) {
        int i;
        cout << "��ѡ����ķ�����";
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