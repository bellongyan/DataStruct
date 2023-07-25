/**
 * @file SeStack.cpp
 * @brief: 顺序栈的实现
 * @author: Long Yan
 * @date: 2023-05-12
 *
 **/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

typedef struct {
    int data[MAXSIZE];
    int top;
} SqStack;

void InitStack(SqStack &S) {
    S.top = -1;
}

// 判断空栈
bool Empty(SqStack S) {
    if (S.top == -1) {
        return true;
    } else {
        return false;
    }
}

// 入栈
bool Push(SqStack &S, int x) {
    if (S.top == MAXSIZE - 1) {
        return false;
    }
    // 等价于 S.data[++S.top] = x;
    // 但是不能写成 S.data[S.top++] = x;
    S.top = S.top + 1;
    S.data[S.top] = x;

    return true;
}

// 出栈
bool Pop(SqStack &S, int &e) {
    if (S.top == -1) {
        return false;
    }
    // 等价于 x = S.data[S.top--];
    // 但是不能写成 x = S.data[--S.top];
    e = S.data[S.top];
    S.top--;
    return true;
}

// 获取栈顶元素
bool GetTop(SqStack S, int &e) {
    if (S.top == -1) {
        return false;
    }
    e = S.data[S.top];

    return true;
}

int main() {
    SqStack S;
    InitStack(S);
    Push(S, 1);
    Push(S, 2);

    // print all elements in stack
    for (int i = 0; i <= S.top; i++) {
        printf("%d ", S.data[i]);
    }

    return 0;
}
