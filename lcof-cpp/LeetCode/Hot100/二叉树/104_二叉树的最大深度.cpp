递归（最常用、最直观）
对每个节点：
  若节点为空，返回 0；
  否则：
    计算左子树深度 left = maxDepth(root->left)
    计算右子树深度 right = maxDepth(root->right)
    当前节点的深度 = max(left, right) + 1
时间复杂度： O(n)（每个节点访问一次）
空间复杂度： O(h)（递归栈高度，最坏 O(n)）

#include <bits/stdc++.h>
using namespace std;

// ---------------- 二叉树节点定义 ----------------
struct TreeNode {
    int val;            // 节点值
    TreeNode *left;     // 左子节点
    TreeNode *right;    // 右子节点
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
//求二叉树的最大深度
int maxDepth(TreeNode* root){
  if(root == nullptr) return 0;
  int leftDepth = maxDepth(root->left);
  int rightDepth = maxDepth(root->right);
  //当前节点深度=max(左，右) + 1
  return max(leftDepth,rightDepth) + 1;
}
};
