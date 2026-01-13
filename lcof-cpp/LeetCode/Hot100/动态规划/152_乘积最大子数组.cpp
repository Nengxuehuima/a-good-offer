#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
int maxProduct(vector<int>& nums){
  int n = nums.size();

  //maxDp[i]:以nums[i]结尾的最大乘积
  //minDp[i]:以nums[i]结尾的最小乘积
  vector<int> maxDp(n),minDp(n);

  //初始化
  maxDp[0] = nums[0];
  minDp[0] = nums[0];

  int ans = nums[0];

  for(int i = 1;i < n;i++){
    int a = nums[i] * maxDp[i - 1];
    int b = nums[i] * minDp[i - 1];

    maxDp[i] = max(nums[i], max(a, b));
    minDp[i] = min(nums[i], min(a, b));

    ans = max(ans,maxDp[i]);
  }
  return ans;
}
};
