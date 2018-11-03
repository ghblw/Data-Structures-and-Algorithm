/*************************************************************************
	> File Name: Huffman3.cpp
	> Author:yuxiaowei 
	> Mail:1147407739@qq.com 
	> Created Time: 2018年11月01日 星期四 17时28分47秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Heap {
    int *data, size;
} Heap;

void init(Heap *h, int length_input) {
    h->data = (int *)malloc(sizeof(int) * length_input);
    h->size = 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void push(Heap *h, int value) {
    h->data[h->size] = value;
    int current = h->size;
    int father = (current - 1) / 2;
    while (h->data[current] < h->data[father]) {
        swap(&h->data[current], &h->data[father]);
        current = father;
        father = (current - 1) / 2;
    }
    h->size++;
}

int top(Heap *h) {
     return h->data[0];
}

void update(Heap *h, int pos, int n) {
    int lchild = 2 * pos + 1, rchild = 2 * pos + 2;
    int max_value = pos;
    if (lchild < n && h->data[lchild] < h->data[max_value]) {
        max_value = lchild;
    }
    if (rchild < n && h->data[rchild] < h->data[max_value]) {
        max_value = rchild;
    }
    if (max_value != pos) {
        swap(&h->data[pos], &h->data[max_value]);
        update(h, max_value, n);
    }
}

void pop(Heap *h) {
    swap(&h->data[0], &h->data[h->size - 1]);
    h->size--;
    update(h, 0, h->size);
}

int heap_size(Heap *h) {
    return h->size;
}

void clear(Heap *h) {
    free(h->data);
    free(h);
}

int main() {
    int n, value, ans = 0;
    scanf("%d", &n);
    Heap *heap = (Heap *)malloc(sizeof(Heap));
	init(heap, n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &value);
        push(heap, value);
    }
    if (n == 1) {
     	ans += top(heap);
    }
    while (heap_size(heap) > 1) {
        int a = top(heap);
        pop(heap);
        int b = top(heap);
        pop(heap);
        ans = ans + a + b;
        push(heap, a + b);
    }
    printf("%d\n", ans);
    clear(heap);
    return 0;
}

