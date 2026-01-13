#include <iostream>
using namespace std;

class Solution{
public:
long long climbStairs(int n){
  //特殊情况处理
  if(n == 1) return 1;
  if(n == 2) return 2;

  //prev2 表示dp[i-2]
  //prev1 表示dp[i-1]

  long long prev2 = 1;
  long long prev1 = 2;
  long long cur = 0;

  //从第3阶开始递推
  for(int i = 3;i <= n;i++){
    cur = prev1 + prev2;//状态转移方程
    prev2 = prev1;//更新dp[i-2]
    prev1 = cur;//更新dp[i-1]
  }
  return cur;
}
};
