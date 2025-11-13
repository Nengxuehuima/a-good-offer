1、初始化：设置两个指针 l 和 r，分别指向数组的两端，并初始化最大面积为 0。
2、计算面积：计算当前两条线之间形成的容器的面积，更新最大面积。
3、移动指针：根据当前两个指针指向的线的高度，决定移动哪个指针。
4、如果 height[l] < height[r]，则移动左指针 l++。
5、如果 height[l] >= height[r]，则移动右指针 r--。
6、终止条件：当两个指针相遇时，停止计算，返回最大面积。
用到的算法与数据结构
1、双指针算法：通过维护两个指针从数组的两端向中间移动来优化搜索过程，减少不必要的计算。
2、贪心策略：每次选择移动较短的一侧，以期获得更大的容器面积。这个策略的核心是：如果当前容器的面积小，移动较短的线可能提高面积，因为宽度减少的同时可能会增加高度。

#include <bits/stdc++.h>
using namespace std;

//计算最大盛水量:双指针 O(n)
long long maxArea(const vector<int>& h)
{
  int n = (int)h.size();//获取数组的长度
  if(n<2) return 0;//至少需要两条边
  int l=0,r=n-1;//定义左右指针
  long long ans=0;
  while(l<r)
    {
      long long height = min(h[l],h[r]);
      long long width = r-l;
      ans = max(ans,height*width);
      //移动较短的一侧，尝试寻找更高的模板
      if(h[l]<h[r])  ++l;
      else --r;
    }
  return ans;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  while((cin>>n))
    {
      vector<long long> a(n);
      for(int i=0;i<n;i++)  cin>>a[i];
      cout<<maxAre(a)<<"\n";
    }
  return 0;
}
