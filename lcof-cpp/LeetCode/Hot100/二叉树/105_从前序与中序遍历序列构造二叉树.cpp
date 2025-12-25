先序遍历的第一个元素，一定是「根节点」
根节点在中序遍历中，把树一分为二
每一层递归做的事
1、从 preorder 中取当前子树的 根节点
2、在 inorder 中找到这个根的位置
3、根据位置：
  左边是左子树
  右边是右子树
4、递归构建左右子树

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
unordered_map<int,int> index;  //中序遍历值-》小标
int preIdx = 0;

TreeNode* buildTree(vector<int>& preorder,vector<int>& inorder){
  //建立中序索引表
  for(int i = 0;i < inorder.size(); i++)
    {
    index[inorder[i]] = i;
    }
    return build(preorder , 0 , inorder.size() - 1);
}

TreeNode* build(vector<int>& preorder,int l,int r){
  if(l > r) return nullptr;

  //先序遍历当前根
  int rootval = preorder[preIdx++];
  TreeNode* root = new TreeNode(rootval);

  int mid = index[rootval];

  //先构建左子树，在构建右子树
  root->left = build(preorder , l , mid - 1);
  root->right = build(preorder , mid + 1 , r);

  return root;
}

};
