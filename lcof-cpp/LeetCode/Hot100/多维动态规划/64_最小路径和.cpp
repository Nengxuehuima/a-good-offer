#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
int minPathSum(vector<vector<int>>& grid){
  int m = grid.size();
  int n = grid[0].size();
  //dp[i][j]表示达到（i,j）的最小路径和
  vector<vector<int>> dp(m,vector<int>(n,0));

  //起点初始化
  dp[0][0] = grid[0][0];

  //初始化第一列
  for(int i = 1;i < m;i++){
    dp[i][0] = dp[i - 1][0] + grid[i][0];
  }
  //初始化第一行

  for(int j = 1;j < n;j++){
    dp[0][j] = dp[0][j - 1] + grid[0][j];
  }

  //状态转移
  for(int i = 1;i < m;i++){
    for(int j = 1;j < n;j++){
      dp[i][j] = min(dp[i - 1][j],dp[i][j - 1]) + grid[i][j];
    }
  }

  return dp[m - 1][n - 1];
}
};
