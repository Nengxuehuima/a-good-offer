#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
vector<int> partitionLabels(string s){
  vector<int> last(26);
  //1.记录每个字符最后出现的位置
  for(int i = 0;i < s.size();i++){
    last[s[i] - 'a'] = i;
  }

  vector<int> res;
  int start = 0,end = 0;

  //贪心切割
  for(int i = 0;i < s.size();i++){
    end = max(end,last[s[i] - 'a']);//更新当前区间最远边界
    if(i == end){
      res.push_back(end - start + 1);
      start = i + 1;
    }
  }
  return res;
}
};
