/**
 * @file: LevelOrder
 * @brief: 层次遍历
 * @author: Long Yan
 * @date: 2023-05-31
 */

#include <queue>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct ElemType {
    int value;
};

typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void Visit(BiTNode *p) {
    printf("%d ", p->data);
}

void LevelOrder(BiTree T) {
    std::queue<BiTree> Q;
    BiTree p;
    Q.push(T);
    while (!Q.empty()) {
        p = Q.front();
        Q.pop();

        Visit(p);

        if (p->lchild != NULL) {
            Q.push(p->lchild);
        }
        if (p->rchild != NULL) {
            Q.push(p->rchild);
        }
    }
}

int main() {
    // 构建一个二叉树
    BiTree root;

    root = (BiTree)malloc(sizeof(BiTNode));
    root->data = {1}, root->lchild = NULL;
    root->rchild = NULL;

    BiTNode *node1 = (BiTNode *)malloc(sizeof(BiTNode));
    BiTNode *node2 = (BiTNode *)malloc(sizeof(BiTNode));
    BiTNode *node3 = (BiTNode *)malloc(sizeof(BiTNode));
    BiTNode *node4 = (BiTNode *)malloc(sizeof(BiTNode));
    BiTNode *node5 = (BiTNode *)malloc(sizeof(BiTNode));

    node1->data = {2}, node1->lchild = NULL, node1->rchild = NULL;
    node2->data = {3}, node2->lchild = NULL, node2->rchild = NULL;
    node3->data = {4}, node3->lchild = NULL, node3->rchild = NULL;
    node4->data = {5}, node4->lchild = NULL, node4->rchild = NULL;
    node5->data = {6}, node5->lchild = NULL, node5->rchild = NULL;

    root->lchild = node1, root->rchild = node2;
    node1->lchild = node3, node1->rchild = node4;
    node2->lchild = node5, node2->rchild = NULL;

    // 执行层次遍历
    LevelOrder(root);

    return 0;
}