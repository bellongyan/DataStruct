/**
 * @file: BinaryTree
 * @brief: 二叉树
 * @author: Long Yan
 * @date: 2023-05-31
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ElemType
{
    int value;
};

typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void Visit(BiTNode *p);

void PreOrder(BiTree T)
{
    if (T != NULL)
    {
        Visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

void InOrder(BiTree T){
    if (T != NULL)
    {
        PreOrder(T->lchild);
        Visit(T);
        PreOrder(T->rchild);
    }
}

void PostOrder(BiTree T){
    if (T != NULL)
    {
        PreOrder(T->lchild);
        PreOrder(T->rchild);
        Visit(T);
    }
}

int main()
{
    BiTree root = NULL;
    root = (BiTree)malloc(sizeof(BiTNode));
    root->data = {1},
    root->lchild = NULL;
    root->rchild = NULL;

    BiTNode *p = (BiTNode *)malloc(sizeof(BiTNode));
    p->data = {2};
    p->lchild = NULL;
    p->rchild = NULL;

    root->lchild = p;
    return 0;
}