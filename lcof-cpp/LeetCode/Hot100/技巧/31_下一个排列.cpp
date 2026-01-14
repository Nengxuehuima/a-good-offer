#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:

  void nextPermutation(vector<int>& nums){
  int n = nums.size();
  int i = n - 2;

  //1.从右向左寻找第一个下降的位置
  while(i >= 0 && nums[i] >= nums[i + 1]){
    i--;
  }

  //2.如果找到pivot
  if(i >= 0){
    int j = n - 1;
    //从右向左寻找第一个比nums[i]大的数
    while(nums[j] <= nums[i]){
      j--;
    }
    //交换
    swap(nums[i],nums[j]);
  }

  //3.翻转pivot右侧的部分
  reverse(nums.begin() + i + 1,nums.end());
}
};
