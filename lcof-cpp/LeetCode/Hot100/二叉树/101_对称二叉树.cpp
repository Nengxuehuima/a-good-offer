若两节点都为空 → 对称；
若一个为空另一个不为空 → 不对称；
若两节点的值相等 → 继续判断：
  left->left 与 right->right 是否对称；
  left->right 与 right->left 是否对称。
最终返回 isMirror(root->left, root->right)。

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
//主函数，判断整棵树是否对称
  bool isSymmetric(TreeNode* root){
    if(root == nullptr)  return true;
    return isMirror(root->left,root->right);
  }

private:
  bool isMirror(TreeNode* t1,TreeNode* t2){
    if(t1 == nullptr && t2 == nullptr) return true;
    if(t1 == nullptr || t2 == nullptr) return false;
    if(t1->val != t2->val) return false;
  
    return isMirror(t1->left,t2->right) && isMirror(t1->right,t2->left);
  }
};

