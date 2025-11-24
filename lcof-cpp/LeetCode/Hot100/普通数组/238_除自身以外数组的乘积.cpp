解题思路
核心思路：
我们可以使用 前缀积（prefix product） 和 后缀积（suffix product） 的概念：
 对于每个位置 i：
  prefix[i] = nums[0] * nums[1] * ... * nums[i-1]
  suffix[i] = nums[i+1] * nums[i+2] * ... * nums[n-1]
那么：
  answer[i] = prefix[i] * suffix[i]

优化空间：
不需要两个数组存前后缀乘积。可以：
  先遍历一次求出前缀乘积并存到 answer 中；
  再从右向左遍历，用一个变量 R 表示当前右边所有元素的乘积，动态更新：
  answer[i] = answer[i] * R
  R *= nums[i]

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
  vector<int> productExceptSelf(vector<int>& nums) {
  int n = nums.size();
  vector<int> answer(n,1);//结果数组，初始时全部置为1
  
  for(int i = 1;i<n;i++)
  {
    answer[i] = answer[i-1]*nums[i-1];//第一趟遍历:计算每个位置的前缀积，answer[i] 存放 nums[0] 到 nums[i-1] 的乘积
  }
  
  int R = 1;
  for(int i = n-1;i >= 0;i--)
  {
          // 第二趟遍历：从右往左，计算后缀积并乘入结果
          // 用一个变量 R 表示当前位置右边所有元素的乘积
          // 初始时 R = 1，因为最右边元素右边没有数
    answer[i] = answer[i] * R;
    R *= nums[i]; // 更新右侧乘积：乘上当前 nums[i]
  }
  return answer;
  }
};

int main(){
  ios::sync_with_stdio(false);
  cin>>tie(nullptr);
  
  vector<int> nums;
  int x;
  
  while(cin>>x)
  {
  nums.push_back(x);
  }
  
  Solution sol;
  vector<int> ans = sol.productExceptSelf(nums);
  
  for(int i = 0;i<ans.size();i++)
  {
  if(i) cout<<" ";
  cout<<ans[i];
  }
  
  cout<<endl;
  return 0;
}
