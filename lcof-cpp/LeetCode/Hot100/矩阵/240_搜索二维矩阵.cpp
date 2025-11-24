核心思想：从右上角开始搜索
1、从矩阵的右上角（matrix[0][n-1]）开始。
2、设当前位置为 (row, col)：
  若 matrix[row][col] == target，返回 true
  若 matrix[row][col] > target，则当前列的值都比 target 大 → 向左移动 (col--)
  若 matrix[row][col] < target，则当前行的值都比 target 小 → 向下移动 (row++)
3、超出边界（row >= m 或 col < 0）则返回 false

#include <bits.stdc++.h>
using namespace std;

class Solution{
public:
  bool searchMatrix(vector<vector<int>>& matrix,int target)
  {
    int m = matrix.size();
    if(m==0) return false;
    int n = matrix[0].size();
  
    //从右上角开始搜索
    int row = 0;
    int col = n-1;
  
    while(row < m && col >=0)
      {
        int val = matrix[row][col];
        if(val == target)
          return true;
        else if(val > target)
          col--;//当前值太大，向左移动
        else row++;//当前值太小，向下移动
      }
    return false;
  }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n, target;
    // 输入矩阵大小和目标值
    cin >> m >> n >> target;

    vector<vector<int>> matrix(m, vector<int>(n));
    // 输入矩阵元素
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    Solution sol;
    bool result = sol.searchMatrix(matrix, target);
    
    cout << (result ? "true" : "false") << "\n";
    return 0;
}
