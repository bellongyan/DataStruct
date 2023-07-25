/**
 * @file: ShStack.cpp
 * @brief: 共享栈
 * @author: Long Yan
 * @date: 2023-05-12
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

typedef struct ShStack {
    int data[MAXSIZE];
    int top0;
    int top1;
} ShStack;

void InitStack(ShStack &S) {
    S.top0 = -1;
    S.top1 = MAXSIZE;
}

// 判断空栈
bool Empty(ShStack S) {
    if (S.top0 == -1 && S.top1 == MAXSIZE) {
        return true;
    } else {
        return false;
    }
}

// 判断栈满了
bool Full(ShStack S) {
    if (S.top0 + 1 == S.top1) {
        return true;
    } else {
        return false;
    }
}

int main() {

    return 0;
}
