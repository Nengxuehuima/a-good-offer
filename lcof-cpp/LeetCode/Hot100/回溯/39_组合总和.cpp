#include <bits/stdc++.h>
using namespace std;

class CombinationSumSolver{
private:
vector<vector<int>> ans;//保存所有组合
vector<int> path;//当前组合

//start：当前可选数字的起始下标
//sum：当前组合的和

void dfs(const vector<int>& candidates,int target,int start,int sum){
  //找到一个合法组合
  if(sum == target){
    ans.push_back(path);
    return;
  }

  //剪枝：超过目标值，直接返回
  if(sum > target){
    return;
  }

  //从start开始选，避免重复组合
  for(int i = start;i < (int)candidates.size();i++){
    path.push_back(candidates[i]);//选择当前数
    dfs(candidates,target,i,sum + candidates[i]);//i不变，允许重复
    path.pop_back();//回溯
  }
}

public:
vector<vector<int>> combinationSum(vector<int>& candidates,int target){
  ans.clear();
  path.clear();
  dfs(candidates,target,0,0);
  return ans;
}
};
