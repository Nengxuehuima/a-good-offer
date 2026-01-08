#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
vector<int> searchRange(vector<int>& nums,int target){
  vector<int> res(2,-1);
  int n = nums.size();
  if(n == 0) return res;

  //找左边界
  int left = 0, right = n - 1;
  while(left <= right){
    int mid = left + (right - left) / 2;
    if(nums[mid] >= target){
      right = mid - 1;
    }else{
      left = mid + 1;
    }
  }

  //检查是否存在
  if(left == n || nums[left] != target){
    return res;
  }
  res[0] = left;


  //找右边界
  int start = left;
  right = n - 1;
  while(start <= right){
    int mid = start + (right - start) / 2;
    if(nums[mid] <= target){
      start = mid +1;//继续向右逼近
    }else{
      right = mid - 1;
    }
  }

  res[1] = right;
  return res;
}
};
