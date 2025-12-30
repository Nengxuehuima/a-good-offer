#include <bits/stdc++.h>
using namespace std;

class NQueenSolver{
private:
vector<vector<string>> ans;//所有解
vector<string> board;//当前棋盘

vector<bool> col;//列是否被占用
vector<bool> diag1;//主对角线(row - col + n - 1)
vector<bool> diag2;//富对角线（row+col）

int n;

//在第row行放皇后
void dfs(int row){
  //终止条件，所有行都放完
  if(row == n){
    ans.push_back(board);
    return;
  }

  //枚举当前行的每一列
  for(int c = 0;c < n;c++){
    int d1 = row - c + n - 1;
    int d2 = row + c;

    //剪枝，不能放
    if(col[c] || diag1[d1] || diag2[d2]) continue;

    //放皇后
    board[row][c] = 'Q';
    col[c] = diag1[d1] = diag2[d2] = true;

    //递归放下一行
    dfs(row + 1);

    //回溯，撤销皇后
    board[row][c] = '.';
    col[c] = diag1[d1] = diag2[d2] = false;
  }
}

public:
vector<vector<string>> solveNQueens(int n_){
  n = n_;
  ans.clear();

  board.assign(n,string(n,'.'));
  col.assign(n,false);
  diag1.assign(2 * n - 1,false);
  diag2.assign(2 * n -1 ,false);

  dfs(0);
  return ans;
}
};
