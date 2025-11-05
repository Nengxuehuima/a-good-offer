//给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
#include <iostream>
#include <vector>
#include <string>
#include <unorder_map>
#include <algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
  unorder_map<string,vector<string>> map;//key：排序后的字符串，value：原字符串的集合

  for(string s : strs)
    {
      string key = s;//拷贝原字符串
      sort(key.begin(),key.end());//排序作为哈希表的键
      map[key].push_back(s);//把原字符串放如对应的组
    }
  vector<vector<string>> result;
  for(auto& entry : map)
    {
      result.push_back(entry.second);//把每组异位词放入结果
    }
  return result;
}

int main()
{
  vector<string> strs={"eat","tea","ate","nat","bat"};
  vector<vector<>string> result=groupAnagram(strs);
  for(auto& group : result)
    {
      cout<<"[";
      for(auto& word : group)
        {
          cout<<word<<" ";
        }
      cout<<"]"<<endl;
    }
  return 0;
}

//使用哈希表（unordered_map）+ 排序

// 对每个字符串 s：

// 将它的字母排序，得到一个“标准形式”（key）。
// 例如 "eat" → "aet"，"tea" → "aet"。

// 用哈希表（unordered_map<string, vector<string>>）存储：

// key 为排序后的字符串（例如 "aet"）。

// value 为属于该组的所有异位词。

// 最后，将哈希表中的所有 value（即每组的字符串集合）取出组成结果。
