二叉搜索树的关键性质
对于任意节点 root：
  左子树所有节点值 小于 root->val
  右子树所有节点值 大于 root->val
重要推论：
  BST 的中序遍历结果是一个递增有序序列

解题核心思路（最重要）
中序遍历（Left → Root → Right）
因为中序遍历会按从小到大的顺序访问节点：
  第 1 个访问到的节点 → 第 1 小
  第 k 个访问到的节点 → 第 k 小
所以问题转化为：
  在中序遍历过程中，数到第 k 个节点即可返回

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
int kthSmallest(TreeNode* root, int k){
  stack<TreeNode*> st;
  TreeNode* cur = root;

  while(cur != nullptr || !st.empty()){
    //一直向左走，并压栈
    while(cur != nullptr){
      st.push(cur);
      cur = cur->left;
    }
    //弹出栈顶节点(当前最小)
    cur = st.top();
    st.pop();
    //访问该节点
    k--;
    if(k == 0)
    {
      return cur->val;
    }
    //转向右子树
    cur = cur->right;
  }
  return -1;
}
};

TreeNode* buileTree(cost vector<int>& nums){
  if(nums.empty() ||nums[0] == -1)  return nullptr;

  TreeNode* root = new TreeNode(nums[0]);
  queue<TreeNode*> q;
  q.push(root);

  int i=1;
  while(!q.emoty() && i < nums.size()){
    TreeNode* cur = q.front();
    q.pop();

    //左孩子
    if(i< nums.size() && nums[i] != -1){
      cur->left = new TreeNode(nums[i]);
      q.push(cur->left);
    }
    i++;

    //右孩子
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
      cin >> nums[i];
    }
  int k;
  cin >> k;

  //构件二叉树
  TreeNode* root = builTree(nums);
  Solution solution;
  cout<<solution.kthSmellest(root,k)<<endl;
  return 0;
}
