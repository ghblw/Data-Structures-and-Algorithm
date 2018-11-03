/*************************************************************************
	> File Name: 102.cpp
	> Author:yuxiaowei 
	> Mail:1147407739@qq.com 
	> Created Time: 2018年10月25日 星期四 19时45分57秒
 ************************************************************************/

#include<iostream>
using namespace std;
int getHeight(struct TreeNode *root) {
    if (root == NULL) return 0;
    int l =getHeight(root->left), r = getHeight(root->right);//左子树深度右子树深度取较大者
    return (l > r ? l : r) + 1;
}
void getColumns(struct TreeNode *root, int *cols, int k) {
    if (root == NULL) return ;
    cols[k] += 1;
}
int ** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    *returnSize = getHeight(root);//层数
    *columnSizes = (int *)calloc(sizeof(int), *returnSize);//初始化为0
    getColumns(root, *columnSizes, 0);//获取每行的列数
    int **ret = (int **)malloc(sizeof(int *) * (*returnSize));
    for (int i = 0; i < *returnSize; i++) {
        ret[i] = (int *)malloc(sizeof(int) * (*columnSizes)[i]);
        (*columnSizes)[i] = 0;
    }
    getResult(root, ret, *columnSizes, 0);
    return ret;
}
