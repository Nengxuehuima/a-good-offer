#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution{
public:
bool canPartition(vector<int>& nums){
  int sum = accumulate(nums.begin(),nums.end(),0);

  //如果总和是结束，无法平分
  if(sum % 2 != 0) return false;

  int target = sum / 2;

  //dp[j]表示是否能凑出和为j
  vector<bool> dp(target + 1, false);

  //初始话
  dp[0] = true;

  //0/1背包
  for(int num : nums){
    for(int j = target;j >= num;j--){
      dp[j] = dp[j] || dp[j - num];
    }
  }

  return dp[target];
}
};
