问题本质：
  对二叉树进行 层序遍历（BFS），每一层取最后一个节点
层序遍历 BFS
思路步骤
  1、使用队列进行 层序遍历
  2、每一层记录节点数量 size
  3、遍历这一层的所有节点
  4、当遍历到本层 最后一个节点 时，加入结果

#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
int val;
TreeNode* left;
TreeNode* right;
TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution{
public:
vector<int> rightSideView(TreeNode* root){
  vector<int> result;
  if(root == nullptr) return result;

  queue<TreeNode*> q;
  q.push(root);

  while(!q.empty()){
    int size = q.size();
    for(int i=0;i < size;i++)
      {
        TreeNode* cur = q.front();
        q.pop();

        //当前层最后一个节点
        if(i == size - 1){
          result.push_back(cur->val);
        }

        if(cur->left) q.push(cur->left);
        if(cur->right) q.push(cur->right);
      }
  }
  return result;
}
};

TreeNode* bulidTree(const vector<int>& nums){
  if(nums.empty() || nums[0] == -1) return nullptr;

  TreeNode* root = new TreeNode(nums[0]);
  queue<TreeNode*> q;
  q.push(root);

  int i=1;
  while(!q.empty() && i < nums.size()){
    TreeNode* cur = q.front();
    q.pop();

    if(i < nums.size() && nums[i] != -1){
      cur->left = new TreeNode(nums[i]);
      q.push(cur->left);
    }
    i++;

    if(i < nums.size() && nums[i] != -1){
      cur->right = new TreeNode(nums[i]);
      q.push(cur->right);
    }
    i++;
  }
  return root;
}

int main(){
  int n;
  cin >> n;
  vector<int> nums(n);
  for(int i=0;i<n;i++)
    {
      cin>>nums[i];
    }
  TreeNode* root = buildTree(nums);
  Solution solution;
  vector<int> ans = solution.rightSideView(root);

  for(int x : ans){
    cout<< x<< " ";
  }
  cout<< endl;
  return 0;
}
