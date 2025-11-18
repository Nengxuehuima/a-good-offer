解题思路：滑动窗口（Two Pointers）
我们使用一个窗口 [left, right) 来表示当前正在检查的子串。
随着 right 向右移动：
  如果当前字符没出现过 → 加入窗口
  如果出现过 → 移动 left 缩小窗口，直到没有重复。
用一个哈希表（或数组）map<char,int> 记录每个字符最后出现的位置。


#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
int lengthOfLongestSubstring(string s){
  unordered_map<char,int> lastPos;//记录每个字符最后一次出现的位置
  int left;//当前窗口左边界
  int maxlen;//最长子串长度

  for(int right = 0;right < (int)s.size();++right)
    {
      char c = s[right];

      //如果字符c在当前窗口中已存在，说明left需要右移到该字符上次出现位置的下一位
      if(lastPos.count(c) && lastPos[c] >= left)
      {
        left = lastPos[c] + 1;
      }
      //更新该字符最后出现的位置
      lastPos[c] = right;
      //计算当前窗口的长度，并更新最大值
      maxlen = max(maxlen,right - left + 1);
    }
  return maxlen;
}
};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin>>s;

  Solution sol;
  cout<<sol.lengthOfLongestSubstring(s)<<"\n";

  return 0;
}
