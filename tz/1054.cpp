/*************************************************************************
	> File Name: bds.cpp
	> Author:yuxiaowei 
	> Mail:1147407739@qq.com 
	> Created Time: 2018年10月21日 星期日 15时36分57秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define INF 0x3f3f3f3f
#define MOD 1000000007
using namespace std;

int calc(const char *str, int l, int r, int a_value) {
    int pos = -1, temp_prior = 0, prior = INF - 1;//temp_prior:括号优先级加成
    for (int i = l; i <= r; i++) {
        int cur_prior = INF; //当前运算符优先级（不是运算符为极大值）
        switch (str[i]) {
            case '(': temp_prior += 100; break;
            case ')': temp_prior -= 100; break;
            case '+': cur_prior = temp_prior + 1; break;
            case '-': cur_prior = temp_prior + 1; break;
            case '*': cur_prior = temp_prior + 2; break;
            case '/': cur_prior = temp_prior + 2; break;
            case '^': cur_prior = temp_prior + 3; break;
            }      
        if (cur_prior <= prior) {//该区间优先级最低且靠后的运算符作为根节点    
            prior = cur_prior;
            pos = i;
        }
    }
    if (pos == -1) {//说明该区间不包含运算符,计算数字的值
        int num = 0;
        for (int i = l; i <= r; i++) {
            if (str[i] == 'a') return a_value;
            if (str[i] < '0' || str[i] > '9') continue;
            num = num * 10 + str[i] - '0';
        }
        return num;
    } else {//递归计算子树表达式
        int a = calc(str, l, pos - 1, a_value);
        int b = calc(str, pos + 1, r, a_value);
        switch (str[pos]) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return (a % MOD) * (b % MOD);
            case '/': return a / b;
            case '^': return (int)pow(a,b) % MOD;
            }
    }
    return 0;
}


int main () {
    char str[30][1000];
    int flag[30];
    int ans[100];
    scanf("%[^\r]s", str[0]);
    getchar();
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 1; i <= n; i++) {
        scanf("%[^\r]s",str[i]);
        getchar();
        flag[i] = 1;
    }
    int len = strlen(str[0]);
    for (int i = 0; i < 100; i++) {
        ans[i] = calc(str[0], 0, len - 1, i);
        for (int j = 1; j <= n; j++) {
            int len2 = strlen(str[j]);
            int res = calc(str[j], 0, len2 - 1, i);
            if (res != ans[i]) flag[j] = 0;
        }
    } 
    for (int i = 1; i <= n; i++) {
        if (flag[i]) printf("%c",'A' + i- 1);
    }
    printf("\n");
    return 0;
}
