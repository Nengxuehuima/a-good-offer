#include <iostream>
#inlcude <vector>
using namespace std;

class Solution{
public:
  int searchInsert(vector<int>& nums, int target){
    int left = 0;
    int right = nums.size() - 1;
  
    //二分查找
    while(left <= right)
      {
        int mid = left + (right - left) / 2;
  
        if(nums[mid] == target){
          return mid;//找到目标
        }else if (nums[mid] < target){
          left = mid + 1;//搜索右半部分
        }else {
          right = mid - 1;//搜索左半部分
        }
      }
  
    return left;//未找到，left即为插入位置
  }
};
