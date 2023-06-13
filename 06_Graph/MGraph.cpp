/**
 * @file: MGraph
 * @brief: 图的邻接矩阵存储结构
 * @author: Long Yan
 * @date: 2023-06-13
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXVERTEXNUM 100

typedef char VertexType;
typedef int EdgeType;
typedef struct
{
    VertexType Vex[MAXVERTEXNUM];
    EdgeType Edge[MAXVERTEXNUM][MAXVERTEXNUM];

    int vexnum, arcnum;
} MGraph;

int main()
{
    
    return 0;
}