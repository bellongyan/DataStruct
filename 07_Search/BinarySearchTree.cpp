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

int main()
{

    return 0;
}