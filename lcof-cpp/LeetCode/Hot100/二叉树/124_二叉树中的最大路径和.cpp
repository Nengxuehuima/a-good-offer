#include <iostream>
#inlcude <vector>
#include <queue>
#include <string>
#include <climits>
using namespace std;

strcut TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution{
public:
int maxSum;//全局最大路径和
//后序遍历，返回 向上延伸 的最大路径和
int dfs(TreeNode* root){
  if(root == nullptr) return 0;
  //左右子树的最大贡献（负数直接舍弃）
  int leftGain = max(0,dfs(root->left));
  int rightGain = max(0,dfs(root->right));

  //以当前节点为最高点路径
  int curPathSum = root->val + leftGain + rightGain;

  //更新全局最大值
  maxSum = max(maxSum,curPathSum);

  //返回给父节点（只能选一边）
  return root->val + max(leftGain , rightGain);
}

int maxPathSum(TreeNode* root){
  maxSum = INT_MIN;
  dfs(root);
  return maxSum;
}
};

