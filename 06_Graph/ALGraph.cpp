/**
 * @file: ALGraph
 * @brief: 图的邻接表存储结构
 * @author: Long Yan
 * @date: 2023-06-19
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAXVERTEXNUM 100

typedef struct ArcNode
{
    int adjvex;
    struct ArcNode *nextarc;
    // InfoType info;
} ArcNode;

typedef struct VNode
{
    int data;
    ArcNode *first;
} VNode, AdjList[MAXVERTEXNUM];

typedef struct
{
    AdjList vertices;
    int vexnum, arcnum;
} ALGraph;

int main(){
    
    return 0;
}