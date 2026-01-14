#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
int expandAroundCenter(const string& s, int left, int right){
  while(left >= 0 && right < s.size() && s[left] == s[right]){
    left--;
    right++;
  }
  //回文长度
  return right - left - 1;
}

//求最长回文子串
string longestPalindrome(string s){
  int n = s.size();
  if(n < 2) return s;

  int start = 0;//最长回文起点
  int maxlen = 1;//最长回文长度

  for(int i = 0;i < n; i++){
    //奇数长度回文
    int len1 = expandAroundCenter(s , i , i);
    //偶数长度回文
    int len2 = expandAroundCenter(s,i,i + 1);

    int len = max(len1, len2);

    if(len > maxlen){
      maxlen = len;
      start = i - (len - 1) / 2;
    }
  }

  return s.substr(start,maxlen);
}
};
