/**
 * @file: SString
 * @brief: 定长顺序存储
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

int StrLength(SString S) {
    return S.length;
}

bool StrEmpty(SString S) {
    return S.length == 0;
}

SString ClearString(SString S) {
    S.length = 0;
    return S;
}

bool SubString(SString &Sub, SString S, int pos, int len) {
    if (pos + len - 1 > S.length) {
        return false;
    }
    for (int i = pos; i < pos + len; i++) {
        Sub.ch[i - pos + 1] = S.ch[i];
    }
    Sub.length = len;
    return true;
}

bool StrCompare(SString S, SString T) {
    if (S.length != T.length) {
        return false;
    }
    for (int i = 1; i <= S.length; i++) {
        if (S.ch[i] != T.ch[i]) {
            return false;
        }
    }
    return true;
}

int Index(SString S, SString T) {
    int i = 1, n = StrLength(S), m = StrLength(T);
    SString sub;
    while (i <= n - m + 1) {
        SubString(sub, S, i, m);
        if (StrCompare(sub, T)) {
            return i;
        } else {
            i++;
        }
    }
    return 0;
}

int main() {
    SString S, T;
    S.length = 10;
    T.length = 2;

    S.ch[1] = 'a';
    S.ch[2] = 'b';
    S.ch[3] = 'c';
    S.ch[4] = 'd';
    S.ch[5] = 'e';
    S.ch[6] = 'f';
    S.ch[7] = 'g';
    S.ch[8] = 'h';
    S.ch[9] = 'i';
    S.ch[10] = 'j';

    T.ch[1] = 'c';
    T.ch[2] = 'd';

    printf("S.length:%d\n", StrLength(S));

    printf("S is empty?%d\n", StrEmpty(S));

    printf("S.ch:%s\n", S.ch);

    SString Sub;

    SubString(Sub, S, 3, 4);

    printf("Sub.ch:%s\n", Sub.ch);

    printf("Sub.length:%d\n", Sub.length);

    printf("StrCompare:%d\n", StrCompare(S, T));

    printf("Index:%d\n", Index(S, T));

    return 0;
}