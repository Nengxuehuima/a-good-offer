//给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int longestConsecutive(const vector<int>& nums)
{
  unordered_set<int> s(nums.begin(),nums.end());//把区间 [nums.begin(), nums.end())
                                                //（也就是 nums 里的所有元素）拷贝插入到一个 unordered_set<int> 里，生成名为 s 的哈希集合。
  int ans;

  for(int x : s)
    {
      //只有当x-1不存在时，x才可能是连续序列的起点
      if(!s.count(x-1))  //!s.count(x - 1) 的意思是：判断 x-1 是否不在集合 s 里
      {
        int cur=x;
        int len=1;
        while(s.count(cur+1))
          {
            cur++;
            len++;
          }
        if(len>ans)  ans=len;
      }
    }
  return ans;
}

int main()
{
  vector<int> a{100,4,200,1,3,2};
  vector<int> b{0,3,7,2,5,8,4,6,0,1};
  vector<int> c{1,0,1,2};

  cout<<longestConsecutive(a)<<"\n";
  cout<<longestConsecutive(b)<<"\n";
  cout<<longestConsecutive(c)<<"\n";

  return 0;
  
}


// 用哈希集合 unordered_set 存所有元素。
// 对于每个元素 x，只有当 x-1 不在集合里时，才把它当作一个连续序列的起点，然后一路向上 x+1, x+2, ... 计数。
// 这样每个数最多被扫描两次（一次作为起点检查、一次在向上扩展时），均摊 O(n)。
