/**
 * @file: HString
 * @brief: 堆分配
 * @author: Long Yan
 * @date: 2023-05-28
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 255

typedef struct {
    char *ch;
    int length;
} HString;

int main() {
    HString S;
    S.ch = (char *)malloc(sizeof(char) * MAXLEN);
    S.length = 0;

    return 0;
}