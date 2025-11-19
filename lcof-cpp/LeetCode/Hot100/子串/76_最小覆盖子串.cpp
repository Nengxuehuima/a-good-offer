解题思路：滑动窗口（双指针 + 计数）
这是典型的 滑动窗口 + 哈希表计数 问题。
 核心思路：
我们在 s 上维护一个窗口 [left, right)，
让窗口内始终尽量包含 t 的所有字符。
步骤如下 
1️⃣ 准备阶段
  用一个哈希表 need 统计 t 中每个字符需要的次数；
  用另一个哈希表 window 统计当前窗口中每个字符的次数；
  用一个变量 valid 表示当前窗口中有多少个字符达到了 t 的要求。
2️⃣ 扩大窗口（右指针）
  每次把 s[right] 加入窗口；
  如果该字符是 t 中需要的，就更新 window，并检查是否达到需求；
  当窗口包含了全部 t 的字符时，尝试缩小窗口。
3️⃣ 收缩窗口（左指针）
  当窗口已经满足条件时，记录当前长度；
  然后移动 left，移除左边字符，直到窗口不再满足条件；
  不断更新最短长度的子串。
4️⃣ 返回结果
  记录最短的合法窗口 [start, end)；
  若未找到，返回空字符串。

#include <bits/stdc++.h>
using namespace std;

class Solution{
  string minWindow(string s,string t)
  {
    unordered_map<char,int> need,window;
    for(char c : t) need[c]++;
    
    int left = 0,right = 0;
    int valid = 0;//满足条件的字符种类数
    int start = 0,len = INT_MAX;
    
    while(right < s.size())
      {
        char c = s[right];
        right++;//扩大窗口
        if(need.count(c))
        {
          window[c]++;
          if(window[c] == need[c]) valid++;
        }
    
        //当窗口已经满足条件
        while(valid == need.size())
          {
            //更新最小窗口
            if(right - left < len)
            {
              start = left;
              len = right - left;
            }
    
          //移动左指针缩小窗口
          char d = s[left];
          left++;
          if(need.count(d))
          {
            if(window[d] == need[d]) valid--;
            window[d]--;
          }
        }
      }
    return (len == INT_MAX)?"":s.substr(start,len);
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s,t;
  sin>>s>>t;

  Solution sol;
  cout<<sol.minWindow(s,t)<<"\n";
}
