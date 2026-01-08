#include <vector>
#include <stack>
using namespace std;

class Solution{
public:
vector<int> dailyTemperatures(vector<int>& temperatures){
  int n = temperatures.size();
  vector<int> answer(n,0);
  stack<int> st;//存下标

  for(int i = 0;i < n;i++){
    while(!st.empty() && temperatures[i] > temperatures[st.top()]){
      int idx = st.top();
      st.pop();
      answer[idx] = i - idx;
    }
    st.push(i);
  }
  return answer;
}
};
