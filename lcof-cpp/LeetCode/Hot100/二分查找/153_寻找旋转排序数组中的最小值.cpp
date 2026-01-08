#inlcude <iostream>
#inlcude <vector>
using namespace std;

class Solution{
public:
int findMin(vector<int>& nums){
  int left = 0,right = nums.size() - 1;

  while(left < right){
    //如果当前区间已经有序，直接返回最左元素
    if(nums[left] <= nums[right]){
      return nums[left];
    }

    int mid = left + (right - left) / 2;

    //左边部分是有序的，最小值在右半
    if(nums[mid] >= nums[left]){
      left = mid + 1;
    }
    //最小值在左半（包括mid）
    else{
      right = mid;
    }
  }
  //left == right
  return nums[left];
}
};
