//
// Created by 46172 on 2020/12/18.
//
#include "stack_line.h"
Stack *creatStack() {//创建栈
    Stack *s = (Stack *) malloc(sizeof(Stack));
    s->num = (int *) malloc(sizeof(int) * STACK_DEFAULT_CAPACITY);
    s->size = 0;
    s->capacity = STACK_DEFAULT_CAPACITY;
    return s;
}

void expand(Stack *s) {//扩容
    if (s->size < s->capacity)
        return;
    int *old = s->num;
    s->num = (int *) malloc(sizeof(int) * (s->capacity << 1));
    memcpy(s->num, old, sizeof(int)*s->size);
    s->capacity <<= 1;
    free(old);
}

void shrink(Stack *s) {//缩容
    if (s->size >= s->capacity >> 2 || s->capacity < STACK_DEFAULT_CAPACITY)//缩容，并防止缩到默认容量以下
        return;
    int *old = s->num;
    s->num = (int *) malloc(sizeof(int) * (s->capacity >> 1));
    memcpy(s->num, old, sizeof(int)*s->size);
    s->capacity >>= 1;
    free(old);
}

int stackIsEmpty(Stack *s) {//判断是否栈空,1空，0非空
    return s->size == 0;
}

void stackPushBack(Stack *s, int num) {//入栈
    expand(s);
    s->num[s->size] = num;
    s->size++;
    return;
}

int stackPop(Stack *s) {//出栈
    if (stackIsEmpty(s))
        return -1;
    int temp = s->num[s->size - 1];
    s->size--;
    shrink(s);
    return temp;
}

int stackTop(Stack *s) {//查看栈顶
    if (!stackIsEmpty(s))
        return s->num[s->size - 1];
    else
        return -1;
}

void stackFree(Stack *s) {//释放栈，栈存储的内容和栈本身均释放，无需手动free
    if (!s->num)
        free(s->num);
    if (!s)
        free(s);
}