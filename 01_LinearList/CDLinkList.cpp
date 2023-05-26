/**
 * @file CDLinkList.cpp
 * @brief: 循环双链表
 * @author: Long Yan
 * @date: 2023-05-09 10:54:32
 *
 **/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct CDNode {
	int data;
	struct CDNode *prior, *next;
} CDNode, *CDLinkList;

// 初始化双链表
bool InitCDLinkList(CDLinkList L) {
	L = (CDNode *)malloc(sizeof(CDNode));
	if (L == NULL) {
		return false;
	}
	L->next = L, L->prior = L;
	return true;
}

bool InsertNextCDNode(CDNode*p, CDNode*s) {
	if (p == NULL || s == NULL) {
		return false;
	}
	s->next = p->next;
	p->next->prior = s;
	s->prior = p;
	p->next = s;

	return true;


}

int main() {

	return 0;
}
