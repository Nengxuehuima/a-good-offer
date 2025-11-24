思路分析
最简单的思路是：
  扫描整个矩阵；
  记录所有出现 0 的行和列；
  再遍历一次，将对应行列设为 0。
但是这样需要额外的 O(m+n) 空间（用于记录行和列），
题目要求 “原地算法”，所以我们要优化空间。

    空间优化技巧（关键思路）
核心思路：
    我们可以用矩阵的第一行和第一列本身来充当“标记数组”。

#include <bits/stdc++.h>
using namespace std;

class Solutio{
public:
  void setZeroes(vector<vector<int>>& matrix)
  {
         int m = matrix.size();
        if (m == 0) return;          // 防止空矩阵
        int n = matrix[0].size();
        if (n == 0) return;          // 防止 [[]] 这种情况
  
    bool firstRowZero = false;//第一行是否需要清零
    bool firstColZero = false;//第一列是否需要清零
  
    //step1： 检查第一行和第一列是否含0
    for(int j = 0;j<n;j++)
      {
        if(matrix[0][j] == 0)
        {
          firstRowZero = true;
        break;
        }
      }
    for(int i = 0;i<m;i++)
      {
        if(matrix[i][0] == 0)
        {
          firstColZero = true;
        break;
        }
      }
    //step2：使用第一行和第一列做标记，若matrix[i][j]==0.则对应行列首位置为0
    for(int i=1;i<m;i++)
      {
        for(int j=1;j<n;j++)
          {
            if(matrix[i][j] == 0)
            {
              matrix[i][0] = 0;//标记该行
              matrix[0][j] = 0;//标记该列
            }
          }
      }
  
    //step3：根据标记清理(跳过首行是首列)
    for(int i=1;i<m;i++)
      {
        for(int j=1;j<n;j++)
          {
            if(matrix[i][0] == 0 || matrix[0][j] == 0)
              matrix[i][j] = 0;
          }
      }
  
    //step4：处理地一行和第一列
    if(firstRowZero)
    {
      for(int j=0;j<n;j++)
        matrix[0][j]=0;
    }
    if(firstColZero)
    {
      for(int i=0;i<m;i++)
        matrix[i][0] = 0;
    }
  }
};

int main(){
  ios::sync_with_stdio(false);
  cin>>tie(nullptr);

  int m,n;
  cin>>m>>n;
  vector<vector<int>> matrix(m,vector<int>n);

  for(int i=0;i<m;i++)
    {
      for(int j=0;j<n;j++)
        cin>>matrix[i][j];
    }

  Solution sol;
  sol.setZeros(matrix);

  for(int i=0;i<m;i++)
    {
      for(int j=0;j<n;j++)
        if(j)  cout<<" ";
          cout<<matrix[i][j];
    }
  cout<<endl;
  return 0;
}
