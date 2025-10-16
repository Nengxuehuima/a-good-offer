#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int countIslands(vector<string> &grid) {
    int m = (int)grid.size();
    if (m == 0) return 0;
    int n = (int)grid[0].size();
    int ans = 0;
    const int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '1') {
                ++ans;
                queue<pair<int,int>> q;
                q.push({i, j});
                grid[i][j] = '0';
                while (!q.empty()) {
                    auto [r, c] = q.front(); q.pop();
                    for (auto &d : dirs) {
                        int nr = r + d[0], nc = c + d[1];
                        if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == '1') {
                            grid[nr][nc] = '0';
                            q.push({nr, nc});
                        }
                    }
                }
            }
        }
    }
    return ans;
}

//加入main()函数之后，为ACM模式，只有类的封装为力扣模式
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    // 多组测试直到 EOF
    while ( (cin >> m >> n) ) {
        vector<string> grid(m);
        // 读取每一行；若存在空格或额外符号（如 ' , [ ]），会自动忽略非 0/1 字符
        for (int i = 0; i < m; ++i) {
            string row, tok;
            // 累积到长度为 n
            while ((int)row.size() < n && (cin >> tok)) {
                for (char ch : tok) if (ch == '0' || ch == '1') row.push_back(ch);
                if ((int)row.size() >= n) break;
            }
            if ((int)row.size() != n) {
                // 若输入不规范，可在此处处理错误；这里简单截断/填充
                row.resize(n, '0');
            }
            grid[i] = row;
        }
        cout << countIslands(grid) << "\n";
    }
    return 0;
}


面试回答
我把网格抽象成无向图：每个 '1' 是顶点，四方向相邻则有边。题目要的是连通分量个数。
我用 BFS（广度优先搜索）/DFS（深度优先搜索） 做 Flood Fill（泛洪）：每遇到一个未访问的 '1'，答案 +1，并把这整块相连的 '1' 全部遍历并标记为已访问（或原地改为 '0'）。
这样每块只数一次，复杂度 O(mn)，空间为队列/栈的大小。若担心递归栈溢出，我用 BFS 或显式栈的 DFS。若不准改输入，就用 visited 数组。

Flood Fill（泛洪/填充）就是：
从一个起点格子出发，把所有与它连通、且满足同一条件（比如都是 '1'）的格子一股脑儿“淹掉/染色/标记”。
用 BFS/DFS 做 Flood Fill”，意思是：
用 BFS（队列，层层扩散）或 DFS（递归/栈，一路走到底再回溯）作为遍历方式，把起点那一整片连通区域全部访问并标记。
