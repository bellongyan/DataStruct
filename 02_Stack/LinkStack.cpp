/**
 * @file: LinkStack.cpp
 * @brief: 链栈实现
 * @author: Long Yan
 * @date: 2023-05-12
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct LinkNode
{
    int data;
    struct LinkNode *next;
} LinkNode, *LinkStack;

void InitStack(LinkStack &S)
{
    S = NULL;
}

bool Empty(LinkStack S)
{
    return (S == NULL);
}

// 进栈
bool Push(LinkStack &S, int e)
{
    LinkNode *h;
    h = (LinkNode *)malloc(sizeof(LinkNode));
    if (Empty(h))
    {
        return false;
    }
    h->data = e;
    h->next = S;
    S = h;
    return true;
}

// 出栈
bool Pop(LinkStack &S)
{
    if (Empty(S))
    {
        return false;
    }

    LinkNode *h = S;
    S = S->next;
    free(h);
    return true;
}

// 读栈顶元素
bool GetTop(LinkStack S, int &e)
{
    if (Empty(S))
    {
        return false;
    }
    e = S->data;
    return true;
}

// 输出栈元素
void PrintStack(LinkStack S)
{
    LinkNode *h = S;
    while (h != NULL)
    {
        printf("%d ", h->data);
        h = h->next;
    }
    printf("\n");
}

int main()
{
    LinkStack S;
    InitStack(S);
    Push(S, 1);
    Push(S, 2);
    Push(S, 3);
    Push(S, 4);

    PrintStack(S);

    int e;
    GetTop(S, e);
    printf("栈顶元素为：%d\n", e);

    Pop(S);
    PrintStack(S);
    return 0;
}
