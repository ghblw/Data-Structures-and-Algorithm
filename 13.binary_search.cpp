/*************************************************************************
	> File Name: 13.binary_search.cpp
	> Author:yuxiaowei 
	> Mail:1147407739@qq.com 
	> Created Time: 2018年11月08日 星期四 00时53分26秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#define P(func) {\
    printf("%s= %d\n", #func, func);\
}

//1 2 3 4 5 6
int binary_search1(int *num, int n, int x) {
    int head = 0, tail = n - 1, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (num[mid] == x) return mid;
        if (num[mid] > x) tail = mid - 1;
        else head = mid + 1;
    }
    return -1;
}

//11111000000
int binary_search2(int *num, int n) {
    int head = -1, tail = n - 1, mid;//虚拟节点
    while (head < tail) {//要找到最后一个1的位置，并不是等于某个值的元素，只剩下一个元素说明找到了
        mid = (head + tail + 1) >> 1;
        if (num[mid] == 1) head = mid;
        else tail = mid - 1;
    }
    return head;
}

//000000111111
int binary_search3(int *num, int n) {
    int head = 0, tail = n, mid;
    while (head < tail) {
        mid = (head + tail) >> 1;
        if (num[mid] == 1) tail = mid;
        else head = mid + 1;
    }
    return head == n ? -1 : head;
}

int main() {
    int arr1[10] = {1, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    int arr2[10] = {1, 1, 1, 0, 0, 0, 0, 0, 0, 0};
    int arr3[10] = {0, 0, 0, 0, 0, 0, 1, 1, 1, 1};
    P(binary_search1(arr1, 10, 11));
    P(binary_search2(arr2, 10));
    P(binary_search3(arr3, 10));
    return 0;
}
