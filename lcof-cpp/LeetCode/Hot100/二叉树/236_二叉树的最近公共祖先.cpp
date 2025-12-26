核心思路（递归 + 后序遍历）
关键观察
  对于任意一个节点 root：
  如果 root == p 或 root == q
→ 它有资格成为最近公共祖先
  如果：
  左子树找到了一个节点
  右子树也找到了一个节点
    → 当前 root 就是最近公共祖先
如果只在一侧找到
→ 继续向上返回
为什么用后序遍历？
  因为我们要：
  先在左右子树中找
  再根据返回结果判断当前节点
  这正是 后序遍历（左 → 右 → 根） 的天然应用场景。


#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

struct TreeNode{
int val;
TreeNode* left;
TreeNode* right;
TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution{
public:
TreeNode* pNode;
TreeNode* qNode;

//最近公共祖先核心递归函数
TreeNode* dfs(TreeNode* root){
  if(root == nullptr) return nullptr;

  if(root == pNode || root == qNode)
    return root;
  TreeNode* left = dfs(root->left);
  TreeNode* right = dfs(root->right);

  if(left && right)
    return root;

  return left ? left : right;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
  pNode = p;
  qNode = q;
  return dfs(root);
}
};

TreeNode* buildTree(const vector<string>& nodes){
  if(nodes.emoty() || nodes[0] == "null") return nullptr;

  TreeNode* root = new TreeNode(stoi(nodes[0]));
  queue<TreeNode*> que;
  que.push(root);

  int i = 1;
  while(!que.empty() && i < nodes.size()){
    TreeNode* cur = que.front();
    que,pop();

    if(i < nodes.size() && nodes[i] != "null"){
      cur->left = new TreeNode(stoi(nodes[i]));
      que.push(cur->left);
    }
    i++;

    if(i < nodes.size() && nodes[i] != "null"){
      cur->right = new TreeNode(stoi(nodes[i]));
      que.push(cur->right);
    }
    i++;
  }
  return root;
}

//在树中查找指定值的节点
TreeNode* findNode(TreeNode* root,int val){
  if(!root) return nullptr;
  if(root->val == val) return root;

  TreeNode* left = findNode(root->left,val);
  if(left) return left;
  return findNode(root->right,val);
}

int main(){
  vector<string> node;
  string s;

  while(cin>>s){
    if(s == "#") break;
    nodes.push_back(s);
    if(cin.peek() == '\n') break;
  }
  int pVal,qVal;
  cin>>pVal>>qVal;

  TreeNode* root = buildTree(nodes);
  TreeNode* p = findNode(root,pVal);
  TreeNode* q = findNode(root,qVal);

  Solution sol;
  TreeNode* ans = sol.lowestCommonAncestor(root,p,q);
  if(ans)
    cout<<ans->val<<endl;

  return 0;
}
