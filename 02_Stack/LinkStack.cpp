/**
 * @file: LinkStack.cpp
 * @brief: ��ջʵ��
 * @author: Long Yan
 * @date: 2023-05-12
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} LinkNode, *LinkStack;

void InitStack(LinkStack &S) {
    S = NULL;
}

bool Empty(LinkStack S) {
    return (S == NULL);
}

// ��ջ
bool Push(LinkStack &S, int e) {
    LinkNode *h;
    h = (LinkNode *)malloc(sizeof(LinkNode));
    if (Empty(h)) {
        return false;
    }
    h->data = e;
    h->next = S;
    S = h;
    return true;
}

// ��ջ
bool Pop(LinkStack &S) {
    if (Empty(S)) {
        return false;
    }

    LinkNode *h = S;
    S = S->next;
    free(h);
    return true;
}

// ��ջ��Ԫ��
bool GetTop(LinkStack S, int &e) {
    if (Empty(S)) {
        return false;
    }
    e = S->data;
    return true;
}

// ���ջԪ��
void PrintStack(LinkStack S) {
    LinkNode *h = S;
    while (h != NULL) {
        printf("%d ", h->data);
        h = h->next;
    }
    printf("\n");
}

int main() {
    LinkStack S;
    InitStack(S);
    Push(S, 1);
    Push(S, 2);
    Push(S, 3);
    Push(S, 4);

    PrintStack(S);

    int e;
    GetTop(S, e);
    printf("ջ��Ԫ��Ϊ��%d\n", e);

    Pop(S);
    PrintStack(S);
    return 0;
}
