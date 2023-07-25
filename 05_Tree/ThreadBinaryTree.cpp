/**
 * @file: ThreadBinaryTree
 * @brief: 中序线索二叉树
 * @author: Long Yan
 * @date: 2023-06-06
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct ElemType {
    int value;
};

typedef struct ThreadNode {
    ElemType data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag; // tag为0时指针指向孩子，tag为1时指针指向线索
} ThreadNode, *ThreadTree;

ThreadNode *pre = NULL;

void CreateInThread(ThreadTree T) {
    pre = NULL;
    if (T != NULL) {
        InThread(T);
        if (pre->rchild == NULL) {
            pre->rtag = 1;
        }
    }
}

void Visit(ThreadNode *q) {
    if (q->lchild == NULL) {
        q->lchild = pre;
        q->ltag = 1;
    }
    if (pre != NULL && pre->rchild == NULL) {
        pre->rchild = q;
        pre->rtag = 1;
    }
    pre = q;
}

void InThread(ThreadTree T) {
    if (T != NULL) {
        InThread(T->lchild);
        Visit(T);
        InThread(T->rchild);
    }
}

int main() {

    return 0;
}