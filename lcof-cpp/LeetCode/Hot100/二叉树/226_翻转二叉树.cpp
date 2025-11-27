递归（最直观，最常用）核心思想：
对每个节点：
  交换它的左右子节点；
  再递归地翻转它的左子树和右子树。
递归结束条件：
  当前节点为空 (root == nullptr) 时，直接返回。

#include <bits/stdc++.h>
using namespace std;

// ------------------ 二叉树节点定义 ------------------
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution{
public:
TreeNode* invertTree(TreeNode* root){
  if(root == nullptr)  return nullptr;

  //1、递归翻转左右字数
  invertTree(root->left);
  invertTree(root->right);

  //2、交换左右节点
  swap(root->left,root->right);

  //3、返回左右节点
  return root;
}
};
