/**
 * @file: KMP
 * @brief: 串的模式匹配算法
 * @author: Long Yan
 * @date: 2023-05-28
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXLEN 255

typedef struct
{
    char ch[MAXLEN];
    int length;
} SString;

void GetNext(SString T, int next[]){
    int i = 1, j = 0;
    next[1] = 0;
    while (i < T.length)
    {
        if (j == 0 || T.ch[i] == T.ch[j])
        {
            ++i, ++j;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
}

void GetNextval(SString T, int next[]){
    int i = 1, j = 0;
    next[1] = 0;
    while (i < T.length)
    {
        if (j == 0 || T.ch[i] == T.ch[j])
        {
            ++i, ++j;
            if (T.ch[i] != T.ch[j])
            {
                next[i] = j;
            }
            else
            {
                next[i] = next[j];
            }
        }
        else
        {
            j = next[j];
        }
    }
}

int IndexKMP(SString S, SString T, int next[])
{
    int i = 1, j = 1;
    while (i <= S.length && j <= T.length)
    {
        if (j == 0 || S.ch[i] == T.ch[j])
        {
            ++i;
            ++j;
        }
        else
        {
            j = next[j];
        }
    }
    if (j > T.length)
        return i - T.length;
    else
        return 0;
}

int main()
{
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

    int next[255];
    GetNext(T, next);
    printf("%d\n", IndexKMP(S, T, next));

    int nextval[255];
    GetNextval(T, nextval);
    printf("%d\n", IndexKMP(S, T, nextval));

    return 0;
}