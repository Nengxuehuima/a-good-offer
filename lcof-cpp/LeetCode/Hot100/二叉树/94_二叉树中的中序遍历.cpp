中序遍历的访问顺序是：左子树 → 根节点 → 右子树

方法一：递归（简单易懂 ✅）
  若当前节点为空，则返回。
  先遍历左子树。
  访问当前节点（保存值）。
  再遍历右子树。
时间复杂度：O(n)
空间复杂度：O(n)（递归调用栈）

#include <bits/stdc++.h>
using namespace std;

//二叉树节点结构定义
struct TreeNode{
int val;
TreeNode* left;
TreeNode* right;
TreeNode(int x):val(x) , left(nullptr) , right(nullptr) {}
};

class Solution{
public:
  vector<int> inorderTraversal(TreeNode* root){
    vector<int> res;
    inorder(root,res);
    return res;
  }

private:
//递归中序遍历
  void inorder(TreeNode* node,vector<int>& res){
    if(node == nullptr) return;
    inorder(node->left,res);//遍历左子树
    res.push_back(node->val);//访问根节点
    inorder(node->right,res);//遍历右子树
  }
};

int main(){
  TreeNode* root = new TreeNode(1);
  root->right = new TreeNode(2);
  root->rigth->left = new TreeNode(3);

  Solution sol;
  vector<int> res = sol.inorderTraversal(root);

  //输出结果
  for(int i=0;i<res.size();i++)
    {
      if(i)  cout<<" ";
      cout<<res[i];
    }
  cout<<endl;
  return 0;
}


方法二：迭代（使用栈模拟递归）
  使用一个栈保存节点。
  不断向左走到底，将路径上的节点压栈。
  当左子树为空时，弹出栈顶节点，访问它，然后转向右子树。
时间复杂度：O(n)
空间复杂度：O(n)


vector<int> inorderTraversal(TreeNode* root){
  vector<int> res;
  stack<TreeNode*> st;
  TreeNode* cur = root;

  while(cur != nullptr || !st.empty()){
    //一直往左走
    while(cur != nullptr){
      st.push(cur);
      cur = cur->left;
    }
    //到达最左节点，弹出栈顶
    cur = st.top();
    st.pop();
    res.push_back(cur->val);
    //转向右子树
    cur = cur->right;
  }
  return res;
}

