#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
//主函数，返回第K大的元素
int findKthLargest(vector<int>& nums, int K){
  int n = nums.size();
  int target = n - K;//转换为第target小
  return quickSelect(nums,0,n - 1,target);
}

private:
//快速选择
int quickSelect(vector<int>& nums,int left,int right,int target){
  //只剩一个元素
  if(left == right) return nums[left];

  //随机选pivot(防止退化)
  int pivot = nums[left + rand() % (right - left + 1)];

  //三路划分
  int i = left;//<pivot
  int j = left;//current
  int k = right;//>pivot

  while(j <= k){
    if(nums[j] < pivot){
      swap(nums[i++] , nums[j++]);
    }
    else if(nums[j] > pivot){
      swap(nums[j] , nums[k--]);
    }
    else{
      j++;
    }
  }
  if(target >= i && target <= k) return nums[target];
  else if(target < i) return quickSelect(nums, left, i - 1, target);
  else return quickSelect(nums, k + 1, right, target);
 
}
};
