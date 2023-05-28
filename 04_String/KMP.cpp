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

int IndexKMP(SString S, SString T, int next[])
{
    int i = 1, j = 1;
    while (i <= S.length && j <= T.length)
    {
        if (j == 0 || S.ch[i] == T.ch[i])
        {
            ++i, ++j; // 当前字符正确，比对下一个字符
        }
        else
        {
            j = next[j]; // 模式串向右移动
        }
    }
    if (j > T.length)
    {
        return i - T.length; // 匹配成功
    }
    else
    {
        return 0;
    }
}

int main()
{

    return 0;
}