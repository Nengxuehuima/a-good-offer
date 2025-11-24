#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix)
  {
    vector<int> res;
    if(matrix.empty() || matrix[0].empty())  return res;//防止空矩阵
  
    int m = matrix.size();
    int n = matrix[0].size();
    int top = 0,bottom = m-1;
    int left = 0,right = n-1;
  
    while(top <= bottom && left <= right)
      {
        //从左到右
        for(int j=left;j<=right;j++)
          res.push_back(matrix[top][j]);
        top++;//上边界下移
  
        //从上到下
        for(int i=top;i<=bottom;i++)
          res.push_back(matrix[i][right]);
        right--;
  
        //从右到左
        if(top <= bottom)
        {
          for(int j=right;j>=left;j--)
            res.push_back(matrix[bottom][j]);
          bottom--;
        }
  
        //从下到上
        if(left<=right)
        {
          for(int i=bottom;i>=top;i--)
            res.push_back(matrix[i][left]);
          left++;
        }
      }
    return res;
  }
};

int main(){
  ios::sync_with_stdio(false);
  cin>>tie(nullptr);

  int n,m;
  cin>>n>>m;

  vector<vector<int>> matrix(m,vector<int>(n));
  for(int i=0;i<m;i++)
      for(int j=0;j<n;j++)
          cin>>matrix[m][n];
  Solution sol; 
  vector<int>res = sol.spiralOrder(matrix);
   for (int i = 0; i < res.size(); ++i) {
        if (i) cout << " ";
        cout << res[i];
    }
    cout << "\n";
    return 0;
}
