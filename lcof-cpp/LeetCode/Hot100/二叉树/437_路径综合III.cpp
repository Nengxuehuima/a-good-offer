前缀和 + DFS（深度优先搜索）

前缀和的定义: 从根节点到当前节点的路径和：
DFS 遍历每个节点时：
1、更新当前路径和 currentSum
2、查看：
3、当前前缀和加入哈希表
4、递归左右子树
5、回溯：当前前缀和次数减 1

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
//哈希表 前缀和-》出现次数
unordered_map<long long,int >prefixCount;

int result = 0;
int target;

int pathSum(TreeNode* root,int targetSum){
  target = targetSum;
  //初始化，前缀和为0出现一次表示从根节点开始的第一条路径
  prefixCount[0] = 1;

    dfs(root,0);

  return result;
}

void dfs(TreeNode* root,long long currentSum){
  if(root == nullptr) return ;

  //1、更新当前路径和
  currentSum += root->val;

  //2、查找是否存在currentSum - target
  if(prefixCount.count(currentSum - target)){
    result += prefixCount[currentSum - target];
  }
  //3、当前前缀和加入哈希表
  prefixCount[currentSum]++;

  //4、递归左右子树
  dfs(root->left,currentSum);
  dfs(root->right,currentSum);

  //5、回溯
  prefixCount[currentSum]--;
}
};
