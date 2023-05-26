/**
 * @file DLinkList.cpp 
 * @brief: 双链表
 * @author: Long Yan
 * @date: 2023-05-09 10:42:56
 * 
 **/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct DNode {
	int data;
	struct DNode *prior, *next;
} DNode, *DLinkList;

// 初始化双链表
bool InitDLinkList(DLinkList L) {
	L = (DLinkList)malloc(sizeof(DNode));
	if (L == NULL) {
		return false;
	}
	L->next = NULL, L->prior = NULL;
	return true;
}

// 双链表的插入
bool InsertNextDNode(DNode *p, DNode *s) {
	if (p == NULL || s == NULL) {
		return false;
	}
	s->next = p->next;
	if (p->next != NULL) {
		p->next->prior = s;

	}
	s->prior = p;
	p->next = s;
	return true;
}

// 删除 p 节点的后继节点
bool DeleteNextDNode(DNode*p) {
	if (p == NULL) {
		return false;
	}
	DNode *q = p->next;
	if (q == NULL) {
		return false;
	}
	p->next = q->next;
	if (q->next != NULL) {
		q->next->prior = p;
	}
	free(q);
	return true;
}

// 双链表的删除
void DestoryList(DLinkList &L) {
	while (L->next != NULL) {
		DeleteNextDNode(L);
	}
	free(L);
	L = NULL;
}

// 判断空表
bool Empty(DLinkList L) {
	if (L->next == NULL) {
		return true;
	} else {
		return false;
	}
}

int main() {


	return 0;
}
