#include <bits/stdc++.h>
using namespace std;

class PermutationSolver{
private:
vector<vector<int>> ans;//存放所有排列结果
vector<int> path;//当前路径（正在构造的排列）
vector<int> used;//used[i] = 1 表示nums[i] 已经用过

//深度优先搜索，在当前path 的基础山继续选择下一个元素

void dfs(const vector<int>& nums){
  //终止条件：当前排列长度等于nums长度，说明构造完成
  if((int)path.size() == (int)nums.size()){
    ans.push_back(path);
    return;
  }

  //尝试把每个未使用的nums[i]放到当前位置
  for(int i=0;i < (int)nums.size();i++){
    if(used[i]) continue;//已使用则跳过

    //选择nums[i]
    used[i] = 1;
    path.push_back(nums[i]);

    //递归进图下一层（继续选下一个位置）
    dfs(nums);

    //回溯，撤销选择，恢复现场
    path.pop_back();
    used[i] = 0;
  }
}

public:
//对外接口，返回所有全排列
vector<vector<int>> permute(const vector<int>& nums){
  ans.clear();
  path.clear();
  used.assign(nums.size(),0);//初始化used为0；
  dfs(nums);
  return ans;
}
};
