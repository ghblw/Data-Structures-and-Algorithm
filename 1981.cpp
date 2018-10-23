/*************************************************************************
	> File Name: bds.cpp
	> Author:yuxiaowei 
	> Mail:1147407739@qq.com 
	> Created Time: 2018年10月21日 星期日 15时36分57秒
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#define MAXN 2300000
#define MOD 10000
char str[MAXN];

int calc(char *str) {
    int len = strlen(str);
    for (int i = 0; str[i]; i++) str[i] = (str[i] == '+'? 0 : str[i]);
    int total = 0;
    for (int j = 0; j < len; j += strlen(str + j) + 1) {
        int num = 0, p = 1;
        for (int i = j; str[i]; i++) {
            switch (str[i]) {
                case '*': p *= num; p %= MOD; num = 0; break;
                default : num = num * 10 + str[i] - '0'; 
            }
        }
        p *= num;//不是乘号要再乘上num
        p %= MOD;
        total += p;
        total %= MOD;
    }
    return total;
}
int main () {
    scanf("%s", str);
    printf("%d\n",calc(str));
    return 0;
 }
