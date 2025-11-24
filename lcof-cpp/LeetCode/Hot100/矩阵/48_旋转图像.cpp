旋转 90° 顺时针可以分解为两个简单的操作：
转置 + 翻转
1、转置矩阵（沿主对角线翻转）
  即 matrix[i][j] ↔ matrix[j][i]
2、每一行左右翻转
  即将每一行的元素反转：

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
   void rotate(vector<vector<int>>& matrix)
  {
    int n = matrix.size();
    //step1:转置矩阵
    for(int i=0;i<n;i++)
      {
        for(int j=i+1;j<n;j++)
          {
            swap(matrix[i][j],matrix[j][i]);
          }
      }
    //step2：每一行翻转
    for(int i=0;i<n;i++)
      {
        reverse(matrix[i].begin(),matrix[i].end());
      }
  }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n; // 输入矩阵大小
    vector<vector<int>> matrix(n, vector<int>(n));

    // 输入矩阵元素
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> matrix[i][j];

    Solution().rotate(matrix); // 调用旋转函数

    // 输出旋转后的矩阵
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << matrix[i][j] << (j == n - 1 ? '\n' : ' ');
    }

    return 0;
}
