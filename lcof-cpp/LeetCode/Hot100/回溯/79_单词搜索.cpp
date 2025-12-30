#inlcude <bits/stdc++.h>
using namespace std;

class WordSearchSolver{
private:
int m,n;
vector<vector<bool>> visited;

//四个方向
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

//从（x，y）开始，匹配word[idx...]
bool dfs(vector<vector<char>>& board,string& word,int x,int y,int idx){
  //成功匹配所有字符
  if(idx == (int)word.size())
    return true;

  //越界检查
  if(x < 0 || x >= m || y < 0 || y >= n)
    return false;

  //已访问 or 字符不匹配
  if(visited[x][y] || board[x][y] != word[idx])
    return false;

  //标记当前格子已使用
  visited[x][y] = true;

  //向四个方向搜索
  for(int d = 0;d < 4;d++)
    {
      int nx = x + dx[d];
      int ny = y + dy[d];
      if(dfs(board,word,nx,ny,idx + 1))
        return true;
    }

  //回溯，恢复状态
  visited[x][y] = false;
  return false;
}

public:
bool exist(vector<vector<char>>& board,string word){
  m = board.size();
  n = board[0].size();
  visited.assign(m,vector<bool>(n,false));

  //枚举所有起点
  for(int i = 0;i < m;i++)
    {
      for(int j = 0;j < n;j++)
        {
          if(dfs(board,word,i,j,0))
            return true;
        }
    }
  return false;
}
};
