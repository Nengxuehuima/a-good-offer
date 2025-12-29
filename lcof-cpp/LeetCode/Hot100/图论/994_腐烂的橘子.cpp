用 BFS（非常关键）
这是一个「最短时间 / 最短步数」问题
  每 1 分钟，腐烂向 四个方向扩散一格
  这正是 BFS 的定义场景
BFS = 按“层”扩散 = 按“时间”推进
所以：
  队列里存的不是“路径”
  而是 “当前这一分钟能腐烂的位置”

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
int orangesRotting(vector<vector<int>>& grid){
  int m = grid.size();//行数
  int n = grid[0].size();//列数

  queue<pair<int ,int>> q;//BFS队列，存放腐烂橘子的位置
  int fresh = 0;

  //上下左右四个方向
  int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

  //初始化：遍历整个网格
  for(int i = 0;i < m;i++){
    for(int j = 0;j < n;j++){
      if(grid[i][j]==2){
        //把所有初始腐烂的橘子加入队列
        q.push({i,j});
      }
      else if(grid[i][j]==1){
        //统计新鲜橘子数量
        fresh++;
      }
    }
  }


  //如果一开始就没有新鲜橘子
  if(fresh == 0)  return 0;

  int minutes = 0;  //记录经过的分钟数

  //BFS 按分钟扩散
  while(!q.empty()){
    int size = q.size();//当前分钟腐烂的橘子数量
    bool rotted = false;//这一分钟是否成功腐烂新橘子

    for(int i = 0;i < size;i++)
      {
        auto [x,y] = q.front();
        q.pop();

        //向四个方向扩散
        for(auto &d : dirs){
          int nx = x + d[0];
          int ny = y + d[1];

          //边界检查+只能腐烂新鲜橘子
          if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1){
            grid[nx][ny] = 2;
            fresh--;//新鲜橘子减少
            q.push({nx,ny});//加入下一分钟队列
            rotted = true;//这一分钟发生了腐烂
          }
        }
      }
    //只有当这一分钟确实腐烂了新橘子，时间才+1
    if(rotted) minutes++;
  }
  //判断是否还有新鲜橘子
  return fresh == 0 ? minutes : -1;
}
};
