正确思路（两种）
方法一（推荐）：中序遍历法
BST 的一个重要性质：
BST 的中序遍历结果是严格递增的
思路：
  中序遍历二叉树
  记录前一个访问的值
  若当前值 ≤ 前一个值 → 不是 BST

#inlcude <bits/stdc++.h>
using namespace std;

struct TreeNode{
int val;
TreeNode* left;
TreeNode* right;

TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution{
private:
long long prev;  //记录中序遍历的前一个值
public:
Solution(){
  prev = LLONG_MIN;   //初始化为最小值，防止越界
}

//判断是否为有效BST
bool isValidBST(TreeNode* root){
  return inorder(root);
}

//中序遍历
bool inorder(TreeNode* root){
  if(!root)  return true;

  //遍历左子树
  if(!inorder(root->left))  return false;

  //判断当前节点是否大于前一个节点
  if(root->val <= prev) return false;

  //更新前一个节点的值
  prev = root->val;

  //遍历右子树
  return inorder(root->right);
}
};

//构件二叉树
TreeNode* buildTree(const string& input){
  if(input == "[]" || input.empty())  return nullptr;

  //去掉左右中括号
  string s = input.substr(1,input.size() - 2);
  vector<string> nodes;
  string temp;
  stringstream ss(s);

  //按逗号分割
  while(getline(ss,temp,',')){
    nodes.push_back(temp);
  }

  if(nodes[0] == "null")  return nullptr;

  //创建根节点
  TreeNode* root = new TreeNode(stoi(nodes[0]));
  queue<TreeNode*> q;
  q.push(root);

  int index = 1;
  while(!q.empty() && index < nodes.size()){
    TreeNode* cur = q.front();
    q.pop();
    //构件左子节点
    if(index < nodes.size() && nodes[index] != "null"){
      q.push(cur->left);
    }
    index++;
    //构建右子节点
    if(index < nodes.size() && nodes[index] != "null"){
      cur->right = new TreeNode(stoi(nodes[index]));
      q.push(cur->right);
    }
    index++;
  }
  return root;
}

int main(){
  string input;
  cin>>input;

  TreeNode* root = buildTree(input);
  Solution soution;
  bool result = solution.isvalidBST(root);

  cout<<(result ? "true" : "false")<<endl;

  return 0;
}
