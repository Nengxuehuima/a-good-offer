#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
int findDuplicate(vector<int>& nums){
  //快慢指针寻找相遇点
  int slow = nums[0];
  int fast = nums[0];

  do{
    slow = nums[slow];//慢指针走一步
    fast = nums[nums[fast]];//指针走两步
    
  }while(slow != fast);

  //阶段二，找到环入口（重复数字）
  slow = nums[0];
  while(slow != fast){
    slow = nums[slow];
    fast = nums[fast];
  }
  return slow;//环入口即为重复数字
}
};
