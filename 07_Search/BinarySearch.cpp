/**
 * @file: BinarySearch
 * @brief: 折半查找（二分查找）
 * @author: Long Yan
 * @date: 2023-06-27
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAXSIZE 10

typedef int ElemType;
typedef struct{
    ElemType *elem;
    int Tablelen;
}SSTable;

int BinarySearch(SSTable L, ElemType key){
    int low = 0, high = L.Tablelen - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (L.elem[mid] == key)
        {
            return mid;
        }
        else if (L.elem[mid] > key)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }       
    }
    return -1;
}
int main(){
    SSTable L;
    L.elem = (ElemType *)malloc(MAXSIZE * sizeof(ElemType));
    L.Tablelen = MAXSIZE;
    for (int i = 0; i < MAXSIZE; i++)
    {
        L.elem[i] = i;
    }
    int result = BinarySearch(L, 5);
    printf("%d\n", result);
        
    return 0;
}