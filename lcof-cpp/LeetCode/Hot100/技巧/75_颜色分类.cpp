#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
void sortColors(vector<int>& nums){
  int low = 0;//下一个0的位置
  int high = nums.size() - 1;//下一个2的位置
  int i = 0;//当前指针

  while(i <= high){
    if(nums[i] == 0){
      //当前是0.放到左边
      swap(nums[i],nums[low]);
      low++;
      i++;
    }else if(nums[i] == 1){
      //当前是1，位置正确
      i++;
    }else{
      //nums[i] == 2,当前是2，放到右边
      swap(nums[i],nums[high]);
      high--;//i不自增，因为换过来的元素还未判断
    }
  }
}
};
