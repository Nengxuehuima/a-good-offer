#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
bool canJump(vector<int>& nums){
  int maxReach = 0;
  for(int i = 0;i < nums.size();i++){
    if(i > maxReach) return false;//到不了当前位置
    maxReach = max(maxReach, i + nums[i]);//更新最远能跳到哪里
  }
  return true;
}
};
