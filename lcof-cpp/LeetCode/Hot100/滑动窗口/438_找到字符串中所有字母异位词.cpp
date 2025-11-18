核心思想：
我们在 s 上用一个长度为 p.size() 的滑动窗口，
实时维护窗口内各字符出现的次数。
如果当前窗口的字符频次与 p 的频次相同，就说明找到了一个异位词。

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
  vector<int> findAnagrams(string ,string p)
  {
    vector<int> res;  //存放结果下标
    if(s.size() < p.size())  return res;
  
    vector<int> need(26,0),window(26,0);
    int m = p.size(),n = s.size();
  
    //统计p中每个字符的频次
    for(char c : p)  need[c-'a']++;
  
    //滑动窗口遍历s
    for(int right = 0;right < n;++right)
      {
        window[s[right]-'a']++;//将右端字符加入窗口
        //当窗口长度大于p，左指针右移，移除最左字符
        if(right >= m)
          window[s[right - m]-'a']--;
  
          //当窗口长度等于p且字符频数相同时，找到下一个异位词
          if(right >= m - 1 && window == need)
            res.push_back(right - m + 1);
       } 
          return res;
  }
};  

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s,p;
  cin>>s>>p;

  Solution sol;
  vector<int> ans = sol.findAnagrams(s,p);

  for(int i = 0;i<(int)ans.size();i++)
    {
      if(i) cout<<" ";
      cout<<ans[i];
    }
  cout<<endl;
  return 0;
}
