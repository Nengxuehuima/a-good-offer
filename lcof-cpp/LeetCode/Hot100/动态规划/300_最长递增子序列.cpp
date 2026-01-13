#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
int lengthOfLIS(vector<int>& nums){
  int n = nums.size();
  if(n == 0) return 0;

  //dp[i]表示以nums[i]结尾的最长递增子序列长度
  vector<int> dp(n,1);

  int ans = 1;
  for(int i = 0;i < n;i++){
    for(int j = 0;j < i;j++){
      if(nums[j] < nums[i]){
        dp[i] = max(dp[i],dp[j] + 1);
      }
    }
    ans = max(ans,dp[i]);
  }
  return ans;
}
};
