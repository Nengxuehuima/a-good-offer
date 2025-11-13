思路分析：
1、排序：首先对数组进行排序，这样可以方便后续使用双指针避免重复。
2、遍历数组：我们可以将数组中的每个元素作为一个固定的第一个元素 nums[i]，然后在剩下的部分中寻找两个数，使得这两个数和当前元素的和为0。
3、双指针：在数组的剩余部分（即从 i+1 到 n-1），我们使用两个指针：left 从 i+1 开始，right 从 n-1 开始。根据三个数的和的大小来移动指针：
4、如果和为0，记录这个三元组，并且移动两个指针。
5、如果和小于0，说明需要增大和，所以移动 left 指针向右。
6、如果和大于0，说明需要减小和，所以移动 right 指针向左。
7、去重：为了避免重复的三元组，当我们找到一个符合条件的三元组时，需要跳过所有重复的数字。

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> threeSum(vector<int>& nums)
  {
    vector<vector<int>> result;
    int n=nums.size();
    if(n<3) return result;
    sort(nums.begin(),nums.end());//将数组排序
    for(int i=0;i<n-2;i++)
      {
        //如果当前元素和前一个元素相同，则跳过，避免重复
        if(i>0 && nums[i] == nums[i-1])  continue;
  
        int left = i+1,right = n-1;
        while(left<right)
          {
            int sum = nums[i] + nums[left] + nums[right];
            if(sum == 0)
            {
              result.push_back({nums[i],nums[left],nums[right]});
              //跳过重复元素
              while(left<right && nums[left] == nums[left + 1]) ++left;
              while(left<right && nums[right] == nums[right - 1]) --right;
              ++left;
              --right;
            }
            else if(sum<0)  ++left;
            else --right;
          }
      }
    return result;
  }
};

int main()
{
  Solution solution;
  vector<int> nums = {-1,0,1,2,-1,-4};
  vector<vector<int>> result = solution.threeSum(nums);

  for(const auto& triplet:result)
    {
      cout<<"[";
      for(int i=0;i<triplet.size();++i)
        {
          cout<<triplet[i];
          if(i!=triplet.size()-1) cout<<",";
        }
      cout<<"]";
      return 0;
    }
}
