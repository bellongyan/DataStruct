/**
 * @file LinkList.cpp
 * @brief: 单链表
 * @author: Long Yan
 * @date: 2023-05-08 20:12:05
 *
 **/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct LNode
{
	int data;
	struct LNode *next;
} LNode, *LinkList;

// typedef struct LNode Lnode;
// typedef struct LNode *LinkList;

// LNode *L <==> LinkList L

// 初始化链表
bool InitList(LinkList &L)
{
	L = (LNode *)malloc(sizeof(LNode));
	if (L == NULL)
	{
		return false;
	}
	L->next = NULL;
	return true;
}

// 判断空表
bool Empty(LinkList L)
{
	return (L->next == NULL);
}

// 按位查找
LNode *GetElem(LinkList L, int i)
{
	if (i < 0)
	{
		return NULL;
	}
	LNode *p;
	int j = 0;
	p = L;
	while (p != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	return p;
}

// 按值查找
LNode *LocateElem(LinkList L, int e)
{
	LNode *p = L->next;
	while (p != NULL && p->data != e)
	{
		p = p->next;
	}
	return p;
}

// 后插操作：在 p 节点之后插入元素
bool InsertNextNode(LNode *p, int e)
{
	if (p == NULL)
	{
		return false;
	}

	// 内存分配失败的情况
	LNode *s = (LNode *)malloc(sizeof(LNode));
	if (s == NULL)
	{
		return false;
	}

	s->data = e;
	s->next = p->next;
	p->next = s;

	return true;
}

// 头插法
bool InsertPriorNode(LNode *p, int e)
{
	if (p == NULL)
	{
		return false;
	}

	// 内存分配失败的情况
	LNode *s = (LNode *)malloc(sizeof(LNode));
	if (s == NULL)
	{
		return false;
	}

	s->next = p->next;
	p->next = s;
	p->data = s->data;
	s->data = e;

	return true;
}

// 王道书头插法
bool InsertPriorNode(LNode *p, LNode *s)
{
	if (p == NULL || s == NULL)
	{
		return false;
	}
	s->next = p->next;
	p->next = s;
	int temp = p->data;
	p->data = s->data;
	s->data = temp;

	return true;
}

// 按位序插入
bool ListInsert(LinkList &L, int i, int e)
{
	if (i < 1)
	{
		return false;
	}
	//	int j = 0; //  p 指向的是第几个结点
	//	LNode *p;
	//	p = L;
	//	while ((p != NULL) && (j < i - 1)) { // 循环找到第 i - 1 个节点
	//		p = p->next;
	//		j++;
	//	}
	LNode *p = GetElem(L, i - 1);

	return InsertNextNode(p, e);
}

// 按位序删除
bool ListDelete(LinkList &L, int i, int &e)
{
	// 同插入操作前半段
	LNode *p = GetElem(L, i - 1);

	if (p == NULL)
	{
		return false;
	}
	if (p->next == NULL)
	{
		return false;
	}
	LNode *q = p->next;
	e = q->data;
	p->next = q->next;
	free(q);
	return false;
}

bool DeleteNode(LNode *p)
{
	if (p == NULL)
	{
		return false;
	}

	// 存在 bug，当 p 节点为最后一个节点时，会删除出错，因为 q = NULL, 无法获得 q->data
	// 只能从表头开始一次寻找 p 的前驱
	LNode *q = p->next;
	p->data = p->next->data;
	p->next = q->next;
	free(q);

	return true;
}

// 表长
int Length(LinkList L)
{
	int len = 0;
	LNode *p = L;
	while (p->next != NULL)
	{
		p = p->next;
		len++;
	}
	return len;
}

void Print(LNode *L)
{
	LNode *h = L->next;
	if (h == NULL)
	{
		printf("该链表为空表\n");
		return;
	}
	while (h != NULL)
	{
		printf("%d ", h->data);
		h = h->next;
	}
	printf("\n");
}

// 尾插法建立单链表
LinkList List_TailInsert(LinkList &L)
{
	int x;
	L = (LinkList)malloc(sizeof(LNode));
	LNode *s, *r = L;
	scanf("%d", &x);
	while (x != 9999)
	{
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		scanf("%d", &x);
	}
	r->next = NULL;
	return L;
}

// 头插法建立单链表
LinkList List_HeadInsert(LinkList &L)
{
	int x;
	LNode *s;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	scanf("%d", &x);
	while (x != 9999)
	{
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d", &x);
	}
	return L;
}

int main()
{
	LNode *L;
	InitList(L);
	ListInsert(L, 1, 1);
	ListInsert(L, 1, 2);
	ListInsert(L, 1, 3);
	Print(L);
	InsertPriorNode(L, 4);
	Print(L);

	return 0;
}
