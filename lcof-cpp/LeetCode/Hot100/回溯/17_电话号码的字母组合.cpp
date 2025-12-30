#include <bits/stdc++.h>
using namespace std;

class PhoneLetterSolver{
private:
vector<string> ans;//保存所有组合
string path;//当前正在构造的字符串

//数字到字母的映射(下标0~9)
vector<string> mapping = {
"",//0;
"",//1
"abc",//2
"def",//3
"ghi",//4
"jkl",//5
"mno",//6
"pqrs",//7
"tuv",//8
"wxyz"//9
};

//从digits[index]开始处理
void dfs(const string& digits,int index){
  //终止条件，所有数字都处理完
  if(index == (int)digits.size()){
    ans.push_back(path);
    return;
  }

  int digit = digits[index] - '0';
  const string& letters = mapping[digit];

  //枚举当前数字对应的每一个字母
  for(char c : letters){
    path.push_back(c);//选择
    dfs(digits,index + 1);//递归
    path.pop_back();//回溯
  }
}

public:
vector<string> letterCombinations(const string& digits){
  ans.clear();
  path.clear();

  //特殊情况，空输入
  if(digits.empty()) return ans;

  dfs(digits,0);
  return ans;
}
};
