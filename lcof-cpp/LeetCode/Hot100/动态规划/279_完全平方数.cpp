#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution{
public:
int numSquares(int n){
  //dp[i]表示和为i的最少完全平方数数量
  vector<int> dp(n + 1,INT_MAX);

  //初始化
  dp[0] = 0;
  //从1到n依次计算
  for(int i = 1;i <= n;i++){
    //尝试所有j*j <= i的完全平方
    for(int j = 1;j * j <= i;j++){
      dp[i] = min(dp[i], dp[i - j * j] + 1);
    }
  }
  return dp[n];
}
};
