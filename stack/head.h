#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <string>

using namespace  std;
struct LNode{
    int data;
    struct LNode * next;
};

struct SNode{
    int data;
    struct SNode *next;
};

struct LStack{
    struct SNode * base;//指向栈底的指针
    struct SNode * top;//指向栈顶的指针
};



struct LNode * InitQuene();//初始化链式队列，返回头指针

//元素入列,返回尾指针
struct LNode* putQuene(struct LNode* rear, int data);

//元素出列
void DeQuene(struct LNode* top,struct LNode* rear);

//销毁链式队列

struct LStack* Stack_create();//创建一个空的栈表头

struct LStack* InitStack(struct LStack * stack);//初始化链式栈结构，返回

//元素入栈
struct LStack* pushStack(struct LStack * stack,int e);

//元素出栈
struct LStack* popStack(struct LStack *stack,int &e);

//判断栈为空
bool judge0Stack(struct LStack * stack );



struct LNode * InitQuene(){
    struct LNode * quene= (struct LNode*)malloc(sizeof(struct LNode));
    quene->next = NULL;
    return quene;
}

struct LNode* putQuene(struct LNode* rear, int data){
    struct LNode* putElem=(struct LNode*)malloc(sizeof(struct LNode));
    putElem->data=data;
    putElem->next = NULL;
    rear->next = putElem;
    rear=putElem;
    return rear;
}

void DeQuene(struct LNode* top,struct LNode* rear){
    if(top->next == NULL){
        printf("队列为空\n");
        return ;
    }
    struct LNode* p = top->next;
    printf("%d\n",p->data);
    top->next = p->next;
    if(rear == p){
        rear = top;
    }
    free(p);
}

struct LStack* Stack_create(){
    struct LStack * stack = (struct LStack * )malloc(sizeof(struct LStack));
    stack->base = stack->top = NULL;
    return stack;
}

struct LStack* InitStack(struct LStack * stack){
    struct SNode * snode = (struct SNode *)malloc(sizeof(struct SNode));
    snode->data = -100000000;
    stack->base = snode;
    snode->next = NULL;
    stack->top = stack->base;
    return stack;
}

struct LStack* pushStack(struct LStack * stack,int e){
    if(stack->base == NULL){//栈结构不存在
        exit(-1);
    }
    stack->top->data = e;//赋值
    struct SNode * snode = (struct SNode *)malloc(sizeof(struct SNode));
    if(snode == NULL){
        exit(-1);
    }
    snode->next = NULL;
    stack->top->next = snode;
    stack->top = snode;

    return stack;
}

struct LStack* popStack(struct LStack *stack,int &e){
    if (stack->top == stack->base){//空栈
        return stack;
    }
    struct SNode * p = stack->base;
    while ( p->next != stack->top ){
        p = p->next;
    }
    e = p->data;

    struct SNode * q = p->next;
    p->next = NULL;
    stack->top = p;
    free(q);
    q = NULL;
    return stack;
}

bool judge0Stack(struct LStack * stack ){
    if ((stack->top == stack->base) ){
        return true;
    }else{
        return false;
    }

}



