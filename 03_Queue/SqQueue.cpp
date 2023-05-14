/**
 * @file: SqQueue.cpp
 * @brief: 顺序队列
 * @author: Long Yan
 * @date: 2023-05-14
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 10

typedef struct SqQueue
{
    int data[MAXSIZE];
    int front, rear;
} SqQueue;

void InitQueue(SqQueue &Q)
{
    Q.rear = Q.front = 0;
}

bool QueueEmpty(SqQueue Q)
{
    if (Q.rear == Q.front)
    {
        return true;
    }
    return false;
}

bool EnQueue(SqQueue &Q, int e)
{
    if ((Q.rear + 1) % MAXSIZE == Q.front)
    {
        return false;
    }

    Q.data[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXSIZE;
    return true;
}

bool DeQueue(SqQueue &Q, int &e)
{
    if (Q.rear == Q.front)
    {
        return false;
    }
    e = Q.data[Q.front];
    Q.front = (Q.front + 1) % MAXSIZE;
    return true;
}

bool GetHead(SqQueue Q, int &x)
{
    if (Q.front == Q.rear)
    {
        return false;
    }

    x = Q.data[Q.front];
    return true;
}

// 队列的元素个数
// (Q.rear + MAXSIZE - Q.front) % MAXSIZE;

int main()
{

    return 0;
}
