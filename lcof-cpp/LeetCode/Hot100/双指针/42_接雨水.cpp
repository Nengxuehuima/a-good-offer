双指针法（最优解）
思路步骤：
1、设定左右指针 left = 0，right = n-1；
2、同时维护：
  左边最高柱 left_max
  右边最高柱 right_max
3、当 height[left] < height[right] 时：
  若 height[left] < left_max，则此处能接的水为 left_max - height[left]
  否则更新 left_max
  左指针右移
4、否则对右指针做同样的操作。
5、遍历结束得到总的水量。

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
  //主函数，计算能接的雨水总量
  int trap(vector<int>& height)
  {
    int n = height.size();
    if(n == 0)  return 0;//空数组直接返回0
  
    int left = 0;//左指针
    int right = n-1;//右指针
    int left_max = 0;//当前左边最高的柱子高度
    int right_max = 0;//当前右边最高柱子的高度
    int res = 0;//累积雨水量
  
    //当前左右指针未相遇时循环
    while(left<right)
      {
        //谁高度更低，就由谁那一侧计算水量
        if(height[left] < height[right])
        {
          //如果当前左柱子比已知的最高左柱子低，能积水
          if(height[left] >= left_max)
            left_max = height[left];//更新左最大值
          else 
            res += left_max - height[left];//积水量=左最大值-当前高度
          ++left;//左指针右移；
        }
        else
        {
          //如果当前右柱子比已知的最高右柱子低，能积水
          if(height[right] >= right_max)
            right_max = height[right];
          else
            res += right_max - height[right];//积水量 = 右最大-当前高度
          --right;
        }
      }
    return res;//返回总积水量
  }
};
int main()
{
  ios::sync_with_stido(false);
  cin.tie(nullptr);

  vector<int> height;
  int x;

  while(cin>>x) height.push_back(x);

  Soltion s;
  cout<<s.trap(height)<<"\n";
  return 0;
}
