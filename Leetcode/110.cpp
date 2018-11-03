/*************************************************************************
	> File Name: 110.cpp
	> Author:yuxiaowei 
	> Mail:1147407739@qq.com 
	> Created Time: 2018年10月25日 星期四 20时04分09秒
 ************************************************************************/

#include<iostream>
using namespace std;

int getHeight(struct TreeNode *root) {
    if (root == NULL) return 0;
    int l = getHeight(root->left), r = getHeight(root->right);
    return (l > r? l : r) + 1;
}
bool isBalanced(struct TreeNode* root) {
    if (root == NULL) return true;
    int l = getHeight(root->left), r = getHeight(root->right);
    if (abs(l - r) > 1) return false;
    return isBalanced(root->left) && isBalanced(root->right);
}//重复运算多




