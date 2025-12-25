先序遍历：根》左》右
把二叉树按照「先序遍历」的顺序，串成一条只用 right 指针的链表。
思路核心（非常重要）
对每个节点 root：
  1、先递归展开 左子树
  2、再递归展开 右子树
  3、将：
    左子树接到 root->right
    原来的右子树接到「左子树最右节点」

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution{
public:
void flatten(TreeNode* root){
  if(root == nullptr) return;

  flatten(root->left);
  flatten(root->right);

  TreeNode* rightSubTree = root->right;

  root->right = root->left;
  root->left = nullptr;

  TreeNode* cur = root;
  while(cur->right != nullptr){
    cur = cur->right;
  }
  cur->right = rightSubTree;
}
};
