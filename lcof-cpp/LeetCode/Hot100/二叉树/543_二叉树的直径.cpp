递归求深度 + 动态更新最大直径
对于每个节点，我们考虑：
  左子树的最大深度 = L
  右子树的最大深度 = R
  经过该节点的路径长度 = L + R
我们用一个全局变量 maxDiameter 记录所有节点中最大值。

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
int maxDiameter = 0;
int diameterOfBinaryTree(TreeNode* root){
  depth(root);
  return maxDiameter;
}

private:
int depth(TreeNode* node){
  if(node == nullptr) return 0;
  int leftDepth = depth(node->left);
  int rightDepth = depth(node->right);

  maxDiameter = max(maxDiameter,leftDepth + rightDepth);
  return max(leftDepth,rightDepth) + 1;
}
};
