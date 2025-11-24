解题思路
核心思想：原地哈希（索引放置法）
我们想找到 数组中缺失的最小正整数。
设数组长度为 n，那么答案一定在 [1, n+1] 之间。
（比如长度为 3 的数组，最多能包含 [1,2,3]，如果都存在，答案就是 4）

思路步骤：
1、过滤无用元素
  所有 ≤ 0 或 > n 的元素都不可能是我们要找的数，直接忽略（可以暂时设为 n+1）。
2、原地哈希：交换到正确位置
  我们希望每个正整数 x（若 1 ≤ x ≤ n）都被放到下标 x-1 的位置。
  例如：数字 1 应该在下标 0，数字 2 应该在下标 1。
  用循环交换：
  while (nums[i] in range [1, n] and nums[nums[i]-1] != nums[i]) {
      swap(nums[i], nums[nums[i]-1]);
  }
3、查找第一个不匹配的位置
  遍历一遍数组，如果 nums[i] != i+1，说明 i+1 缺失。
  如果都匹配，说明 [1, n] 都在数组中，答案为 n+1。

  #include <bits/stdc++.h>
  using namespace std;
class Solution{
public:
  int firstMissingPositive(vector<int>& nums)
  {
    int n = nums.size();
  
    //第一步，消除无效元素,把所有 所有 ≤ 0 或 > n 的元素都改为n+1
    for(int i = 0;i<n;i++)
      {
        if(nums[i] <= 0 || nums[i] > n)
          nums[i] = n + 1;
      }
    
          // 第二步：原地哈希（索引放置法）
          // 如果 nums[i] 的值在 [1, n] 范围内，就将它放到正确的位置
          // 即：nums[i] 应该放到 nums[i] - 1 位置上
    for(int i = 0;i<n;i++)
      {
        while(nums[i] >= 1 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
          {
            swap(nums[i],nums[nums[i] - 1]);
          }
      }
  
           // 第三步：扫描找出第一个不匹配的下标
          // 如果 nums[i] != i + 1，说明缺失的最小正数是 i + 1
      for(int i = 0;i<n;i++)
        {
          if(nums[i] != i+1)
            return i+1;
        }
    return n+1;
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin>>tie(nullptr)

    vector<int> nums;
  int x;

  while(cin>>x){
    nums.push_back(x);
  }
  Solution sol;
  int res = sol.firstMissingPositive(nums);

  cout<<res<<endl;
  return 0;
}
