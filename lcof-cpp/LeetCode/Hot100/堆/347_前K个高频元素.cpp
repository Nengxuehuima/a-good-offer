#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
vector<int> topKFrequent(vector<int>& nums, int k){
  unordered_map<int,int> freq;

  //1.统计概率
  for(int x : nums){
    freq[x]++;
  }

  int n = nums.size();
  //2.桶：下标表示频率
  vector<vector<int>> bucket(n + 1);
  for(auto& [num,f] : freq){
    bucket[f].push_back(num);
  }
  //3.从高频到低频收集
  vector<int> res;
  for(int f = n; f >= 1 && res.size() < k; f--){
    for(int x : bucket[f]){
      res.push_back(x);
      if(res.size() == k) break;
    }
  }
  return res;
}
};
