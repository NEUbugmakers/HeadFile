//
// Created by 46172 on 2020/12/18.
//

#ifndef HEADFILE_STACK_LINE_H
#define HEADFILE_STACK_LINE_H
#include <stdlib.h>
#include <string.h>

#define STACK_DEFAULT_CAPACITY 4
typedef struct {
    int *num;
    int size;
    int capacity;
} Stack;

Stack *creatStack();//栈创建

void expand(Stack *s);//扩容

void shrink(Stack *s);//缩容

int stackIsEmpty(Stack *s);//是否栈空

void stackPushBack(Stack *s, int num);//入栈

int stackPop(Stack *s);//出栈

int stackTop(Stack *s);//查看栈顶

void stackFree(Stack *s);//删除栈

#endif //HEADFILE_STACK_LINE_H
