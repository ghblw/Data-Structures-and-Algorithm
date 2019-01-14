/*************************************************************************
	> File Name: ac.cpp
	> Author:yuxiaowei 
	> Mail:1147407739@qq.com 
	> Created Time: 2019年01月14日 星期一 13时57分12秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;



//统计时顺序写反，没考虑清楚前后的小逻辑
int match(Node *root, const char *str) {
    int cnt = 0;
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - 'a';
        while (p && p->next[ind] == NULL) p = p->fail;
        if (p == NULL) p = root;
        else p = p->next[ind];//到了匹配的蓝色节点
        Node *q = p;
        while (q) {
            cnt += q->flag;
            q = q->fail;
        }
    }
    return cnt;
}

void build_ac(Node *root, int n) {
    
}
