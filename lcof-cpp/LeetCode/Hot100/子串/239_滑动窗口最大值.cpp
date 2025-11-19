高效解法：单调队列（Deque）O(n)
核心思想
维护一个单调递减队列（存储下标）：
  队列中对应的元素值是递减的；
  队首元素永远是当前窗口最大值的下标。
每次滑动窗口时：
  移除队首：如果队首下标已经滑出窗口；
  移除队尾：如果新来的元素更大，就把队尾的小元素都弹出；
  将新元素下标入队；
  队首元素对应的值就是当前窗口最大值。

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
  vector<int> maxSlidingWindow(vector<int>& nums,int k)
  {
    deque<int> dq;//存放下标，保证队列单调递减
    vector<int> res;
  
    for(int i=0;i<nums.size();i++)
      {
        //移除划出窗口的元素(队首下标超出范围)
        if(!dq.empty()&&dq.front() <= i-k)
          dq.pop.front();//删除队首的元素
  
        //维护单调性，移除队尾小于当前元素的下标
        while(!dq.empty() && nums[dq.back()] < nums[i])
          dq.pop_back();//删除队尾的元素
  
        //当前元素下标入队
        dq.push_back(i);//在队尾插入一个元素
  
        //当窗口长度 >= k 时，记录最大值(队首)
        if(i >= k -1)
          res.push_back(nums[dq.front()]);
      }
    return res;
  }
};


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,k;
  cin>>n>>k;
  vector<int> nums(n);
  for(int i=0;i<n;i++) cin>>nums[i];

  Solution sol;
  vector<int> ans = sol.maxSlidingWindow(nums,k);

  for(int i=0;i<ans.size();++i)
    {
      if(i) cout<<" ";
      cout<<ans[i];
    }
  cout<<"\n";
  return 0;
}
