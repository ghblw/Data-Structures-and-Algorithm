/*************************************************************************
	> File Name: 5.lca.cpp
	> Author:yuxiaowei 
	> Mail:1147407739@qq.com 
	> Created Time: 2018年10月23日 星期二 19时39分27秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#define MAXN 1000//n个结点
#define MAXK 20//跳2^k层
using namespace std;
struct Edge {
    int v, n;
} g[MAXN << 1];
int head[MAXN + 5] = {0}, cnt = 0;
inline void add(int a, int b) {
    g[++cnt].v = b;
    g[cnt].n = head[a];
    head[a] = cnt;
    return ;
}

//gas[i][j] i往上走
//结点编号从1开始
//不用0结点？
int gas[MAXN][MAXK], dep[MAXN];

void dfs(int u, int father) {
    gas[u][0] = father;
    dep[u] = dep[father] + 1;
    for (int i = 1; i < MAXK; i++) {
        gas[u][i] = gas[gas[u][i - 1]][i - 1];
    }
    for (int i = head[u]; i; i = g[i].n) {
        if (g[i].v == father) continue;
        dfs(g[i].v, u);
    }
    return ;
}

int lca(int a, int b) {
    //b较深
    if (dep[b] < dep[a]) {
        a ^= b;
        b ^= a;
        a ^= b;//交换ab结点,a^b=c,(1,1,0)(0,0,0)
    }
    int l = dep[b] - dep[a];
        for (int i = 0; i < MAXK; i++) {
            if ((l & (1 << i))) b = gas[b][i];
        }
        if (a == b) return a;
        for (int i = MAXK - 1; i >= 0; i--) {//可以遍历到二进制的每一位，跳任意层数
            if (gas[a][i] != gas[b][i]) a = gas[a][i], b = gas[b][i];
        }
    return gas[a][0];
}

int main() {
    int n, a, b;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    dfs(1, 0);//1号结点父节点为0
    while (scanf("%d%d", &a, &b) != EOF) {
        printf("lca(%d,%d) = %d, a->b = %d\n", a, b, lca(a, b), dep[a] + dep[b] - 2 *dep[lca(a,b)]);
    }
}
