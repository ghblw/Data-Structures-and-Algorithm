/*************************************************************************
	> File Name: boyi.cpp
	> Author:yuxiaowei 
	> Mail:1147407739@qq.com 
	> Created Time: 2018年10月28日 星期日 13时30分23秒
 ************************************************************************/

#include<iostream>
using namespace std;

int g[3][3];
int game_end(int &ret) {
    ret = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ret += (g[i][j] == 0);
        }
    }
    for (int i = 0; i < 3; i++) {

    }
}

int dfs(int k) {
    int ret, temp;
    if (game_end(ret)) return ret;
    ret = (k % 2 ? -10 : 10);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (g[i][j]) continue;
            g[i][j] = (k % 2 ? 1 : 2);//奇数层下1,偶数层下2
            temp = dfs(k + 1);//搜索下一层
            if (k % 2) ret = max(ret, temp);//奇数层：选择极大值
            else ret = min(ret, temp);//偶数层：选择极小值
            g[i][j] = 0;//恢复为空
        }
    }
    return ret;
}

int main() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &g[i][j]);
        }
    }
    printf("%d\n",dfs(1));
}
