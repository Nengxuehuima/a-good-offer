#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
int singleNumber(vector<int>& nums){
  int result = 0;
  //对数组中所有元素进行异或运算
  for(int num : nums){
    result ^= num;
  }
  return result;
}
};
