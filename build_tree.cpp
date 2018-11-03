/*************************************************************************
	> File Name: build_tree.cpp
	> Author:yuxiaowei 
	> Mail:1147407739@qq.com 
	> Created Time: 2018年10月28日 星期日 18时19分18秒
 ************************************************************************/

#include<iostream>
using namespace std;

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->lchild = p->rchild = NULL;
    return p;
}


Stack *initStack(int n) {
    
}

int empty(Stack *s) {
    return s == NULL || s->top == -1;
}

void pop(Stack *s) {
    if ()
}

void push(Stack *s, Node *root) {
    if (s->top + 1 == s->size) return ;
    s->data[++(s->top)] = root;
    return ;
}

Node *top(Stack *s) {
    if (empty(s)) return NULL;
    return 
}

void clearStack(Stack *s) {
    if (s == NULL) return ;

}

void clearTree(Node *root) {
    if (root == NULL) return ;
    clearTree(root->lchild);
    clearTree(root->rchild);
    free
}

Node *build(const char *str) {
    Node *p = NULL;
    Stack *s = initStack(100);
    while (str[0]) {
        switch (str[0]) {
            case '(':{
                push(s, p);
                k = 0;
            }break;
            case ')':{
                pop
            }break;
            case '(':
            case '(':
                   default: {
                       p = getNewNode(str[0]);
                       if ()
                       if
                       if (k == 0) top(s)->lchild = p;
                       else top(s)->rchild = p;
          }
        }
        str++;
    }
    return root;
}

                   void output(Node *root) {//先序遍历
                       if (root == NULL) return ;
                       printf("%c ", root->key);
                       output(root->lchild);
                       output(root->rchild);
                   }
                   int main() {
                       
                   }
