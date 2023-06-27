/**
 * @file: BinarySearchTree
 * @brief: 二叉排序树（二叉搜索树）
 * @author: Long Yan
 * @date: 2023-06-27
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;
typedef struct BSTNode
{
    int key;
    struct BSTNode *lchild, *rchild;
} BSTNode, *BSTree;

// 二叉排序树的查找
BSTNode *BSTSearch(BSTree T, ElemType key)
{
    while (T != NULL && key != T->key)
    {
        if (key < T->key)
        {
            T = T->lchild;
        }
        else
        {
            T = T->rchild;
        }
    }
    return T;
}

// 二叉排序树的插入
int BSTInsert(BSTree &T, ElemType key)
{
    if (T == NULL)
    {
        T = (BSTree)malloc(sizeof(BSTNode));
        T->key = key;
        T->lchild = T->rchild = NULL;
        return 1;
    }
    else if (key == T->key)
    {
        return 0;
    }
    else if (key < T->key)
    {
        return BSTInsert(T->lchild, key);
    }
    else
    {
        return BSTInsert(T->rchild, key);
    }
}

// 二叉排序树的构造
void CreateBST(BSTree &T, ElemType str[], int n)
{
    T = NULL;
    int i = 0;
    while (i < n)
    {
        BSTInsert(T, str[i]);
        i++;
    }
}

int main()
{

    return 0;
}