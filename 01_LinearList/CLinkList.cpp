/**
 * @file CLinkList.cpp
 * @brief: 循环单链表
 * @author: Long Yan
 * @date: 2023-05-09 10:43:06
 *
 **/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct CNode {
    int data;
    struct CNode *next;
} CNode, *CLinkList;

// 初始化循环单链表
bool InitCLinkList(CLinkList L) {
    L = (CNode *)malloc(sizeof(CNode));
    if (L == NULL) {
        return false;
    }
    L->next = L;
    return true;
}

// 判断空链表
bool empty(CLinkList L) {
    if (L->next == L) {
        return true;
    } else {
        return true;
    }
}

// 判断节点 p 是否是表尾节点
bool isTail(CLinkList L, CNode *p) {
    if (p->next == L) {
        return true;
    } else {
        return false;
    }
}

int main() {

    return 0;
}
