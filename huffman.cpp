/*************************************************************************
	> File Name: huffman.cpp
	> Author:yuxiaowei 
	> Mail:1147407739@qq.com 
	> Created Time: 2018年10月28日 星期日 20时01分21秒
 ************************************************************************/

#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<inttypes.h>
using namespace std;

typedef struct Node {
    int key, freq;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(int key, int freq) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->freq = freq;
    p->lchild = p->rchild = NULL;
    return p;
}

void clear(Node *root) {
    if (root == NULL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

int swap_node(Node **p, Node **q) {
    Node *temp = *p;
    *p = *q;
    *q = temp;
    return 1;
}

Node *build_huffman(Node **arr, int n) { 
    Node INIT_NODE = {0, INT32_MAX, NULL, NULL};
    Node *first = &INIT_NODE, *second = &INIT_NODE;
        //合并n-1次
        //最小频率放在末尾
        for (int i = 0; i < n - 1; i++) {
            int ind1 = arr[0]->freq > arr[1]->freq;
            int ind2 = arr[0]->freq <= arr[1]->freq;
            for (int j = 2; j < n - i; j++) {
                if (arr[j]->freq <= arr[ind1]->freq) {
                    ind2 = ind1;
                    ind1 = j;
                } else if (arr[j]->freq < arr[ind2]->freq) {
                    ind2 = j;
                }//找到了最小频率的两个节点
            }
            printf("first:%c %d, second:%c %d\n", arr[ind1]->key, arr[ind1]->freq, arr[ind2]->key, arr[ind2]->freq);
            Node *temp = getNewNode(0, arr[ind2]->freq + arr[ind1]->freq);
            temp->lchild = arr[ind1];
            temp->rchild = arr[ind2];
            swap_node(arr + n - i - 1, arr + ind1);
            swap_node(arr + n - i - 2, arr + ind2);
            arr[n - i - 2] = temp;
        }
    return arr[0];
}

void extract_code(Node *root, char (*code)[20], int k, char *buff) {
    buff[k] = 0;
    if (root->key) {
        strcpy(code[root->key], buff);
        return ;
    }
    buff[k] = '0';
    extract_code(root->lchild, code, k + 1, buff);
    buff[k] = '1';
    extract_code(root->rchild, code, k + 1, buff);
    return ;
}

int main() {
    int n;
    scanf("%d", &n);
    Node **arr = (Node **)malloc(sizeof(Node *) * n);
    Node *root;
    for (int i = 0; i < n; i++) {
        char key[10];
        int freq;
        scanf("%s%d", key, &freq);
        arr[i] = getNewNode(key[0], freq);
    }
    root = build_huffman(arr, n);
    char code[256][20] = {0}, buff[20];
    extract_code(root, code, 0, buff);//层号第ｉ层对应第ｉ位
    for (int i = 0; i < 256; i++) {
        if (code[i][0] == 0) continue;
            printf("%c : %s\n", i, code[i]);
    } 
    return 0;
}
