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
#define INF 0x3f3f3f3f

using namespace std;

int calc(const char *str, int l, int r) {
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
            }      
        if (cur_prior <= prior) {//该区间优先级最低且靠后的运算符作为根节点    
            prior = cur_prior;
            pos = i;
        }
    }
    if (pos == -1) {//说明该区间不包含运算符,计算数字的值
        int num = 0;
        for (int i = l; i <= r; i++) {
            if (str[i] < '0' || str[i] > '9') continue;
            num = num * 10 + str[i] - '0';
        }
        return num;
    } else {//递归计算子树表达式
        int a = calc(str, l, pos - 1);
        int b = calc(str, pos + 1, r);
        switch (str[pos]) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
            }
    }
    return 0;
}


int main () {
    char str[1000];
    while (scanf("%[^\n]s", str) != EOF) {
        getchar();
        printf("%s = %d\n", str, calc(str, 0, strlen(str) - 1));
    }
    return 0;
}
