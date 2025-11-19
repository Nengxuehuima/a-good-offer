#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
  int subarraySum(vector<int>& nums,int k)
  {
    unordered_map<int,int> prefixCount;
    prefixCount[0] = 1;//前缀和为0出现1次
  
    int preSum = 0,count = 0;
    for(int x : nums)
      {
        preSum += x;
        if(prefixCount.find(preSum - k) != prefixCount.end())
          count += prefixCount[preSum - k];
        prefixCount[preSum]++;//记录当前前缀和 preSum 的出现次数，以便后续子数组计算时使用。
      }
    return count;
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,k;
  cin>>n>>k;
  vector<int> nums(n);
  for(int i = 0;i<n;i++)  cin>>nums[i];

  Solution sol;
  cout<<sol.subarrySum(nums,k)<<"\n";

  return 0;
}
