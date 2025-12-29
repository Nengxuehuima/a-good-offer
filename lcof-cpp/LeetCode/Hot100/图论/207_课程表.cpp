用「拓扑排序（BFS / Kahn 算法）」？
拓扑排序的核心思想：
  每次选择一个 入度为 0 的节点（没有前置依赖）
  “学习”它，然后删除它对其他课程的影响
  最后：
    如果能学完所有课程 → 无环
    否则 → 有环
  这是判断有向图是否有环的经典方法
整体解题思路（四步）
Step 1️⃣ 建图
  邻接表 graph
  入度数组 indegree
Step 2️⃣ 把所有「入度为 0」的课程入队
Step 3️⃣ BFS（拓扑排序）
  每出队一个课程，表示“学完一门课”
  它指向的课程入度减 1
  若某课程入度变成 0，入队
Step 4️⃣ 判断是否学完所有课程


#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
    //构件课程邻接表：graph[b]中存放所有依赖b的课程
    vector<vector<int>> graph(numCourses);
    // 入度数组：indegree[i] 表示课程 i 还有多少门前置课程
    vector<int> indegree(numCourses,0);
  
    //读取先修关系，建图+统计入度
    for(auto& p : prerequisites){
      int a = p[0];//要学的课程
      int b = p[1];//先修课程
  
      graph[b].push_back(a);//b->a
      indegree[a]++;//a的入度+1
    }
  
    //队列：存放所有[入度为0]的课程
  
    queue<int> q;
  
    //把所有没有前置课程的课加入队列
    for(int i = 0;i<numCourses;i++){
      if(indegree[i] == 0){
        q.push(i);
      }
    }
  
    int finished = 0;//已完成课程数量
  
    //拓扑排序（BFS）
    while(!q.empty()){
      int cur = q.front();
      q.pop();
  
      finished++;//当前课程可以学习
  
      //遍历所有依赖当前课程的课程
      for(int next : graph[cur]){
        indegree[next]--;//前置课程少了一门
  
        //如果next的前置课程都学完了
        if(indegree[next] == 0){
          q.push(next);
        }
      }
    }
    //判断是否所有课程都完成
    return finished == numCourses;
  }
};
