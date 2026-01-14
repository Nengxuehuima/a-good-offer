#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
int majorityElement(vector<int>& nums){
  int candidate = 0;//当前候选所述元素
  int count = 0;//计数器

  for(int num : nums){
    if(count == 0){
      //当前没有候选人，选择当前元素
      candidate = num;
      count = 1;
    }else if(num == candidate){
      //当前元素支持候选人
      count++;
    }else{
      //当前元素反对候选人
      count--;
    }
  }
  return candidate;
}
};
