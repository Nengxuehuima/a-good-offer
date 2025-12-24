层序遍历=广度优先搜索(BFS)
核心思想：
  按层访问二叉树
  使用队列：
    先把根节点入队
    每次从队列中取出一整层节点
    访问它们的值
    再把它们的左右子节点加入队列
没处理完一层，就把该层的结果加入答案  队列是先进先出（FIFO），非常适合按层遍历节点
解题方法（BFS 过程）
1、若 root == nullptr，直接返回空结果
2、创建一个队列 queue<TreeNode*>
3、根节点入队
4、while 队列不为空：
    当前层节点数 = queue.size()
    循环取出这 size 个节点：
      记录节点值
      左右子节点不为空就入队
    把当前层结果加入最终答案

#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
pubic:
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x) , left(nullptr) , right(nullptr){}
};

class Solution{
public:
  vector<vector<int>> levelOrder(TreeNode* root){
    vector<vector<int>> res;
    if(!root) return res;
  
    queue<TreeNode*> q;
    q.push(root);
  
    while(!q.empty()){
      int size = q.size();
      vector<int> level;
  
      for(int i = 0; i < size; i++){
        TreeNode* node = q.front();
        q.pop();
        level.push_back(node->val);
  
        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
      }
      res.push_back(level);
    }
    return res;
  }
};

//解析输入字符串，构件二叉树
TreeNode* bulidTree(const string& input){
  if(input == "[]" || input.empty()) return nullptr;
  vector<string> nodes;
  string s = input.substr(1,input.size()-2);
  string temp;
  stringstream ss(s);

  while(getline(ss,temp,","))
    {
      nodes.push_back(temp);
    }
  if(nodes[0] == "null") return nullptr;
  TreeNode* root = new TreeNode(stoi(nodes[0]));
  queue<TreeNode*> q;
  q.push(root);

  int index = 1;
  while(!q.empty() && index < nodes.size()){
    TreeNode* curr = q.front();
    q.pop();

    if(nodes[index] = != "null"){
      curr->left = new TreeNode(stoi(nodes[index]));
      q.push(curr->left);
    }
    index++;
    
    if(index < nodes.size() && nodes[index] != "null"){ 
      curr->right = new TreeNode(stoi(nodes[index]));
      q.push(curr->right);
  }
  index++;
}
return root;
}

int main(){
  string input;
  cin>>input;

  TreeNode* root = buildTree(intput);
  Solution solution;
  vector<vector<int>> result = solution.levelOrder(root);

  cout<<"[";
  for(int i = 0;i < result.size(); i++){
      cout"[";
      for(int j = 0;j < result[i].szie(); j++){
        cout << result[i][j];
        if(j + 1 < result[i].size()) cout << ",";
      }
      cout << "]";
      if (i + 1 < result.size()) cout << ",";
  }
cout<< "]";
return 0;
}
