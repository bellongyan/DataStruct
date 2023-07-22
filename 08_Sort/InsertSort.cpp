/**
 * @file: InsertSort
 * @brief: 插入排序
 * @author: Long Yan
 * @date: 2023-07-23
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int InsertSort(int arr[], int len)
{
    int temp = 0;
    int j = 0;

    for (int i = 1; i < len; i++)
    {
        temp = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = temp;
    }
    return *arr;
}