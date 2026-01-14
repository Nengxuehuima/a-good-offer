#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution{
public:
  int minDistance(string word1,string word2){
  int m = word1.size();
  int n = word2.size();

  //dp[i][j]:word1 前i个字符-》word2前j个字符的最少操作数
  vector<vector<int>> dp(m + 1,vector<int>(n + 1,0));

  //初始化边界
  for(int i = 0;i <= m;i++){
    dp[i][0] = i;//删除
  }
  for(int j = 0;j <= n;j++){
    dp[0][j] = j;//插入
  }

  //状态转移
  for(int i = 1;i <= m;i++){
    for(int j = 1;j <= n;j++){
      if(word1[i - 1] == word2[j - 1]){
        //字符相同，不需要操作
        dp[i][j] = dp[i-1][j-1];
      }else{
        //三种操作取最小
        dp[i][j] = min({
          dp[i - 1][j] + 1,//删除
          dp[i][j - 1] + 1,//插入
          dp[i - 1][j - 1] + 1//替换
          });
      }
    }
  }
  return dp[m][n];
}
};
