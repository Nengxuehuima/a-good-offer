#include <bits/stdc++.h>
using namespace std;

class ParenthesisSolver{
private:
vector<string> ans;//保存所有合法括号组合
string path;//当前构造的括号字符串

//left:已使用的‘（’数量
//right:已使用的‘）’数量

void dfs(int n,int left,int right){
  //终止条件，长度达到2n
  if((int)path.size() == 2 * n){
    ans.push_back(path);
    return ;
  }

  //尝试加左括号
  if(left < n){
    path.push_back('(');
    dfs(n,left + 1,right);
    path.pop_back();//回溯
  }
  //尝试加右括号
  if(right < left){
    path.push_back(')');
    dfs(n,left,right + 1);
    path.pop_back();//回溯
  }
  
}

public:
vector<string> generateParenthesis(int n){
  ans.clear();
  path.clear();
  dfs(n,0,0);
  return ans;
}
};
