/**
 * @file SeList.cpp
 * @brief: 顺序表动态分配
 * @author: Long Yan
 * @date: 2023-05-08 19:24:04
 *
 **/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define InitSize 10

typedef struct
{
	int *data;
	int MaxSize;
	int length;
} SqList;

// 初始化顺序表
void InitList(SqList &L)
{
	L.data = (int *)malloc(InitSize * sizeof(int));
	L.length = 0;
	L.MaxSize = InitSize;
}

// 增加动态数组的长度
void IncreaseSize(SqList &L, int len)
{
	int *p = L.data;
	L.data = (int *)malloc((L.length + len) * sizeof(int));
	for (int i = 0; i < L.length; i++)
	{
		L.data[i] = p[i];
	}
	L.MaxSize = L.MaxSize + len;
	free(p);
}

// 插入操作
bool ListInsert(SqList &L, int i, int e)
{
	// 位序合法性判断和空间剩余判断
	if (i < 1 || i > L.length + 1)
	{
		return false;
	}
	if (L.length >= L.MaxSize)
	{
		return false;
	}

	// 执行插入操作
	for (int j = L.length; j >= i; j--)
	{
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;
	L.length++;

	return true;
}

// 删除操作
bool ListDelete(SqList &L, int i, int &e)
{
	if (i < 1 || i > L.length + 1)
	{
		return false;
	}

	if (L.length == 0)
	{
		return false;
	}

	// 执行删除操作
	e = L.data[i - 1];
	for (int j = i - 1; j <= L.length; j++)
	{
		L.data[j - 1] = L.data[j];
	}
	L.length--;

	return true;
}

// 按位查找操作
int GetElem(SqList L, int i)
{
	return L.data[i - 1];
}

// 按值查找
int LocateElem(SqList L, int e)
{
	for (int i = 0; i < L.length; i++)
	{
		if (L.data[i] == e)
		{
			return i + 1;
		}
	}
	return 0;
}

// 打印顺序表元素
void Print(SqList L)
{
	if (L.length == 0)
	{
		printf("顺序表为空表");
	}
	else
	{
		for (int i = 0; i < L.length; i++)
		{
			if (i != L.length - 1)
			{
				printf("%d ", L.data[i]);
			}
			else
			{
				printf("%d\n", L.data[i]);
			}
		}
	}
}

int main()
{
	SqList L;
	InitList(L);

	int e;
	if (ListDelete(L, 1, e))
	{
		printf("删除的数为：%d\n", e);
	}
	else
	{
		printf("删除失败\n");
	}

	// 插入数据
	ListInsert(L, 1, 1);
	ListInsert(L, 1, 2);
	ListInsert(L, 1, 3);
	ListInsert(L, 1, 4);
	ListInsert(L, 1, 5);

	Print(L);

	// 删除数据
	if (ListDelete(L, 1, e))
	{
		printf("删除的数为：%d\n", e);
	}
	else
	{
		printf("删除失败\n");
	}
	Print(L);
	return 0;
}
