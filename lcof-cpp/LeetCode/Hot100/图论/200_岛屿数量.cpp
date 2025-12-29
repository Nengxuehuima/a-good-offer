#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
int n,m;   //网格的行数和列数

int dx[4] = {-1,1,0,0};// 四个方向：上下左右
int dy[4] = {0,0,-1,1};

//使用BFS从（x，y）开始
//将整个岛屿（连通“1”）标记为已访问

void bfs(int x,int y,vector<vector<char>>& grid,vector<vector<bool>>& visited){
  queue<pair<int,int>> q;
  q.push({x,y});
  visited[x][y] = true;

  while(!q.empty()){
    auto [cx,cy] = q.front();
    q.pop();

    //向四个方向扩展
    for(int i = 0;i < 4;i++)
      {
        int nx = cx + dx[i];
        int ny = cy + dy[i];

        //边界判断
        if(nx >= 0 && nx < n && ny >= 0 && ny < m){
          //如果是陆地且未访问，则加入队列
          if(grid[nx][ny] == '1' && !visited[nx][ny]){
            visited[nx][ny] = true;
            q.push({nx,ny});
          }
        }
      }
  }
}

//主函数，计算岛屿数量
int numsIslands(vector<vector<char>>& grid){
  if(grid.empty())  return 0;

  n = grid.size();
  m = grid[0].size();

  //记录是否访问过
  vector<vector<bool>> visited(n,vector<bool>(m,false));

  int islands = 0;

  //遍历整个网络
  for(int i = 0;i < n;i++)
    {
      for(int j = 0;j < m;j++)
        {
          //发现一个新岛屿
          if(grid[i][j] == '1' && !visited[i][j]){
            island++;
            bfs(i,j,grid,visited);
          }
        }
    }
  return islands;
}
};
