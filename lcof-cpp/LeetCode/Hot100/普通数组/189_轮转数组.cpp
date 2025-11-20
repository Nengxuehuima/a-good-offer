三次反转法（最优解）      面试中最推荐的方法。
核心思想：
  右移 k 步 = 把数组的后 k 个元素放到前面。
  我们可以通过“反转”实现这个效果。
    (1) 反转整个数组
    (2) 反转前 k 个元素
    (3) 反转后 n-k 个元素

#include <bits/stdc++.h>
using namespace std;

calss Solution {
public:
  void rotate(vector<int>& nums,int k)
  {
    int n = nums.size();
    if(n == 0)  return ;
  
    //如果k大于数组长度，只需取余数即可
    k %= n;
    if(k == 0) return ;
  
    //第一步： 反转整个数组
    reverse(nums.begin(),nums.end());
    //第二步：反转前K个元素
    reverse(nums.begin(),nums.begin() + k);
    //第三步：反转后n-k 个元素
    reverse(nums.begin() + k,nums.end());
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
  sol.rotate(nums,k);

  for(int i = 0;i<n;i++)
    {
      cout<<nums[i];
      if(i<n-1)  cout<<" ";
    }
  cout<<"\n";
  return 0;
}
