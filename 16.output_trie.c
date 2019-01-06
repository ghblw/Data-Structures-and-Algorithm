#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node {
    int check;
    int base;
} Node;

Node trie[1000];

void dfs(int ind, int k, char *str) {
    if (trie[ind].check < 0) {
        printf("%s\n", str);
    }
    for (int i = 0; i < 26; i++) {
        int check = abs(trie[trie[ind].base + i].check);
        if (check - ind == 0 && trie[ind].base + i != check) {//存在子节点，特殊处理：节点１的第一个子节点，死循环？
            str[k] = 'a' + i;
            str[k + 1] = 0;
            dfs(trie[ind].base + i, k + 1, str);
        }
    }
    return ;
}

int main() {
    int ind;
    while (scanf("%d", &ind) != EOF) {
        scanf("%d%d", &trie[ind].base, &trie[ind].check);
        printf("%d %d %d\n", ind, trie[ind].base, trie[ind].check);
    }
    char str[100];
    dfs(1, 0, str);//层，位置，字符串
}
