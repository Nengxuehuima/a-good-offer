解题思路（贪心 + 排序）
按区间起点升序排序（如果起点相同，按终点升序）；
用一个临时变量保存当前正在合并的区间；
遍历后续区间：
  若当前区间的起点 ≤ 上一个区间的终点，则说明重叠，合并；
  否则，说明不重叠，将当前区间加入结果列表，并更新当前区间；
遍历完成后，别忘了把最后一个区间加入结果。

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
  vector<vector<int>> merge(vector<vector<int>>& intervals)
  {
    //如果为空，则返回
    if(intervals.empty())  return {};
  
    //按起点排序（起点相同，则按照重点排序）
    sort(intervals.begin(),intervals.end());
  
    vector<vector<int>> merged;
    //先加入第一个区间
    merged.push_back(intervals[0]);
  
    for(int i=1;i < intervals.size();i++)
      {
        //取当前区间
        int start = intervals[i][0];
        int end = intervals[i][1];
  
        //取上一个区间的引用(方便直接修改)
        vector<int>& last = merged.back();//引用最后一个区间	修改 last 会同步修改 merged    back() 返回的是容器最后一个元素的“引用”，
        //vector<int>* last = &merged.back();
        //(*last)[1] = max((*last)[1], end);//指针写法，可以但更复杂
        
        //如果当前区间的起点 <= 上一个区间的终点，则重叠，合并
        if(start <= last[1])
        {
          last[1] = max(last[1],end);// 直接修改 merged 里的最后一个区间
        }
        else {
          //否则，直接加入结果
          merged.push_back({start,end});
        }
      }
  
    return merged;
  }
};


int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin>>n;//输入区间个数

  vector<vector<int>> intervals(n,vector<int>(2));
  for(int i=0;i<n;i++)
    {
      cin>>intervals[i][0]>>intervals[i][1];
    }

  Solution sol;
  vector<vector<int>>  res = sol.merge(intervals);

  for(auto& interval : res)
    {
      cout<<"["<<interval[0]<<","<<interval[1]<<"]";
    }
  cout<<"\n";

  return 0;
}
