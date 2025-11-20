初始化 currentSum = nums[0]，maxSum = nums[0]
从第二个元素开始遍历数组：
  更新当前连续和：
    currentSum = max(nums[i], currentSum + nums[i])
  更新全局最大值：
    maxSum = max(maxSum, currentSum)
遍历结束后，maxSum 即为答案。

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
int maxSubArray(vector<int>& nums)
{
  //初始化当前子数组和与最大子数组和
  int currentSum = nums[0];            //当前连续子数组的最大和（以当前元素结尾）
  int maxSum = nums[0];

  //从第二个元素开始遍历
  for(int i = 1;i < nums.size();++i)
    {
      //如果档期啊按元素加上之前的和还不如当前元素大，则从当前元素重新开始
      currentSum = max(nums[i],currentSum + nums[i]);
      //更新最大和
      maxSum = max(maxSum,currentSum);
    }
  return maxSum;
}
};

int main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);

  int n;
  cin>>n;//输入数组长度
  vector<int> nums(n);
  for(int i = 0;i < n;i++)
    cin>>nums[i];

  Solution sol;
  cout<<sol.maxSubArray(nums)<<"\n";
  return 0;
}
