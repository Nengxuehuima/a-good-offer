#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution{
public:
bool wordBreak(string s,vector<string>& wordDict){
  int n = s.size();

  //将字典转换为set,加快查找速度
  unordered_set<string> dict(wordDict.begin(),wordDict.end());
  //dp[i]表示s的前i个字符是否可以被拆分
  vector<bool> dp(n + 1,false);

  //初始化
  dp[0] = true;

  //状态转移
  for(int i = 1;i <= n;i++){
    for(int j = 0;j < i;j++){
      //如果前j个字符可拆分，且s[j....i-1]在字典中
      if(dp[j] && dict.count(s.substr(j,i - j))){
        dp[i] = true;
        break;//找到一种可能
      }
    }
  }
  return dp[n];
}
};
