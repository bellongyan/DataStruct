/**
 * @file: LinkQueue.cpp
 * @brief:
 * @author: Long Yan
 * @date: 2023-05-15
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct LinkNode
{
    int data;
    struct LinkNode *next;
} LinkNode;

typedef struct LinkQueue
{
    LinkNode *front, *rear;
} LinkQueue;

void InitQueue(LinkQueue &Q)
{
    Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}

bool Empty(LinkQueue Q)
{
    if (Q.front == Q.rear)
    {
        return true;
    }
    return false;
}

void EnQueue(LinkQueue &Q, int x)
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;
}

bool DeQueue(LinkQueue &Q, int &x)
{
    if (Q.front == Q.rear)
    {
        return false;
    }
    LinkNode *p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    if (Q.rear = p)
    {
        Q.rear = Q.front;
    }
    free(p);
    return true;
}



int main()
{

    return 0;
}
