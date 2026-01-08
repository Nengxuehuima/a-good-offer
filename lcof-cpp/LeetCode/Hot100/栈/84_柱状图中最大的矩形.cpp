#include <vector>
#include <stack>
using namespace std;

class Solution{
public:
int largestRectangleArea(vector<int>& heights){
  //加左右哨兵
  heights.insert(heights.begin(),0);
  heights.push_back(0);

  stack<int> st;//存下标
  int maxArea = 0;

  for(int i = 0;i < heights.size();i++){
    while(!st.empty() && heights[i] <  heights[st.top()]){
      int mid = st.top();
      st.pop();

      int height = heights[mid];
      int width = i - st.top() - 1;
      maxArea = max(maxArea,height * width);
    }
    st.push(i);
  }
  return maxArea;
}
};
