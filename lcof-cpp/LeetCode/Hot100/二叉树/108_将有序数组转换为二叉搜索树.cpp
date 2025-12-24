二叉搜索树(BST)：
  左子树所有节点值<根节点
  右子树所有节点值>根节点
任意节点左右子树高度差小于等于1
解题思路（核心思想）
 “升序数组 + 平衡 BST” = 分治 + 中序思想
关键观察
  升序数组正好是 BST 的 中序遍历结果
  要保证树平衡：
    每次选数组的中间元素作为根节点
分治策略（非常重要）
对数组 [left, right]：
  1、取中间元素 mid 作为根
  2、左半部分构建左子树
  3、右半部分构建右子树
  4、递归进行

#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
public:
int val;
TreeNode* left;
TreeNode* right;
TreeNode(int x) : val(x) , left(nullptr) , right(nullptr){}
};

class Solution{
public:
TreeNode* sortedArrayToBST(vector<int>& nums){
  return build(nums , 0 , nums.size()-1);
}
private:
TreeNode* build(vector<int>& nums,int left,int right){
  //递归终止条件
  if(left > right)  return nullptr;

  //选择中间元素作为根节点
  int mid = left + (right - left)/2;
  TreeNode* root = new TreeNode(nums[mid]);

  //构建左右子树
  root->left = build(nums , left , mid - 1);
  root->right = build(nums , mid + 1, right);

  return root;
}
};

//将BST按照层序遍历输出
vector<string> levelOrder(TreeNode* root){
  vector<string> result;
  if(!root) return result;

  queue<TreeNode*> q;
  q.push(root);

  while(!q.empty()){
    TreeNode* node = q.front();
    q.pop();

    if(node){
      result.push_back(to_string(node->val));
      q,push(node->left);
      q.push(node->right);
    }
    else{
      result.push_back("null");
    }
  }

  //删除末尾多余的null
  while(!result.empty() && result.back() == "null")
    {
      result.pop_back();
    }

  return result;
}

int main(){
  string input;
  cin>>input;

  input = input.substr(1,input.size() - 2);
  vector<int> nums;
  string temp;
  stringstream ss(input);

  //解析输入数组
  while(getline(ss,temp,","))
    {
      nums,push_back(stoi(temp));
    }

  Solution solution;
  TreeNode* root = solution.sortedArrayToBST(nums);

  //层序遍历输出
  vector<string>  output = levelOrder(root);

  cout<<"[";
  for(int i=0;i < output.size();i++)
    {
      cout<<output[i];
      if(i + 1 < output.size())  cout<<",";
    }
  cout<<"]";
  return 0;
}

