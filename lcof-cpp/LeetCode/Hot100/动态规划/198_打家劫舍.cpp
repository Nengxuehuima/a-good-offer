#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
int rob(vector<int>& nums){
  int n = nums.size();

  //特殊情况处理
  if(n == 0) return 0;
  if(n == 1) return nums[0];

  //prev2表示dp[i-2]
  //prev1表示dp[i-1]
  int prev2 = nums[0];
  int prev1 = max(nums[0],nums[1]);

  //从第2间房开始计算
  for(int i = 2;i<n;i++){
    int cur = max(prev1, prev2 + nums[i]);
    prev2 = prev1;
    prev1 = cur;
  }
  return prev1;
}
};
