#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution{
public:
string decodeString(string s){
  stack<int> countStack;
  stack<string> stringStack;

  string curStr = "";
  int curNum = 0;

  for(char c : s){
    if(isdigit(c)){
      //处理多位数字
      curNum = curNum * 10 + (c - '0');
    }
    else if(c == '['){
      //保存当前状态
      countStack.push(curNum);
      stringStack.push(curStr);

      curNum = 0;
      curStr = "";
    }
    else if(c == ']'){
      //结束当前层
      int repeat = countStack.top();
    countStack.pop();

    string preStr = stringStack.top();
    stringStack.pop();

    string temp = "";
    for(int i = 0;i<repeat;i++){
      temp += curStr;
    }

    curStr = preStr + temp;
    }
  else{
    //普通字符
    curStr += c;
  }
  }
return curStr;
}
};
