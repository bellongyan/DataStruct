/**
 * @file: NPM
 * @brief: 朴素模式匹配算法
 * @author: Long Yan
 * @date: 2023-05-28
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 255

typedef struct {
    char ch[MAXLEN];
    int length;
} SString;

int Index(SString S, SString T) {
    int i = 1, j = 1;
    while (i <= S.length && j <= T.length) {
        if (S.ch[i] == T.ch[j]) {
            ++i;
            ++j;
        } else {
            i = i - j + 2;
            j = 1;
        }
    }
    if (j > T.length)
        return i - T.length;
    else
        return 0;
}

int main() {
    SString S, T;
    S.length = 5;
    T.length = 2;
    S.ch[1] = 'a';
    S.ch[2] = 'b';
    S.ch[3] = 'c';
    S.ch[4] = 'd';
    S.ch[5] = 'e';

    T.ch[1] = 'c';
    T.ch[2] = 'd';

    printf("%d\n", Index(S, T));

    return 0;
}