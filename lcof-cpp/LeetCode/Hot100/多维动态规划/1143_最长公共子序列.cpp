#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution{
int longestCommonSubsequence(string text1, string text2){
  int m = text1.size();
  int n = text2.size();

  //dp[i][j] 表示text1的前i个字符
  //和text2的前j个字符的最长公共子序列长度
  vector<vector<int>> dp(m + 1,vector<int>(n + 1,0));

  //状态转移
  for(int i = 1;i <= m;i++){
    for(int j = 1;j <= n;j++){
      if(text1[i - 1] == text2[j - 1]){
        dp[i][j] = dp[i - 1][j - 1] + 1;
      }else{
        dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
      }
    }
  }

  return dp[m][n];
}
};
