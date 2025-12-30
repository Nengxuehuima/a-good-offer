#include <bits/stdc++.h>
using namespace std;

class PalindromePartitionSolver{
private:
vector<vector<string>> ans;//所有分隔方案 
vector<string> path;//当前分割路径

//判断s[l..r]是否是回文串
bool isPalindrome(const string& s, int l, int r){
  while(l < r){
    if(s[l] != s[r]) 
      return false;
    l++;
    r--;
  }
  return true;
}

//从start开始切割字符串
void dfs(const string& s,int start){
  //终止条件；切到字符串末尾
  if(start == (int)s.size()){
    ans.push_back(path);
    return ;
  }
  //尝试所有切割位置
  for(int end = start;end < (int)s.size();end++){
    //只有回文串才继续
    if(!isPalindrome(s,start,end)) continue;

    //选择当前回文子串
    path.push_back(s.substr(start,end-start + 1));

    //递归切割剩余部分
    dfs(s,end + 1);

    //回溯，撤销选择
    path.pop_back();
  }
}

public:
vector<vector<string>> partition(const string& s){
  ans.clear();
  path.clear();
  dfs(s,0);
  return ans;
}
};
