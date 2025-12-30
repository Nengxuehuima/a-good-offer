#include <bits/stdc++.h>
using namespace std;

class SubsetSolver{
private:
vector<vector<int>> ans;//保存所有子集
vector<int> path;//当前子集

//从下标start开始，构造子集
void dfs(const vector<int>& nums,int start){
  //当前path本身就是一个合法子集
  ans.push_back(path);

  //从start开始，依次选择元素
  for(int i = start;i < (int)nums.size();i++){
    //选择nums[i]
    path.push_back(nums[i]);

    //递归处理下一个位置
    dfs(nums,i+1);

    //回溯，撤销选择
    path.pop_back();
  }
}

prublic:
vector<vector<int>> subsets(const vector<int>& nums){
  ans.clear();
  path.clear();
  dfs(nums,0);
  return ans;
}
};
