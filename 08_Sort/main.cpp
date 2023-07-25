/**
 * @file: main
 * @brief: 测试排序算法
 * @author: Long Yan
 * @date: 2023-07-23
 */

#include "InsertSort.cpp"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int arr[20] = {73, 19, 32, 74, 21, 43, 23, 12, 54, 32, 65, 34, 76, 23, 54, 23, 65, 34, 76, 23};

    int resurt = InsertSort(arr, 20);

    for (int i = 0; i < 20; i++) {
        printf("%d ", arr[i]);
    }

    // output:
    // 12 19 21 23 23 23 23 32 32 34 34 43 54 54 65 65 73 74 76 76

    return 0;
}