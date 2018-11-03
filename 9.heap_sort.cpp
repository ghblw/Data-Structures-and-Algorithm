/*************************************************************************
	> File Name: 9.heap_sort.cpp
	> Author:yuxiaowei 
	> Mail:1147407739@qq.com 
	> Created Time: 2018年10月30日 星期二 20时27分54秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

#define swap(a, b) {\
    __typeof(a) __temp = a; a = b; b = __temp; \
}
void heap_sort(int *arr, int n) {
    //建堆，排序
    int *p = arr - 1;//p[1]->arr[0]
    for (int i = 2; i <= n; i++) {//蛮力算法
        int ind = i;
        while (ind > 1) {
            //从小到大排序，建立大顶堆
            //逐一入堆,自底向上调整
            if (p[ind] <= p[ind >> 1]) break;
            swap(p[ind], p[ind >> 1]);
            ind >>= 1;
        }
    }
    //弹堆
    for (int i = n; i > 1; i--) {
        swap(p[i], p[1]);
        int ind = 1;
        //自顶向下调整堆
        while ((ind << 1) <= i - 1) {//存在子节点
            int temp = ind;
            if (p[ind] < p[ind << 1]) temp = ind << 1;
            if ((ind << 2 | 1) <= i - 1 && p[temp] < p[ind << 1 | 1]) temp = ind << 1 | 1;
            if (temp == ind) break;
            swap(p[temp], p[ind]);
            ind = temp;
        }
    }
    return ;
}

void output(int *num, int n) {
    printf("Arr = [");
    for (int i = 0; i < n; i++) {
        printf(" %d", num[i]);
        i == n - 1 || printf(",");
    }
    printf("]\n");
    return ;
}

int main() {
    srand(time(0));
    #define MAX_N 20
    int arr[MAX_N];
    for (int i = 0; i < MAX_N; i++) arr[i] = rand() % 100;
    output(arr, MAX_N);
    heap_sort(arr, MAX_N);
    output(arr, MAX_N);
    return 0;
}
