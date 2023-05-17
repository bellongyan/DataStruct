/**
 * @file: BracketCheck.cpp
 * @brief:
 * @author: Long Yan
 * @date: 2023-05-17
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 10

typedef struct SqStack
{
    char data[MAXSIZE];
    int top;
} SqStack;

void InitStack(SqStack &S)
{
    S.top = -1;
}

bool StackEmpty(SqStack S)
{
    return S.top == -1;
}

bool Push(SqStack &S, char x)
{
    if (S.top == MAXSIZE - 1)
    {
        return false;
    }

    S.top += 1;
    S.data[S.top] = x;
    return true;
}

bool Pop(SqStack &S, char &x)
{
    if (StackEmpty(S))
    {
        return false;
    }

    x = S.data[S.top];
    S.top -= 1;
    return true;
}

bool BrackCheck(char str[], int length)
{
    SqStack S;
    InitStack(S);
    for (int i = 0; i < length; i++)
    {
        if ((str[i] == '(') || (str[i] == '[') || (str[i] == '{'))
        {
            Push(S, str[i]);
        }
        else
        {
            if (StackEmpty(S))
            {
                return false;
            }

            char topElem;
            Pop(S, topElem);
            if ((str[i] == ')') && (topElem != '('))
            {
                return false;
            }
            if ((str[i] == ']') && (topElem != '['))
            {
                return false;
            }
            if ((str[i] == '}') && (topElem != '{'))
            {
                return false;
            }
        }
    }
    return StackEmpty(S);
}

int main()
{
    char str[] = "({[]})";
    int length = sizeof(str) / sizeof(str[0]) - 1;
    bool result = BrackCheck(str, length);
    printf("result: %d\n", result);

    char str2[] = "({[})";
    int length2 = sizeof(str2) / sizeof(str2[0]) - 1;
    bool result2 = BrackCheck(str2, length2);
    printf("result2: %d\n", result2);

    return 0;
}
