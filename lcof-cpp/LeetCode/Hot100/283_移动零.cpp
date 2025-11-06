//给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

//解法一：双指针 + 交换。slow 指向“下一个非零要放的位置”，i 遍历数组；遇到非零就和 slow 位置交换，并将 slow++。
#include <bits/stdc++.h>
using namespace std;
void moveZeroes(vector<int>& nums)
{
  int slow=0;  //下一个非零应放的位置
  for(int i=0;i<(int)nums.size();i++)
    {
      if(nums[i]!=0)
      {
        if(i!=slow)
        {
          swap(nums[slow],nums[i]);//避免自交换
          slow++;
        }
      }
    }
}

int main()
{
  vector<int>a{0,1,0,3,12};
  moveZeroes(a);
  for(int x:a) cout<<x<<" ";
  cout<<"\n";
  return 0;
}

//解法二：先写非零，再补零。先把所有非零按顺序写到前面，写完后把剩余位置补成 0。

void moveZeroes(vector<int>& nums)
{
  int pos=0;
  for(int x:nums)//压缩非零
    {
      if(x!=0)
        nums[pos++]=x;
    }
  while(pos<(int)nums.size())//补零
    {
      nums[pos++]=0;
    }
}

