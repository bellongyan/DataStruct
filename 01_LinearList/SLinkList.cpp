/**
 * @file SLinkList.cpp
 * @brief: 静态链表
 * @author: Long Yan
 * @date: 2023-05-09
 *
 **/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10

typedef struct {
    int data;
    int next;
} SLinkList[MaxSize];

int main() {
    SLinkList a;
    printf("Size a = %lld\n", sizeof(a));

    return 0;
}
