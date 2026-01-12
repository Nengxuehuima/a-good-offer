#include <bits/stdc++.h>
using namespace std

class Solution{
public:
int jump(vector<int>& nums){
  int steps = 0;//已经跳了多少次
  int curEnd =0;//当前跳的范围边界（本次跳最多能覆盖到哪）
  int maxReach = 0;//在下一跳前，我最远能到哪里

  for(int i = 0;i < nums.size() - 1;i++){
    maxReach = max(maxReach,i + nums[i]);
    if(i == curEnd){    //到达当前跳的边界
      steps++;   //再跳一步
      curEnd = maxReach;//更新下一跳能去到的最远位置
    }
  }
  return steps;
}
};
