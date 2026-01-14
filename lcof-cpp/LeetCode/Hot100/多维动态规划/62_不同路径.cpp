#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
long long uniquePaths(int m,int n){
  //创建一个m×n的二维数组dp
  vector<vector<long long>> dp(m,vector<long long>(n,0));

  //初始化第一列，只能从上到下
  for(int i = 0;i < m;i++){
    dp[i][0] = 1;
  }
  //初始化第一行，只能从左向右
  for(int j = 0;j < n;j++){
    dp[0][j] = 1;
  }

  //动态规划
  for(int i = 1;i < m;i++){
    for(int j = 1;j < n;j++){
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }
  }

  return dp[m - 1][n - 1];
}
};
