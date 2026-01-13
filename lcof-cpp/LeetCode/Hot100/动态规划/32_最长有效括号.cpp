#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution{
public:
int longestValidParentheses(string s){
  int n = s.size();
  if(n == 0) return 0;

  vector<int> dp(n,0);
  int ans = 0;

  for(int i = 1;i < n;i++){
    if(s[i] == ')'){
      //情况1 ....()
      if(s[i -1] == '('){
        dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
        
      }
      //情况2...))
      else{
        int j = i - dp[i -1] - 1;
        if(j >= 0 && s[j] == '('){
          dp[i] = dp[i - 1] + 2 + (j >= 1 ? dp[j - 1] : 0);
        }
      }
      ans = max(ans,dp[i]);
    }
  }
  return ans;
}
};
