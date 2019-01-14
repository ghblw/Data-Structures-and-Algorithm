/*************************************************************************
	> File Name: 17.ac.cpp
	> Author:yuxiaowei 
	> Mail:1147407739@qq.com 
	> Created Time: 2019年01月13日 星期日 20时44分32秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#define BASE 26
#define BEGIN_LETER 'a'

using std::cin;
using std::cout;
using std::endl;
using std::string;

typedef struct Node {
    int flag;
    struct Node *next[BASE], *fail;//比普通字典树多一条fail边
} Node;

typedef struct Queue {
    Node **data;//数据区：存储AC自动机节点地址
    int head, tail, size;
} Queue;

Queue *init_queue(int n) {
    Queue *q = (Queue *)calloc(sizeof(Queue), 1);
    q->data = (Node **)malloc(sizeof(Node *) * n);
    q->tail = q->head = 0;//队列的尾指针指向第一个为空的元素，队列的头指针指向第一个非空元素，重合代表队列是空的
    return q;
}

void clear_queue(Queue *q) {
    if (q == NULL) return ;
    free(q->data);
    free(q);
    return ;
}

Node *front(Queue *q) {
    return q->data[q->head];
}

int empty(Queue *q) {
    return q->head == q->tail;
}

void push(Queue *q, Node *node) {
    q->data[q->tail++] = node;
    return ;
}

void pop(Queue *q) {
    if (empty(q)) return ;
    q->head++;
}

Node *getNewNode() {
    Node *p = (Node *)calloc(sizeof(Node), 1);
    return p;
}

int insert(Node *root, const char *str) {
    int cnt = 0;
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - BEGIN_LETER;
        if (p->next[ind] == NULL) p->next[ind] = getNewNode(), ++cnt;
        p = p->next[ind];
    }
    p->flag = 1;
    //需要统计每次新增字符指针的个数
    return cnt;
}

void clear(Node *node) {
    if (node == NULL) return ;
    for (int i = 0; i < BASE; i++) {
        clear(node->next[i]);
    }
    free(node);
    return ;
}

void build_ac(Node *root, int n) {
    //建立AC自动机
    //传入字典树根节点和节点个数
    Queue *q = init_queue(n + 10);
    //先将根节点的fail指针设为NULL
    root->fail = NULL;
    push(q, root);
    while (!empty(q)) {
        //每次取出一个节点，建立相关节点所有子节点的失败指针
        Node *now_node = front(q);
        pop(q);
        //建立当前节点所有子节点的失败指针
        for (int i = 0; i < BASE; i++) {
            //如果没有第i个子孩子，不需要建立失败指针
            if (now_node->next[i] == NULL) continue;
            //p是当前节点的失败指针，即第i个子节点的父节点的失败指针
            Node *p = now_node->fail;
            while (p && p->next[i] == NULL) p = p->fail;
            //如果没有找到可匹配的字符指针，则子节点失败指针指向根节点
            //如果找到了，则子节点失败指针指向父节点失败指针指向节点之后的下一个对应节点
            if (p == NULL) now_node->next[i]->fail = root;
            else now_node->next[i]->fail = p->next[i];
            //子节点入队
            push(q, now_node->next[i]);
        }
    }
    return ;
}

int match(Node *root, const char *str) {
    //下次想不明白代码就模拟！！！
    int cnt = 0;
    //字典树指针
    Node *p = root; 
    for (int i = 0; str[i]; i++) {
        //i代表字符对应的指针下标
        int ind = str[i] - BEGIN_LETER;
        while (p && p->next[ind] == NULL) p = p->fail;
        //p == NULL代表到了根结点依然找不到对应的字符指针（根结点的fail指针为NULL），字典树指针回溯到根结点，等待下一个文本串字符进来
        if (p == NULL) p = root;
        else p = p->next[ind];
        Node *q = p;
        while (q) cnt += q->flag, q = q->fail;
        //统计了各个单词总的出现次数，比如一个模式串，模式串为h,文本串为hhhhh，那么统计总数为５
    }
    return cnt;
}

int main() {
    Node *root = getNewNode();
    int n, cnt = 0;
    char str[1000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        cnt += insert(root, str);//有多少个节点，队列就需要多少个空间位置
    }
    //建立失败指针build ac
    build_ac(root, cnt);
    scanf("%s", str);//文本串
    match(root, str);
    printf("match word cnt : %d\n",match(root, str));
}
