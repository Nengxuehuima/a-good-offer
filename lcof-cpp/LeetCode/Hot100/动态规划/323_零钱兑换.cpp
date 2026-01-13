#inlcude <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution{
public:

int coinChange(vector<int>& coins,int amount){
  //dp[i]表示凑成金额i的最少硬币数
  vector<int> dp(amount + 1,INT_MAX);
  //初始化
  dp[0] = 0;

  //计算dp[1]到dp[amount]
  for(int i = 1;i <=amount;i++){
    for(int coin : coins){
      if(i >= coin && dp[i - coin] != INT_MAX){
        dp[i] = min(dp[i],dp[i - coin] + 1);
      }
    }
  }
  //如果仍然不等，返回-1；
  return dp[amount] == INT_MAX ? -1 : dp[amount];
}
};
